#include "LinkedList.hpp"
#include <iostream>
#include <ctime>

int main()
{
    /*LinkedList* ll = new  LinkedList();
    ll->addFront(1);
    ll->addFront(2);
    ll->addFront(3);
    ll->addEnd(4);
    ll->addEnd(5);
    ll->display();
    //std::cout << "Tail Node Held: " << ll->removeEnd() << "\n";
    //ll->display();
    std::cout << "Head Holds: " << ll->getIndex(0) << "\n";
    std::cout << "Index 3 Holds: " << ll->getIndex(3) << "\n";
    std::cout << "Tail Holds: " << ll->getIndex(4) << "\n";*/


    
    
    
    
    std::srand(std::time(nullptr)); //use current time as seed for rng
    LinkedList* ll = new  LinkedList();
    for(int i = 0; i< 5; i++)
    {
       ll->addEnd(std::rand() % 1000);
    }
    
    ll->sort();
    

 
    
}