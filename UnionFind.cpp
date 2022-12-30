#include "UnionFind.h"

UnionFind::UnionFind() : allPlayers(HashMap()) {}

void UnionFind::makeSet(shared_ptr<Player> player, shared_ptr<Team> team)
{
    allPlayers.insertElement(player, team);
}

void UnionFind::unionTeams(shared_ptr<Team> boughtTeam, shared_ptr<Team> buyerTeam)
{
    Node* boughtTeamRoot = boughtTeam->getRootInTree();
    Node* buyerTeamRoot = buyerTeam->getRootInTree();
    permutation_t newSpirit;
    if(boughtTeam->getNumOfPlayers() <= buyerTeam->getNumOfPlayers())
    {
        boughtTeamRoot->setParent(buyerTeamRoot);
        boughtTeamRoot->setTeam(nullptr);
        newSpirit = (((buyerTeamRoot->getPlayer())->getSpirit()).inv())*
                (buyerTeamRoot->getTeam()->getTeamSpirit())
                *((boughtTeamRoot->getPlayer())->getSpirit());
        boughtTeamRoot->getPlayer()->setSpirit(newSpirit);
        boughtTeamRoot->getPlayer()->updateGamesPlayed((-1)*buyerTeamRoot->getPlayer()->getGamesPlayed());
    }

    else
    {
        buyerTeamRoot->setParent(boughtTeamRoot);
        boughtTeamRoot->setTeam(buyerTeamRoot->getTeam());
        buyerTeamRoot->setTeam(nullptr);
        newSpirit = (((buyerTeamRoot->getTeam()->getTeamSpirit())) *
                ((boughtTeamRoot->getPlayer())->getSpirit()));
        (boughtTeamRoot->getPlayer())->setSpirit(newSpirit);
        newSpirit = (((boughtTeamRoot->getTeam())->getTeamSpirit()).inv()) *
                ((buyerTeamRoot->getPlayer())->getSpirit());
        (buyerTeamRoot->getPlayer())->setSpirit(newSpirit);
        (buyerTeamRoot->getPlayer())->updateGamesPlayed((-1)*boughtTeamRoot->getPlayer()->getGamesPlayed());
    }
}

shared_ptr<Player> UnionFind::findPlayer(int playerId) {
    return (allPlayers.findElement(playerId))->getPlayer();
}

shared_ptr<Team> UnionFind::findPlayerTeam(int playerId) {
    Node* playerNode = allPlayers.findElement(playerId);
    Node* tempNode = playerNode;
    permutation_t totalSpirit = permutation_t::neutral();
    int totalGamesPlayed = 0;
    while(!tempNode->getIsRoot()){
        totalSpirit = (tempNode->getPlayer())->getSpirit() * totalSpirit;
        totalGamesPlayed += (tempNode->getPlayer())->getGamesPlayed();
        tempNode=tempNode->getParent();
    }
    playerNode->setParent(tempNode);
    playerNode->getPlayer()->setSpirit((((tempNode->getPlayer())->getSpirit()).inv())*totalSpirit);
    int newParentGamesPlayed = (tempNode->getPlayer())->getGamesPlayed();
    playerNode->getPlayer()->setGamedPlayed(totalGamesPlayed-newParentGamesPlayed);
    return tempNode->getTeam();
}

void UnionFind::addPlayerToTeam(shared_ptr<Player> player, shared_ptr<Team> team) {
    Node* playerNode = allPlayers.findElement(player->getPlayerId());

    // in case it is the first player in the team, we should only update its fields
    if(team->getNumOfPlayers() != 0){
        Node* teamRoot = team->getRootInTree();
        playerNode->setParent(teamRoot);
        permutation_t newSpirit = ((((playerNode->getParent())->getPlayer())->getSpirit()).inv()) *
                                  (team->getTeamSpirit()) * (player->getSpirit());
        int newGamesPlayed = (player->getGamesPlayed()) - (((playerNode->getParent())->getPlayer())->getGamesPlayed());
        player->setSpirit(newSpirit);
        player->setGamedPlayed(newGamesPlayed);
    }
}

