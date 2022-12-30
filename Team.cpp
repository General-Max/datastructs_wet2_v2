

#include "Team.h"

Team::Team(int teamId) : m_teamId(teamId), m_points(0), m_numOfPlayers(0), m_totalPlayersAbility(0),
                         m_totalCards(0), m_goalkeepers(0), m_rootInTree(nullptr),
                         m_teamSpirit(permutation_t::neutral()), m_isInGame(true){ }

int Team::getTeamId() const {
    return m_teamId;
}

int Team::getPoints() const {
    return m_points;
}

int Team::getNumOfPlayers() const {
    return m_numOfPlayers;
}

int Team::getTotalPlayersAbility() const {
    return m_totalPlayersAbility;
}

int Team::getScore() const {
    return (m_points + m_totalPlayersAbility);
}

int Team::getGoalkeepers() const {
    return m_goalkeepers;
}

bool Team::isEmptyTeam() const {
    return m_numOfPlayers == 0;
}

void Team::updatePoints(int points) {
    m_points += points;
}

ostream &operator<<(ostream &os, const Team &team) {
    os << "team id: " <<  team.getTeamId() << ", score: " << team.getScore();
    return os;
}

Node *Team::getRootInTree() const {
    return m_rootInTree;
}

void Team::setRootInTree(Node *newRoot) {
    m_rootInTree = newRoot;
}

permutation_t Team::getTeamSpirit() const {
    return m_teamSpirit;
}

void Team::setTeamSpirit(permutation_t newTeamSpirit)
{
    m_teamSpirit = newTeamSpirit;
}

bool Team::getIsInGame() const {
    return this->m_isInGame;
}

void Team::setIsInGame(bool isInGame) {
    this->m_isInGame = isInGame;
}
//
//shared_ptr<Player> Team::getNewestPlayer() const {
//    return this->m_newestPlayer;
//}
//
//void Team::setNewestPlayer(shared_ptr<Player>& newPlayer) {
//    this->m_newestPlayer = newPlayer;
//}

void Team::insertPlayer(const shared_ptr<Player> &player) {
    m_numOfPlayers++;
    m_totalCards+=player->getCards();
    if(player->getGoalKeeper()){
        m_goalkeepers++;
    }
    m_totalPlayersAbility += player->getAbility();
    m_teamSpirit = m_teamSpirit*(player->getSpirit());
}

















