// Example assignment

#include <string>
#include "code.hpp"

template<class ItemType>
void deleteNode(Node<ItemType>* headPtr){
    Node<ItemType>* alias = headPtr; // alias to headptr

    alias = alias->getNext(); // alias points to 2nd node in chain

    // Node<ItemType>* alias = headPtr->getNext();
    headPtr->setNext(alias->getNext()); // headptr points to 3rd node in chain

    // delete 2nd node
    delete alias;
    alias = nullptr; // alias set to nullptr; no dangling pointer address
};

