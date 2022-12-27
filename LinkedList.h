
#ifndef WET2_LINKEDLIST_H
#define WET2_LINKEDLIST_H

#include <iostream>

template<class T>
class LinkedList{
public:
    struct ListNode{
        ListNode *m_next;
        T m_nodeData;
    };

    // Node Functions
    ListNode *initNode(T data);

    // Two-Way List Functions
    // constructor
    LinkedList();

    //  destructor
    ~LinkedList();

    void add(T val);

    /**
     * prints the list
     */
    void printList();

    bool isEmpty() const;

    void pop();

    T& getElement() const; //check

private:
    ListNode* m_first;
    ListNode* m_last;

};

template <class T>
LinkedList<T>::LinkedList() : m_first(nullptr), m_last(nullptr) {}

template<class T>
typename LinkedList<T>::ListNode *LinkedList<T>::initNode(T data) {
    ListNode* node = new ListNode();
    node->m_next =nullptr;
    node->m_nodeData=data;

    return node;
}

template <class T>
LinkedList<T>::~LinkedList<T>()
{
    ListNode* toDelete = this->m_first;
    ListNode* temp;
    while(toDelete!= nullptr){
        temp = toDelete->m_next;
        delete toDelete;
        toDelete = temp;
    }
}

template<class T>
void LinkedList<T>::printList()
{
    if(this->m_first == nullptr){
        return;
    }
    std::cout << (this->m_first)->m_nodeData <<  "-> ";
    ListNode* temp = (this->m_first)->m_next;
    while(temp != nullptr){
        std::cout << temp->m_nodeData <<  "-> ";
        temp = temp->m_next;
    }
    std::cout << "||" << std::endl;
}

template<class T>
void LinkedList<T>::add(T val)
{
    ListNode* temp;
    try{
        temp = initNode(val);
        if(m_first==nullptr){
            m_first=temp;
            m_last=temp;
        }
        else{
            m_last->m_next=temp;
            m_last=m_last->m_next;
        }
    }
    catch(std::bad_alloc &e){
        throw e;
    }
}

template<class T>
bool LinkedList<T>::isEmpty() const
{
    return (m_first == nullptr);
}

template<class  T>
void LinkedList<T>::pop()
{
    ListNode* toDelete = this->m_first;
    this->m_first = (this->m_first)->m_next;
    delete toDelete;
}

template<class T>
T& LinkedList<T>::getElement() const //check the &
{
    return &(m_first->m_nodeData);
}


#endif //WET2_LINKEDLIST_H
