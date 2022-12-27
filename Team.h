#ifndef WET2_TEAM_H
#define WET2_TEAM_H

#include <ostream>
#include "Node.h"
using std::ostream;
class Node;

class Team{
public:
    /**
     * Constructor of Team
     * @param teamId
     * @param points
     */
    Team(int teamId);

    /**
     * Destructor of team, destroy the team's players trees
     */
    ~Team() = default;

    /**
     * @return teh is of the team
     */
    int getTeamId() const;

    /**
     * @return the points of the team
     */
    int getPoints() const;

    /**
     * @return the nu,ber of games that the players of the team has played together
     */
    int getPlayedTogether() const;

    /**
     * @return the number of players in the team
     */
    int getNumOfPlayers() const;

    /**
     * @return the sum of the goals of all teh players in this team
     */
    int getTotalPlayersAbility() const;

    /**
     * @return the team's score, computed by:
     * the points plus the sum of abilities of all the players
     */
    int getScore() const;

    /**
     * @return the number of goalkeepers in the team
     */
    int getGoalkeepers() const;

    /**
     * @return the node of the team's root in the inverse tree
     */
    Node* getRootInTree() const;

    /**
     * set the root of the inverse tree
     * @param newRoot
     */
    void setRootInTree(Node* newRoot);

    /**
     * @return the spirit of the team (spirit of all the players in it)
     */
    permutation_t getTeamSpirit() const;

    /**
     * set a new spirit to the team
     * @param newTeamSpirit
     */
    void setTeamSpirit(permutation_t newTeamSpirit);

    /**
     * increase the number of games that the players played together by one
     */
    void increasePlayedTogether();

    /**
     * insert a new player to the team and updates the params of the fields
     * @param player a new player
     */
    // void insertPlayer(const shared_ptr<Player>& player);

    /**
     * remove a player from the team and updates the values of the fields
     * @param player
     */
    //void removePLayer(shared_ptr<Player> player);

    /**
     * @return if there aren't any players in the team
     */
    bool isEmptyTeam() const;

    /**
     * Adds the given points to the total points of the team
     * @param points
     */
    void updatePoints(int points);

    /**
     * print operator for the team fields
     * @param os
     * @param team
     * @return
     */
    friend ostream& operator<<(ostream& os, const Team& team);

private:
    int m_teamId;
    int m_points;
    int m_playedTogether;
    int m_numOfPlayers;
    int m_totalPlayersAbility;
    int m_totalCards;
    int m_goalkeepers;
    Node* m_rootInTree;
    permutation_t m_teamSpirit;
};

#endif //WET2_TEAM_H
