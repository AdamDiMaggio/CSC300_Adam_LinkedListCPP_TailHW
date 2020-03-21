#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList()    //implement LinkedList constructor
{
    this->count = 0;    //set count to zero since we don't have any nodes yet
}

void LinkedList::addFront(int payload)  //implement addFront method
{
    Node* n = new Node(payload);    //new node object(Node n = new Node(payload) in Java),n points to the new node    
    
    //list currently has nothing in it
    if(!this->head) //if head currently points nowhere(count is zero)
    {
        this->head = n; //set head to the new node's address
        this->tail = n;
    }
    else//list has something in it(count is not zero)
    {
        n->setNextNode(this->head); //n.setNextNode(address in head), this way we won't lose the way to that node
        this->head->setPrevNode(n); //the previous head now points back at new node
        this->head = n; //set head to hold new node's mem. address
    }
    this->count++;
}

int LinkedList::getFront()
{
    return this->head->getPayload(); 
}

int LinkedList::removeFront()
{
    Node* nodeToReturn = this->head;    //locate the node at the front of the list
    this->head = this->head->getNextNode(); //set head to the front's nextNode
    this->head->setPrevNode(0);
    int val = nodeToReturn->getPayload(); //save the payload of the first node
    delete nodeToReturn;    //free up the memory space we were using
    this->count--;
    return val; //output the payload value we saved
}

Node* LinkedList::findEnd()
{
    return this->tail;
    /*Node* currNode = this->head;
    for(int i = 1; i < this->count; i++)
    {
        currNode = currNode->getNextNode();
    }
    return currNode;*/
}

void LinkedList::addEnd(int payload)   //add node to the end of the list
{
    
    if(!this->head) //if head points to nothing
    {
        this->addFront(payload);
    }
    else
    {
        Node* n = new Node(payload);
        this->tail->setNextNode(n);
        n->setPrevNode(tail);
        this->tail = n;
        this->count++;
    /*Node* n = new Node(payload);
    Node* currNode = this->findEnd();
    currNode->setNextNode(n);
    n->setPrevNode(currNode);
    this->count++;*/
    }
    
}

int LinkedList::getEnd()
{
    return this->tail->getPayload();
    /*Node* currNode = this->findEnd();
    return currNode->getPayload();*/
}

int LinkedList::removeEnd()
{
    int val = this->tail->getPayload();
    this->tail = this->tail->getPrevNode();
    this->tail->setNextNode(0);
    this->count--;
    return val;
    /*Node* nodeToReturn = this->findEnd();
    int val = nodeToReturn->getPayload();
    delete nodeToReturn;
    this->count--;
    this->findEnd()->setNextNode(0);
    return val;*/
}

int LinkedList::getIndex(int index)
{
    if(index == 0)
    {
        return this->head->getPayload();
    }
    else if(index > 0 && index <= this->count- 2)
    {
        Node* currNode = this->head;
        for(int i = 0; i < index; i++)
        {
            currNode = currNode->getNextNode();
        }
        return currNode->getPayload();
    }
    else
    {
        return this->tail->getPayload();
    }
    
}

void LinkedList::addAtIndex(int index, int payload)
{
    if(index == 0)
    {
        this->addFront(payload);
    }
    else
    {
        if(index>= this->count)
        {
            this->addEnd(payload);
        }
        else
        {
        Node* currNode = this->head;
        for(int i = 0; i < (index-1); i++)
        {
            currNode = currNode->getNextNode();
        }
        Node* n = new Node(payload);
        n->setNextNode(currNode->getNextNode());
        currNode->setNextNode(n);
        this->count++;
        }

    }
}

int LinkedList::removeAtIndex(int index)
{
    if(index==0)
    {
        this->removeFront();
    }
    else
    {
        if(index >= this->count - 1)
        {
            this->removeEnd();
        }
        else
        {
            Node* nodeBefore = this->head;
            for(int i = 1; i < index; i++)
            {
                nodeBefore = nodeBefore->getNextNode();
            }
            Node* nodeToRemove = nodeBefore->getNextNode();
            nodeBefore->setNextNode(nodeToRemove->getNextNode());
            nodeToRemove->setNextNode(0);
            int val = nodeToRemove->getPayload();
            delete nodeToRemove;
            this->count--;
            return val;
        }
    }
}

void LinkedList::sort()
{
    if(this->count > 1)
    {
        for(int currPos = 1; currPos < this->count;currPos++)
        {
            this->display();
            int followPos = currPos;
            Node* follower = this->findIndex(followPos); 
            
            while(!(follower == this->head))
            {
                Node* temp = findIndex(followPos-1);
                if(follower->getPayload() < temp->getPayload())
                {
                    //The Swap                    
                    temp->setNextNode(follower->getNextNode());
                    follower->setNextNode(temp);
                    if(followPos == 1)
                    {
                        this->head = follower;
                    }
                    else
                    {
                        this->findIndex(followPos -2)->setNextNode(follower);    
                    }
                }
                else
                {
                    break;
                }
                followPos--;
            }
        }
        this->display();
    }
}

Node* LinkedList::findIndex(int index)
{
    Node* currNode = this->head;
    if(index==0)
    {
        return this->head;
    }
    else
    {
        for(int i = 0; i < index; i++)
        {
            currNode = currNode->getNextNode();
        }
        return currNode;
    }
}



    
void LinkedList::display()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        std::cout << currNode->getPayload() << "\n";
        currNode = currNode->getNextNode();
    }
    std::cout<< "Count = " << this->count <<"\n"<<"**********"<<"\n";
}

void LinkedList::displayPointers()
{
    Node* currNode = this->head;
    for(int i = 0; i < this->count; i++)
    {
        std::cout << currNode << "\n";
        currNode = currNode->getNextNode();
    }
}