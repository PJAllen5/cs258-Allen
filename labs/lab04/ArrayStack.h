//   Created by Frank M. Carrano and Timothy M. Henry.
//   Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT stack: Array-based implementation.
 Listing 7-1
 @file ArrayStack.h */

#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_

#include "StackInterface.h"

// The capacity the stack starts with.  ArrayStackRS doubles from here.
const int MAX_STACK = 5;

template<class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
protected:
    ItemType* items;  // Array of stack items, allocated on the heap
    int top;          // Index to top of stack
    int capacity;     // Number of slots in the array

public:
    ArrayStack();                                    // Default constructor
    ArrayStack(const ArrayStack<ItemType>& aStack);  // Copy constructor
    ArrayStack<ItemType>& operator=(const ArrayStack<ItemType>& aStack);
    virtual ~ArrayStack();  // Destructor
    bool isEmpty() const;
    virtual bool push(const ItemType& newEntry);
    bool pop();
    int getSize() const;  // return the size (capacity) of the array
    ItemType peek() const;
};  // end ArrayStack

#include "ArrayStack.cpp"
#endif  // ARRAYSTACK_H_
