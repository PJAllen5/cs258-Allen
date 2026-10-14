//   Created by Frank M. Carrano and Timothy M. Henry.
//   Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//   Copyright (c) 2016 __Pearson Education__. All rights reserved.

/** @file StackInterface.h */

#ifndef STACK_INTERFACE_
#define STACK_INTERFACE_

template<class ItemType>
class StackInterface
{
public:
    /** Sees whether this stack is empty.
    @return True if the stack is empty, or false if not. */
    virtual bool isEmpty() const = 0;

    /** Adds a new entry to the top of this stack.
    @post If the operation was successful, newEntry is at the top of the stack.
    @param newEntry The object to be added as a new entry.
    @return True if the addition is successful or false if not. */
    virtual bool push(const ItemType& newEntry) = 0;

    /** 
     * @brief: removes n entries from the stack
     * @param: n the number of entries to remove
     * @pre: has at least n entries
     * @return: false if the precondition wasnt met and
     * we dont remove anything,; true if we removed entries.
     */
    virtual bool remove(int n) = 0;

    /** Removes the top of this stack.
    @post If the operation was successful, the top of the stack
    has been removed.
    @return True if the removal is successful or false if not. */
    virtual bool pop() = 0;

    /** Returns the top of this stack.
    @pre The stack is not empty.
    @post The top of the stack has been returned, and
    the stack is unchanged.
    @return The top of the stack. */
    virtual ItemType peek() const = 0;

    /** @brief: prints the contents of the stack 
     * @post: the contents of the stack are printed to console.
    */
    void display(){
        // before print, store everything.
        std::vector<ItemType> auxStack;

        while (!isEmpty()){
            std::cout << peek() << std::endl;
            auxStack.push_back(peek());
            pop();
        }
        // restore the stack
        while (!auxStack.empty()){
            push(auxStack.back());
            auxStack.pop_back();
        }
    }
    /** Destroys object and frees memory allocated by object. */
    virtual ~StackInterface() {}
};  // end StackInterface
#endif
