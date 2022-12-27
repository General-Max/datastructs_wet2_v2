
#include "HashMap.h"

HashMap::HashMap() : m_data(new Node*[INITIAL_SIZE]), m_size(INITIAL_SIZE), m_occupancy(0)
{
    for(int i=0; i<INITIAL_SIZE; i++){
        m_data[i] = nullptr;
    }
}

int HashMap::HashFunction(int key) const
{
    double fracPart = COEFFICIENT*key -(int)(COEFFICIENT*key);
    int floored = (int)(fracPart*m_size);
    return floored;
}

HashMap::~HashMap()
{
    for (int i=0; i<m_size; i++){
        if(m_data[i]!=nullptr){
            delete m_data[i];
        }
    }

    delete[] m_data;
}

int HashMap::getSize() const
{
    return m_size;
}

int HashMap::getOccupancy() const
{
    return m_occupancy;
}

void HashMap::insertElement(shared_ptr<Player> player, std::shared_ptr<Team> playerTeam)
{
    if(m_occupancy==m_size-1){
        std::cout << "expanding" << std::endl;
        expand();
    }
    int key = player->getPlayerId();

    Node* newNode = new Node(player);

    // in case it is the root of the inverse tree
    if((playerTeam->getNumOfPlayers())==0){
        newNode->setTeam(playerTeam);
    }
    int index = HashFunction(key);
    if(m_data[index] != nullptr){
        newNode->setNext(m_data[index]);
    }
    else{
        m_occupancy++;
    }
    m_data[index] = newNode;
}
void HashMap::expand()
{
    int oldSize = m_size;
    Node** newDataArray = new Node*[oldSize*RATE];
    for(int i=0;i<oldSize*RATE;i++){
        newDataArray[i] = nullptr;
    }
    Node* temp;
    Node** oldArray = m_data;
    m_data = newDataArray;
    m_size*=RATE;
    m_occupancy=0;
    for(int i=0;i<oldSize;i++){
        temp = oldArray[i];
        while(temp!= nullptr){
            insertElement(temp->getPlayer(), temp->getTeam());
            temp = temp->getNext();
        }
    }

    Node* toDelete;
    for(int i=0;i <oldSize; i++){
        toDelete = oldArray[i];
        while(toDelete!= nullptr){
            temp = toDelete->getNext();
            delete toDelete;
            toDelete = temp;
        }
    }
    delete[] oldArray;

 }

Node* HashMap::findElement(int playerId) const
{
    int index = HashFunction(playerId);
    Node* temp = m_data[index];
    while(temp!= nullptr){
        if(temp->getPlayer()->getPlayerId() == playerId){
            return temp;
        }
        temp = temp->getNext();
    }
    return nullptr;
}

void HashMap::printHash()
{
    Node* temp;
    for(int i=0;i<m_size;i++){
        temp = m_data[i];
        std::cout << "["<<i<<"]: ";
        while(temp!= nullptr){
            std::cout << "player: " << temp->getPlayer()->getPlayerId() << "->";
            temp = temp->getNext();
        }
        std::cout << "||" << std::endl;
        //std::cout << "end position " << i << " in the array" << std::endl;
    }
}
