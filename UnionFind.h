//
// Created by waine on 12/27/2022.
//

#ifndef WET2_UNIONFIND_H
#define WET2_UNIONFIND_H
#include "HashMap.h"

//TODO add getters and setters!!!

class UnionFind{
private:
    HashMap allPlayers;
public:
    UnionFind();
    ~UnionFind() = default;
    void makeSet(shared_ptr<Player> player, shared_ptr<Team> team);
    void unionTeams(shared_ptr<Team> boughtTeam, shared_ptr<Team> buyerTeam);
    shared_ptr<Player> findPlayer();
    shared_ptr<Team> findPlayerTeam();
};
#endif //WET2_UNIONFIND_H
