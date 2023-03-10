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
    // in case there are players in both teams
    if(boughtTeamRoot!= nullptr && buyerTeamRoot!= nullptr){
        if(boughtTeam->getNumOfPlayers() <= buyerTeam->getNumOfPlayers())
        {
            newSpirit = (((buyerTeamRoot->getPlayer())->getSpirit()).inv())*
                        (buyerTeam->getTeamSpirit())
                        *((boughtTeamRoot->getPlayer())->getSpirit());
            ( boughtTeamRoot->getPlayer())->setSpirit(newSpirit);
            (boughtTeamRoot->getPlayer())->setParent(buyerTeamRoot->getPlayer());
            if(boughtTeam!=buyerTeam){
                boughtTeam->setRootInTree(nullptr);
            }
            (boughtTeamRoot->getPlayer())->setTeam(nullptr);
            boughtTeamRoot->getPlayer()->updateGamesPlayed((-1)*((buyerTeamRoot->getPlayer())->getGamesPlayed()));
        }

        else
        {
            (buyerTeamRoot->getPlayer())->updateGamesPlayed((-1)*(boughtTeamRoot->getPlayer()->getGamesPlayed()));
           newSpirit = ((buyerTeam->getTeamSpirit())) *
                         ((boughtTeamRoot->getPlayer())->getSpirit());
           (boughtTeamRoot->getPlayer())->setSpirit(newSpirit);
           newSpirit = (((boughtTeamRoot->getPlayer())->getSpirit()).inv()) *
                        ((buyerTeamRoot->getPlayer())->getSpirit());
           (buyerTeamRoot->getPlayer())->setSpirit(newSpirit);
            (buyerTeamRoot->getPlayer())->setParent(boughtTeamRoot->getPlayer());

            buyerTeam->setRootInTree(boughtTeamRoot);
            boughtTeam->setRootInTree(nullptr);
            (boughtTeamRoot->getPlayer())->setTeam(buyerTeam);
            (buyerTeamRoot->getPlayer())->setTeam(nullptr);
        }
    }
    
    else if(boughtTeamRoot!= nullptr){
        buyerTeam->setRootInTree(boughtTeamRoot);
        (boughtTeamRoot->getPlayer())->setTeam(buyerTeam);
        boughtTeam->setRootInTree(nullptr);
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
    permutation_t totalSpirit = permutation_t::neutral();
    int totalGamesPlayed = 0;
    shared_ptr<Player> tempPlayer = playerNode->getPlayer();

    // while the player is not the root of the tree
    while((tempPlayer->getTeam()) == nullptr){
        totalSpirit = (tempPlayer->getSpirit()) * totalSpirit;
        totalGamesPlayed += tempPlayer->getGamesPlayed();
        tempPlayer = tempPlayer->getParent();
    }
    totalSpirit = (tempPlayer->getSpirit()) * totalSpirit;
    totalGamesPlayed += tempPlayer->getGamesPlayed();
    shared_ptr<Player> player = playerNode->getPlayer();
    shared_ptr<Player> parent;
    permutation_t oldSpirit;
    int oldGamesPlayed;
    while(player != nullptr && (player->getParent())!= nullptr){
        parent = player->getParent();
        oldSpirit = player->getSpirit();
        oldGamesPlayed = player->getGamesPlayed();
        player->setParent(tempPlayer);
        player->setSpirit(((tempPlayer->getSpirit()).inv()) * totalSpirit);
        int newParentGamesPlayed = tempPlayer->getGamesPlayed();
        player->setGamedPlayed(totalGamesPlayed - newParentGamesPlayed);

        totalSpirit = totalSpirit * oldSpirit.inv();
        totalGamesPlayed -= oldGamesPlayed;

        player = parent;
    }

    return tempPlayer->getTeam();
}

void UnionFind::addPlayerToTeam(shared_ptr<Player> player, shared_ptr<Team> team) {

    // in case it is the first player in the team, we should only update its fields
    if(team->getNumOfPlayers() != 0){
        Node* teamRoot = team->getRootInTree();
        player->setParent(teamRoot->getPlayer());
        permutation_t newSpirit = (((player->getParent())->getSpirit()).inv()) *
                                  (team->getTeamSpirit()) * (player->getSpirit());
        int newGamesPlayed = (player->getGamesPlayed()) - ((player->getParent())->getGamesPlayed());
        player->setSpirit(newSpirit);
        player->setGamedPlayed(newGamesPlayed);
    }
}





