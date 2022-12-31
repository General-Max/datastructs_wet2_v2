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
     * @return the number of players in the team
     */
    int getNumOfPlayers() const;

    /**
     * @return the sum of the goals of all teh players in this team
     */
    int getTotalPlayersAbility() const;

    /**
     * return the number of cards the the all the players in the team have
     * @return
     */
    int getTotalCards() const;

    /**
     * set a new new total players ability of the team
     * @param newTotalPlayersAbility
     */
    void setTotalPlayersAbility(int newTotalPlayersAbility);

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
     * insert a new player to the team and updates the params of the fields
     * @param player a new player
     */
     void insertPlayer(const shared_ptr<Player>& player);


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

    /**
     *
     * @return true if the team is still in the game (wasn't bought or removed)
     */
    bool getIsInGame() const;

    /**
     * change the participation status of the team
     * @param isInGame
     */
    void setIsInGame(bool isInGame);

    /**
     * sets new points to the team
     * @param newPoints
     */
    void setPoints(int newPoints);

    /**
     * sets new goals keepers amount
     */
    void setGoalsKeepers(int newGoalsKeepers);

    /**
     * sets the number of the players in the team
     * @param newNumOfPlayers
     */
    void setNumOfPlayers(int newNumOfPlayers);

    /**
     * sets a new total cards of the team
     * @param newTotalCards
     */
    void setTotalCards(int newTotalCards);

    void updateAfterBuying(shared_ptr<Team> boughtTeam);
   /* shared_ptr<PLayer> getNewestPlayer() const;

    void setNewestPlayer(shared_ptr<Player>& newPlayer);*/
private:
    int m_teamId;
    int m_points;
    int m_numOfPlayers;
    int m_totalPlayersAbility;
    int m_totalCards;
    int m_goalkeepers;
    Node* m_rootInTree;
    permutation_t m_teamSpirit;
    bool m_isInGame;
  //  shared_ptr<Player> m_newestPlayer;
};

#endif //WET2_TEAM_H
