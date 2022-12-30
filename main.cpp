//

#include <iostream>
//#include "AVLRankTree.h"
//#include "sortRegular.h"
#include "HashMap.h"
#include "Player.h"
#include "Team.h"
#include "UnionFind.h"

using std::cout;
using std::endl;

const int SIZE = 100000;
const int SIZE_UNION = 4+1;

//functions
void testHashInsert(HashMap* h);
void testHashFind(HashMap* h);
void testHashOccupancy(HashMap* h);
void testHashMap();
void testUnionFind();
void testUFInsert(UnionFind* u);
void testFindPlayerInUnion(UnionFind* u);
void testFindTeamInUnion(UnionFind* u);
void testUniteUnion(UnionFind* u);


int main()
{
    //testHashMap();
    testUnionFind();

    return 0;
}

void testHashInsert(HashMap* h)
{
    cout << "--------------------------insertion test--------------------------" << endl;
    bool insertTest = true;
    permutation_t per= permutation_t();
    try{
        for(int i=1;i<SIZE;i++){
            shared_ptr<Team> t1 = std::make_shared<Team>(i);
            shared_ptr<Player> p1 = std::make_shared<Player>(i, per,1,1,1,false);
            h->insertElement(p1,t1);
        }
    }
    catch(...){
        insertTest = false;
    }

    if(insertTest){
        cout << "insert Test Passed :)" << endl;
    }
    else{
        cout << "insert Test Failed :(" << endl;
    }
}

void testHashFind(HashMap* h)
{
    cout << "--------------------------finding test--------------------------" << endl;
    bool findTest = true;
    for(int i=1;i<SIZE;i++){
        int x = h->findElement(i)->getPlayer()->getPlayerId();
        //cout << "the player " << i;
        if(i == x){
            //cout << " was found" << endl;
        }
        else{
            findTest = false;
            //cout << " was not found" << endl;
        }
        //cout << "want to find player with id: "<< i << " found: " << x << endl;
    }

    if(findTest){
        cout << "find Test Passed :)" << endl;
    }
    else{
        cout << "find Test Failed :(" << endl;
    }
}

void testHashOccupancy(HashMap* h)
{
    cout << "--------------------------size and occupancy test--------------------------" << endl;
    bool sizeAndOccupancyTest = true;
    int hashSize = h->getSize();
    int occupancy = h->getOccupancy();
    cout <<"hash table size: "<< hashSize << " hash table occupancy: " << occupancy << endl;
    double factor = SIZE/hashSize;
    if(factor > 1.5){
        sizeAndOccupancyTest = false;
    }
    if(sizeAndOccupancyTest){
        cout << "size and Occupancy Test Passed :)" << endl;
    }
    else{
        cout << "size and Occupancy Test Failed :(" << endl;
    }
}

void testHashMap()
{

    cout << "------------------------------------\n";
    cout << "-----------HashMap test-------------\n";
    cout << "------------------------------------\n";

    HashMap* h = new HashMap();
    //not double insertion proof

    //insertion test
    testHashInsert(h);

    //find test
    testHashFind(h);

    //occupancy test
    testHashOccupancy(h);

    delete h;

}

void testUnionFind()
{

    cout << "--------------------------------------\n";
    cout << "-----------UnionFind test-------------\n";
    cout << "--------------------------------------\n";

    UnionFind* u = new UnionFind();

    testUFInsert(u);
    testFindPlayerInUnion(u);
//    testFindTeamInUnion(u);
//    testFindTeamInUnion(u);
//    testFindTeamInUnion(u);
//    testFindTeamInUnion(u);
//    testFindTeamInUnion(u);
    testFindPlayerInUnion(u);
    testFindPlayerInUnion(u);
    testFindPlayerInUnion(u);
    testFindPlayerInUnion(u);
    testFindPlayerInUnion(u);
    testFindPlayerInUnion(u);
    testFindPlayerInUnion(u);
    testFindPlayerInUnion(u);
    testFindPlayerInUnion(u);
    testFindPlayerInUnion(u);
    testFindPlayerInUnion(u);
    testFindPlayerInUnion(u);
    testFindPlayerInUnion(u);

    //testUniteUnion(u);

    delete u;
}

void testUFInsert(UnionFind* u)
{
    permutation_t per= permutation_t();

    for(int i=1;i<SIZE_UNION;i++){
        shared_ptr<Team> t1 = std::make_shared<Team>(i);
        shared_ptr<Player> p1 = std::make_shared<Player>(i, per,1,1,1,false);
        u->makeSet(p1,t1);
        u->addPlayerToTeam(p1, t1);
    }

}

//should find all the players later, later not necessarily will find all the teams
void testFindPlayerInUnion(UnionFind* u)
{
    cout << "--------------------------finding Player test--------------------------" << endl;
    bool findTest = true;

    for(int i=1;i<SIZE_UNION;i++){
        int x = u->findPlayer(i)->getPlayerId();
        if(x != i){
            findTest = false;
        }
    }

    if(findTest){
        cout << "find players Test Passed :)" << endl;
    }
    else{
        cout << "find Test Failed :(" << endl;
    }
}

void testFindTeamInUnion(UnionFind* u)
{
    cout << "--------------------------finding Team test--------------------------" << endl;
    bool findTest = true;

    for(int i=1;i<SIZE_UNION;i++){
        int x = u->findPlayerTeam(i)->getTeamId();
        if(x != i){
            findTest = false;
        }
    }

    if(findTest){
        cout << "find team Test Passed :)" << endl;
    }
    else{
        cout << "find Test Failed :(" << endl;
    }
}

void testUniteUnion(UnionFind* u)
{
    cout << "--------------------------finding Team after U test--------------------------" << endl;
    bool findTest = true;

    for(int i=1;i<SIZE_UNION/2;i++){
        shared_ptr<Team> t1 = std::make_shared<Team>(i);
        shared_ptr<Team> t2 = std::make_shared<Team>(i+SIZE_UNION/2);
        u->unionTeams(t1, t2);
    }
/*
    for(int i=1;i<SIZE_UNION/2;i++){
        int x = u->findPlayerTeam(i+SIZE_UNION/2)->getTeamId();
        if(x != i){
            findTest = false;
        }
    }

    if(findTest){
        cout << "find team Test Passed :)" << endl;
    }
    else{
        cout << "find Test Failed :(" << endl;
    }*/
}