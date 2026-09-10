//   Created by Frank M. Carrano and Timothy M. Henry.
//   Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Listing 7-1
    @file ArrayStack.cpp */
#include <cassert>       // For assert
#include "ArrayStack.h"  // Header file

template<class ItemType>
ArrayStack<ItemType>::ArrayStack()
    : items(new ItemType[MAX_STACK]), top(-1), capacity(MAX_STACK)
{
}  // end default constructor

// This class allocates memory, so it must supply its own copy constructor,
// assignment operator and destructor - the Rule of Three.  The versions the
// compiler writes for you would copy the pointer rather than the array, so two
// stacks would share one array and both would try to free it.

template<class ItemType>
ArrayStack<ItemType>::ArrayStack(const ArrayStack<ItemType>& aStack)
    : items(new ItemType[aStack.capacity]), top(aStack.top),
      capacity(aStack.capacity)
{
    for (int i = 0; i <= top; i++)
    {
        items[i] = aStack.items[i];
    }  // end for
}  // end copy constructor

template<class ItemType>
ArrayStack<ItemType>&
ArrayStack<ItemType>::operator=(const ArrayStack<ItemType>& aStack)
{
    if (this != &aStack)
    {  // Guard against self assignment
        ItemType* newItems = new ItemType[aStack.capacity];
        for (int i = 0; i <= aStack.top; i++)
        {
            newItems[i] = aStack.items[i];
        }  // end for
        delete[] items;
        items = newItems;
        top = aStack.top;
        capacity = aStack.capacity;
    }  // end if

    return *this;
}  // end operator=

template<class ItemType>
ArrayStack<ItemType>::~ArrayStack()
{
    delete[] items;
}  // end destructor

template<class ItemType>
int ArrayStack<ItemType>::getSize() const
{
    return capacity;
}  // end getSize

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{
    return top < 0;
}  // end isEmpty

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry)
{
    bool result = false;
    if (top < capacity - 1)
    {  // Does stack have room for newEntry?
        top++;
        items[top] = newEntry;
        result = true;
    }  // end if

    return result;
}  // end push


template<class ItemType>
bool ArrayStack<ItemType>::pop()
{
    bool result = false;
    if (!isEmpty())
    {
        top--;
        result = true;
    }  // end if

    return result;
}  // end pop


template<class ItemType>
ItemType ArrayStack<ItemType>::peek() const
{
    assert(!isEmpty());  // Enforce precondition

    // Stack is not empty; return top
    return items[top];
}  // end peek
// End of implementation file.
