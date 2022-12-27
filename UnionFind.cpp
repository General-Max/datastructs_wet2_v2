#include "UnionFind.h"

UnionFind::UnionFind() : allPlayers(HashMap()) {}

void UnionFind::makeSet(shared_ptr<Player> player, shared_ptr<Team> team)
{
    allPlayers.insertElement(player, team);
}

void unionTeams(shared_ptr<Team> boughtTeam, shared_ptr<Team> buyerTeam)
{
    Node* boughtTeamRoot = boughtTeam->getRootInTree();
    Node* buyerTeamRoot = buyerTeam->getRootInTree();
    permutation_t newSpirit;
    if(boughtTeam->getNumOfPlayers() <= buyerTeam->getNumOfPlayers())
    {
        boughtTeamRoot->setParent(buyerTeamRoot);
        newSpirit = (((buyerTeamRoot->getPlayer())->getSpirit()).inv())*
                (buyerTeamRoot->getTeam()->getTeamSpirit())
                *((boughtTeamRoot->getPlayer())->getSpirit());
        boughtTeamRoot->getPlayer()->setSpirit(newSpirit);
    }

    else
    {
        buyerTeamRoot->setParent(boughtTeamRoot);
    }
}