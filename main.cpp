//

#include <iostream>
//#include "DynamicArray.h"
//#include "AVLRankTree.h"
//#include "sortRegular.h"
//#include "LinkedList.h"
#include "HashMap.h"
#include "Player.h"
#include "Team.h"

using std::cout;
using std::endl;

int main()
{
    shared_ptr<Team> t1 = std::make_shared<Team>(1);
    shared_ptr<Team> t2 = std::make_shared<Team>(2);
    shared_ptr<Team> t3 = std::make_shared<Team>(3);
    shared_ptr<Team> t4 = std::make_shared<Team>(4);
    shared_ptr<Team> t5 = std::make_shared<Team>(5);

    permutation_t per= permutation_t();
    shared_ptr<Player> p1 = std::make_shared<Player>(1,1, per,1,1,1,false);
    shared_ptr<Player> p2 = std::make_shared<Player>(2,1, per,1,1,1,false);
    shared_ptr<Player> p3 = std::make_shared<Player>(3,1, per, 1,1,1,false);
    shared_ptr<Player> p4 = std::make_shared<Player>(4,1, per,1,1,1,false);
    shared_ptr<Player> p5 = std::make_shared<Player>(5,1, per,1,1,1,false);


    HashMap h = HashMap();
    h.insertElement(p1,t1);
    h.insertElement(p2,t2);
    h.insertElement(p3,t3);
    h.insertElement(p4,t4);
    h.insertElement(p5,t5);

    h.printHash();

/*
    cout << "Start:" << endl;
    LinkedList<int> list = LinkedList<int>();
    for(int i=0;i<100;i++){
        list.addToList(i);
    }
    list.printList();
    double p=0;
    double x = std::modf(12.333, &p);
    cout << "x: " << x << endl;
*/
    /*Node<int> n = Node<int>(5);
    cout<<n.getData()<<  endl;
    Node<int> temp = n;
    cout<<temp.getData();*/


/*
    DynamicArray<int> dArr = DynamicArray<int>(-1);
    dArr.print();

    cout << "----------------TEST1----------------" << endl;
    dArr.insert(5);
    dArr.print();

    cout << "----------------TEST2----------------" << endl;
    dArr.insert(3);
    dArr.print();

    cout << "----------------TEST3----------------" << endl;
    dArr.insert(5);
    dArr.insert(7);
    dArr.print();

    cout << "----------------TEST4----------------" << endl;
    int num = dArr.getElement(3);
    cout<<num<<endl;

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