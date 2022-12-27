#include "Node.h"

Node::Node() : m_player(nullptr), m_next(nullptr), m_parent(nullptr), m_team(nullptr) {}

Node::Node(shared_ptr<Player> player) : m_player(player), m_next(nullptr), m_parent(nullptr),
m_team(nullptr) {}

Node::~Node()
{
    delete m_next;
}

Node& Node::operator=(Node &other)
{
    if(this == &other){
        return *this;
    }
    this->m_player=other.m_player;
    this->m_next=other.m_next;
    this->m_team = other.m_team;
    this->m_parent=other.m_parent;
    //this->m_buyingTeamSpirit = other.m_buyingTeamSpirit;
}

//getters and setters
shared_ptr<Player> Node::getPlayer() const
{
    return this->m_player;
}

void Node::setPlayer(shared_ptr<Player> p)
{
    this->m_player = p;
}

Node* Node::getNext() const
{
    return this->m_next;
}
void Node::setNext(Node* next)
{
    this->m_next=next;
}

shared_ptr<Team> Node::getTeam() const
{
    return this->m_team;
}

void Node::setTeam(shared_ptr<Team> team)
{
    this->m_team = team;
}

bool Node::getIsRoot() const
{
    return this->m_team != nullptr;
}

//permutation_t Node::getBuyingTeamSpirit() const
//{
//    return this->m_buyingTeamSpirit;
//}
//void Node::setBuyingTeamSpirit(permutation_t other)
//{
//    this->m_buyingTeamSpirit=other;
//}

Node *Node::getParent() const {
    return m_parent;
}

void Node::setParent(Node *parent) {
    m_parent = parent;
}
