#ifndef WET2_V2_SORTTEAMBYID_H
#define WET2_V2_SORTTEAMBYID_H

#include <memory>
#include "Team.h"

class SortTeamById {
public:
    SortTeamById() = default;

    ~SortTeamById() = default;

    static bool equalTo(shared_ptr<Team> team1, int teamId1);

    static bool lessThan(shared_ptr<Team> team1, int teamId1);

    static bool equalTo(shared_ptr<Team> team1, shared_ptr<Team> team2);

    static bool lessThan(shared_ptr<Team> team1, shared_ptr<Team> team2);
};

#endif //WET2_V2_SORTTEAMBYID_H
