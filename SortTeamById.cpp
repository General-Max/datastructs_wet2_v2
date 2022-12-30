#include "SortTeamById.h"

bool SortTeamById::equalTo(shared_ptr<Team> team1, int teamId1)
{
    return team1->getTeamId() == teamId1;
}

bool SortTeamById::lessThan(shared_ptr<Team> team1, int teamId1)
{
    return team1->getTeamId() < teamId1;
}

// return true if they are the same team
// if their ids are equal so those are the same team because the tree contains every time only
// one team with the same id
bool SortTeamById::equalTo(shared_ptr<Team> team1, shared_ptr<Team> team2)
{
    return (team1->getTeamId() == team2->getTeamId());
}

bool SortTeamById::lessThan(shared_ptr<Team> team1, shared_ptr<Team> team2)
{
    return (team1->getTeamId() < team2->getTeamId());
}