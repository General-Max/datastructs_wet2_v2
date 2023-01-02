
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
    Node* toDelete;
    Node* temp;
    for(int i=0;i <m_size; i++){
        toDelete = m_data[i];
        while(toDelete!= nullptr){
            temp = toDelete->getNext();
            delete toDelete;
            toDelete = temp;
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
    m_occupancy++;
    Node* newNode = new Node(player);

    // in case it is the root of the inverse tree
    if((playerTeam->getNumOfPlayers())==0){
       // shared_ptr<Team> newTeam = std::make_shared<Team>(playerTeam->getTeamId());
        newNode->getPlayer()->setTeam(playerTeam);
        playerTeam->setRootInTree(newNode);
    }
    int index = HashFunction(key);
    if(m_data[index] != nullptr){
        newNode->setNext(m_data[index]);
    }

    m_data[index] = newNode;
}

void HashMap::insertNode(Node* node)
{
    int key = (node->getPlayer())->getPlayerId();
    m_occupancy++;

  //  shared_ptr<Player> newPlayer = std::make_shared<Player>((node->getPlayer())->getPlayerId(),(node->getPlayer())->getSpirit(),
    //                                                        (node->getPlayer())->getGamesPlayed(), (node->getPlayer())->getAbility(),
      //                                              (node->getPlayer())->getCards(), (node->getPlayer())etGoalKeeper());
    Node* newNode = new Node(node->getPlayer());
    if(node->getIsRoot()){
        ((node->getPlayer())->getTeam())->setRootInTree(newNode);
    }
    int index = HashFunction(key);
    if(m_data[index] != nullptr){
        newNode->setNext(m_data[index]);
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
            insertNode(temp);
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
