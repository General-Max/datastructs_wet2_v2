#include "Player.h"

Player::   Player(int playerId, const permutation_t& spirit, int gamesPlayed, int ability, int cards, bool goalkeeper)
        : m_playerId(playerId),
        m_spirit(spirit), m_gamesPlayed(gamesPlayed),
        m_ability(ability), m_cards(cards),
        m_goalKeeper(goalkeeper){}

int Player::getPlayerId() const {
    return this->m_playerId;
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
    os << "player id: " <<  player.getPlayerId() <<  ", cards: "
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

void Player::setSpirit(const permutation_t& newSpirit) {
    this->m_spirit = newSpirit;
}

void Player::setGamedPlayed(int newTotalGames) {
    this->m_gamesPlayed = newTotalGames;
}

int Player::getAbility() const {
    return this->m_ability;
}

void Player::setPlayerAbility(int newPlayerAbility) {
    this->m_ability = newPlayerAbility;
}

shared_ptr<Team> Player::getTeam() const
{
    return m_team;
}

void Player::setTeam(shared_ptr<Team> team)
{
    m_team = team;
}

shared_ptr<Player> Player::getParent() const
{
    return m_parent;
}

void Player::setParent(shared_ptr<Player> newParent)
{
    m_parent = newParent;
}




