#include "Node.hpp"     //"" means import local file

//Constructor
Node::Node(int payload)   //class::constructor
{
    //'this' is a Node*
    this->payload = payload;                               
}

int Node::getPayload()
{
    return this->payload;
}

Node* Node::getPrevNode() //returns the address of a node
{
    return this->prevNode;
}

void Node::setPrevNode(Node* n)
{
    this->prevNode = n;
}

Node* Node::getNextNode() //returns the address of a node
{
    return this->nextNode;
}

void Node::setNextNode(Node* n)
{
    this->nextNode = n;
}