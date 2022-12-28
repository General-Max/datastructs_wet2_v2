//

#include <iostream>
//#include "DynamicArray.h"
//#include "AVLRankTree.h"
//#include "sortRegular.h"
//#include "LinkedList.h"
#include "HashMap.h"
#include "Player.h"
#include "Team.h"
#include "UnionFind.h"

using std::cout;
using std::endl;

const int SIZE = 100000;

//functions
void testHashInsert(HashMap* h);
void testHashFind(HashMap* h);
void testHashOccupancy(HashMap* h);
void testHashMap();
void testUnionFind();
void testUFInsert(UnionFind* u);


int main()
{

    testHashMap();

    testUnionFind();

/*
    cout << "----------------TEST5----------------" << endl;
    AVLTree<int, SortRegular> tree = AVLTree<int, SortRegular>();
    tree.insert(5);
    for(int i=0;i<9;i++){
        tree.insert(i);
    }
    for(int i=20;i>10;i--){
        tree.insert(i);
    }
    tree.printD(tree.getRoot(), 10);
    tree.printH(tree.getRoot(), 10);
*/

    return 0;
}

void testHashInsert(HashMap* h){
    cout << "--------------------------insertion test--------------------------" << endl;
    bool insertTest = true;
    permutation_t per= permutation_t();
    try{
        for(int i=1;i<SIZE;i++){
            shared_ptr<Team> t1 = std::make_shared<Team>(i);
            shared_ptr<Player> p1 = std::make_shared<Player>(i,1, per,1,1,1,false);
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

void testHashFind(HashMap* h){
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

void testHashOccupancy(HashMap* h){
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

void testHashMap(){

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

void testUnionFind(){

    cout << "--------------------------------------\n";
    cout << "-----------UnionFind test-------------\n";
    cout << "--------------------------------------\n";

    UnionFind* group = new UnionFind();

    testUFInsert(group);

    delete group;
}

void testUFInsert(UnionFind* u){
    permutation_t per= permutation_t();

    shared_ptr<Team> t1 = std::make_shared<Team>(1);
    shared_ptr<Player> p1 = std::make_shared<Player>(1,1, per,1,1,1,false);

    u->makeSet(p1,t1);
}