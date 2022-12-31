#include "UnionFind.h"

UnionFind::UnionFind() : allPlayers(HashMap()) {}


void UnionFind::makeSet(shared_ptr<Player> player, shared_ptr<Team> team)
{
    allPlayers.insertElement(player, team);
}

void UnionFind::unionTeams(shared_ptr<Team> boughtTeam, shared_ptr<Team> buyerTeam)
{
//    std::cout << boughtTeam.get()->getTeamId() <<std::endl;
//    std::cout << buyerTeam.get()->getTeamId() <<std::endl;

    Node* boughtTeamRoot = boughtTeam->getRootInTree();
    Node* buyerTeamRoot = buyerTeam->getRootInTree();
    permutation_t newSpirit;
    // in case there are players in both teams
    if(boughtTeamRoot!= nullptr && buyerTeamRoot!= nullptr){
        if(boughtTeam->getNumOfPlayers() <= buyerTeam->getNumOfPlayers())
        {
            newSpirit = (((buyerTeamRoot->getPlayer())->getSpirit()).inv())*
                        (buyerTeamRoot->getTeam()->getTeamSpirit())
                        *((boughtTeamRoot->getPlayer())->getSpirit());
            boughtTeamRoot->getPlayer()->setSpirit(newSpirit);
            boughtTeamRoot->getPlayer()->updateGamesPlayed((-1)*((buyerTeamRoot->getPlayer())->getGamesPlayed()));
            boughtTeamRoot->setParent(buyerTeamRoot);
            boughtTeamRoot->setTeam(nullptr);
        }

        else
        {
           newSpirit = (((buyerTeamRoot->getTeam()->getTeamSpirit())) *
                         ((boughtTeamRoot->getPlayer())->getSpirit()));
           (boughtTeamRoot->getPlayer())->setSpirit(newSpirit);
           newSpirit = (((boughtTeamRoot->getPlayer())->getSpirit()).inv()) *
                        ((buyerTeamRoot->getPlayer())->getSpirit());
           (buyerTeamRoot->getPlayer())->setSpirit(newSpirit);
           newSpirit = ((buyerTeamRoot->getTeam())->getTeamSpirit())*((boughtTeamRoot->getTeam())->getTeamSpirit());
           (buyerTeamRoot->getTeam())->setTeamSpirit(newSpirit);
           (buyerTeamRoot->getPlayer())->updateGamesPlayed((-1)*(boughtTeamRoot->getPlayer()->getGamesPlayed()));
           buyerTeamRoot->setParent(boughtTeamRoot);
           boughtTeamRoot->setTeam(buyerTeamRoot->getTeam());
           buyerTeamRoot->setTeam(nullptr);
           buyerTeam->setRootInTree(boughtTeamRoot);
        }
    }
    else if(boughtTeamRoot!= nullptr){
        buyerTeam->setRootInTree(boughtTeamRoot);
        boughtTeamRoot->setTeam(buyerTeam);
    }
}

shared_ptr<Player> UnionFind::findPlayer(int playerId) {
    if(allPlayers.findElement(playerId)!= nullptr){
        return allPlayers.findElement(playerId)->getPlayer();
    }
    return nullptr;
}

shared_ptr<Team> UnionFind::findPlayerTeam(int playerId) {
    Node* playerNode = allPlayers.findElement(playerId);
    if(playerNode == nullptr){
        return nullptr;
    }
    Node* tempNode = playerNode;
    permutation_t totalSpirit = permutation_t::neutral();
    int totalGamesPlayed = 0;
    while(!tempNode->getIsRoot()){
        totalSpirit = (tempNode->getPlayer())->getSpirit() * totalSpirit;
        totalGamesPlayed += (tempNode->getPlayer())->getGamesPlayed();
        tempNode=tempNode->getParent();
    }
    if((tempNode!=playerNode) && (tempNode!=playerNode->getParent())) {
        playerNode->setParent(tempNode);
        playerNode->getPlayer()->setSpirit((((tempNode->getPlayer())->getSpirit()).inv()) * totalSpirit);
        int newParentGamesPlayed = (tempNode->getPlayer())->getGamesPlayed();
        playerNode->getPlayer()->setGamedPlayed(totalGamesPlayed - newParentGamesPlayed);
    }
    shared_ptr<Team> t = tempNode->getTeam();
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

int UnionFind::calculatePlayedGames(int playerId) {
    int gamesPlayed = 0;
    Node* tempNode = allPlayers.findElement(playerId);
    while(tempNode != nullptr){
        gamesPlayed += (tempNode->getPlayer())->getGamesPlayed();
        tempNode = tempNode->getParent();
    }
    return gamesPlayed;
}

permutation_t UnionFind::calculateSpirit(int playerId) {
    permutation_t partialSpirit = permutation_t::neutral();
    Node* tempNode = allPlayers.findElement(playerId);
    while(tempNode != nullptr){
        partialSpirit = (tempNode->getPlayer())->getSpirit()*partialSpirit;
        tempNode = tempNode->getParent();
    }
    return partialSpirit;
}



