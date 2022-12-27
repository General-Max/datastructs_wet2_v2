
#ifndef WET2_NODE_H
#define WET2_NODE_H

#include "Player.h"
#include "Team.h"
#include <memory>
#include "wet2util.h"
class Team;

class Node
{
private:
    shared_ptr<Player> m_player;
    Node* m_next;
    Node* m_parent;
    shared_ptr<Team> m_team;
//    permutation_t m_buyingTeamSpirit;

public:
    Node();
    Node(shared_ptr<Player> other);
    ~Node();
    Node& operator=(Node& other);
    //getters and setters
    shared_ptr<Player> getPlayer() const;
    void setPlayer(shared_ptr<Player> p);

    Node* getNext() const;
    void setNext(Node* next);

    Node* getParent() const;
    void setParent(Node* parent);

    shared_ptr<Team> getTeam() const;
    void setTeam(shared_ptr<Team> team);

    bool getIsRoot() const;

//    permutation_t getBuyingTeamSpirit() const;
//    void setBuyingTeamSpirit(permutation_t other);
};

#endif //WET2_NODE_H
