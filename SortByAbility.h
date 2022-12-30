//
// Created by User on 29/12/2022.
//

#ifndef WET2_V2_SORTBYABILITY_H
#define WET2_V2_SORTBYABILITY_H

#include <memory>
#include "Team.h"

class SortByAbility {
public:
    SortByAbility() = default;
    ~SortByAbility() = default;
    static bool equalTo(shared_ptr<Team> team1, int teamId1);

    static bool lessThan(shared_ptr<Team> team1, int teamId2);

    static bool equalTo(shared_ptr<Team> team1, shared_ptr<Team> team2);

    static bool lessThan(shared_ptr<Team> team1, shared_ptr<Team> team2);
};

#endif //WET2_V2_SORTBYABILITY_H
