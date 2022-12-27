//
// Created by waine on 12/24/2022.
//

#ifndef WET2_HASHMAP_H
#define WET2_HASHMAP_H

#include <iostream>
#include <math.h>
#include "Node.h"
#include <memory>

const int RATE = 2;
const int INITIAL_SIZE = 16;
const double COEFFICIENT = 0.61803;

class HashMap
{
private:
    Node** m_data;
    int m_size;
    int m_occupancy;
    void expand();
    int HashFunction(int key) const;

public:
    HashMap();
    ~HashMap();

    int getSize() const;
    int getOccupancy() const;

    void insertElement(shared_ptr<Player> player, std::shared_ptr<Team> playerTeam);
    Node* findElement(int key) const;
    void printHash();

};

#endif //WET2_HASHMAP_H
