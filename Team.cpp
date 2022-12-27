

#include "Team.h"

Team::Team(int teamId) : m_teamId(teamId), m_points(0), m_playedTogether(0), m_numOfPlayers(0), m_totalPlayersAbility(0),
                         m_totalCards(0), m_goalkeepers(0), m_rootInTree(nullptr), m_teamSpirit(permutation_t()) { }

int Team::getTeamId() const {
    return m_teamId;
}

int Team::getPoints() const {
    return m_points;
}

int Team::getPlayedTogether() const {
    return m_playedTogether;
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

void Team::increasePlayedTogether() {
    m_playedTogether ++;
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















