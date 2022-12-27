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
    }

    else
    {
        buyerTeamRoot->setParent(boughtTeamRoot);
        boughtTeamRoot->setTeam(buyerTeamRoot->getTeam());
        buyerTeamRoot->setTeam(nullptr);
        newSpirit = (((buyerTeamRoot->getTeam()->getTeamSpirit())) *
                ((boughtTeamRoot->getPlayer())->getSpirit()));
        boughtTeamRoot->getPlayer()->setSpirit(newSpirit);
        newSpirit = (((boughtTeamRoot->getTeam())->getTeamSpirit()).inv()) *
                ((buyerTeamRoot->getPlayer())->getSpirit());
        buyerTeamRoot->getPlayer()->setSpirit(newSpirit);
    }
}

shared_ptr<Player> UnionFind::findPlayer(int playerId) {
    return (allPlayers.findElement(playerId))->getPlayer();
}

shared_ptr<Team> UnionFind::findPlayerTeam(int playerId) {
    Node* tempNode = allPlayers.findElement(playerId);
    while(!tempNode->getIsRoot()){
        tempNode=tempNode->getParent();
    }
    return tempNode->getTeam();
}
