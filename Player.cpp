#include "Player.h"

Player::   Player(int playerId, int teamId, const permutation_t& spirit, int gamesPlayed, int ability, int cards, bool goalkeeper)
        : m_playerId(playerId),
        m_teamId(teamId), m_spirit(spirit), m_gamesPlayed(gamesPlayed),
        m_ability(ability), m_cards(cards),
        m_goalKeeper(goalkeeper){}

int Player::getPlayerId() const {
    return this->m_playerId;
}

int Player::getTeamId() const {
    return this->m_teamId;
}

int Player::getGamesPlayed() const {
    return this->m_gamesPlayed;
}

bool Player::getGoalKeeper() const {
    return this->m_goalKeeper;
}

int Player::getCards() const {
    return this->m_cards;
}

ostream& operator<<(ostream& os, const Player& player)
{
    os << "player id: " <<  player.getPlayerId() << ", team: " << player.getTeamId() << ", cards: "
       << player.getCards();
    return os;
}

void Player::updateGamesPlayed(int newGamedNumber) {
    this->m_gamesPlayed += newGamedNumber;
}

void Player::updateCards(int newCardsNumber) {
    this->m_cards += newCardsNumber;
}

void Player::setGoalKeeper(bool isGoalKeeper) {
    this->m_goalKeeper = isGoalKeeper;
}

permutation_t Player::getSpirit(){
    return m_spirit;
}

void Player::setSpirit(permutation_t newSpirit) {
    this->m_spirit = newSpirit;
}
