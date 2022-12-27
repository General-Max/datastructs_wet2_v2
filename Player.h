#ifndef EX1_Player_H
#define EX1_Player_H

#include <ostream>
#include <memory>
#include "wet2util.h"

using std::ostream;
using std::shared_ptr;

class Player{
public:
   /**
    * Constructor of Player, created a new player with the given values:
    * @param playerId
    * @param teamId
    * @param spirit
    * @param gamesPlayed
    * @param ability
    * @param cards
    * @param goalkeeper
    */
   Player(int playerId, int teamId, const permutation_t& spirit, int gamesPlayed, int ability, int cards, bool goalkeeper);

    /**
     * destructor of player
     */
    ~Player() = default;

    /**
     * @return the id of the player
     */
    int getPlayerId() const;

    /**
     * @return the id of the team that the player belongs to
     */
    int getTeamId() const;

    /**
     * @return the number of games the player has played
     */
    int getGamesPlayed() const;

    /**
     * @return the number of cards that the player received
     */
    int getCards() const;

    /**
     * @return true if the player can be a goal keeper, else false
     */
    bool getGoalKeeper() const;

    /**
     * prints this player details
     * @param os
     * @param player
     * @return
     */
    friend ostream& operator<<(ostream& os, const Player& player);

    /**
     * add the new games number to the current one
     * @param newGamedNumber
     */
    void updateGamesPlayed(int newGamedNumber);

    /**
     * add the new games number to the current one
     * @param newCardsNumber
     */
    void updateCards (int newCardsNumber);

    /**
     * determine if the player can be a goal keeper or not
     * @param isGoalKeeper
     */
    void setGoalKeeper(bool isGoalKeeper);

    /**
     *
     * @return the spirit of the player
     */
    permutation_t getSpirit();

    /**
     * update the spirit of the player
     * @param newSpirit
     */
    void setSpirit(permutation_t newSpirit);

private:
    int m_playerId;
    int m_teamId;
    permutation_t m_spirit;
    int m_gamesPlayed;
    int m_ability;
    int m_cards;
    bool m_goalKeeper;
};

#endif //WET2_PLAYER_H
