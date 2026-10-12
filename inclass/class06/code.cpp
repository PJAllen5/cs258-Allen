// Example assignment

#include <string>
#include "code.hpp"
#include <stack>
#include <iostream>  // if we want to print


// display the stack in reverse order
void displayBackward(std::stack<int>& aStack) {
    std::stack<int> auxStack;
    while (!aStack.empty()){
        auxStack.push(aStack.top());
        aStack.pop();
    }

    while (!auxStack.empty()){
        std::cout << auxStack.top() << " ";
        auxStack.pop();
    }
}

// count the items in the stack
int countStack(std::stack<int>& aStack)
{
    std::stack<int> auxStack;
    int count = 0;

    while (!aStack.empty()){
        auxStack.push(aStack.top());
        aStack.pop();
        count++;
    }
    // TODO: write this.  The placeholder return is only here so the skeleton
    // has defined behaviour before you do - replace it.

    //restore aStack to its original state
    while (!auxStack.empty()){
        aStack.push(auxStack.top());
        auxStack.pop();
    }

    return count;
}

// delete every occurrence of a specified item from a Stack
std::stack<int> deleteOccurr(std::stack<int>& aStack, int item)
{
    std::stack<int> auxStack;

    while (!aStack.empty()){
        if (aStack.top() != item){
            auxStack.push(aStack.top());
        }
        aStack.pop();
    }

    while (!auxStack.empty()){
        aStack.push(auxStack.top());
        auxStack.pop();
    }
    // TODO: write this.  The placeholder return is only here so the skeleton
    // has defined behaviour before you do - replace it.
    return aStack;
}

// specify remove n
/** @brief remove topmost N entries from the stack
*  @param n the number of entries to remove
*  @param stack the stack to remove entries from
*  @return true if the entries were removed, false
*  if the stack had fewer than n entries.
*  @return int of number of items we removed from the stack
*  @pre has at least n entries.
*  @pre n >= 0.
*  @post the stack n fewer entries than before, or is empty.
*/
bool removeN(int n, std::stack<int>& stack){}

// determine whether a string is in the language
bool inLanguage(std::string theString)
{
    // create s'
    // read halfway through the string and copying to the stack
    std::stack<char> auxStack;

    int length = theString.length();
    int halfLength = length / 2;

    for (int i - 0; i < halfLength; i++){
        auxStack.push(theString[i]);
    }

    // auxstack has half the string
    for (int i = halfLength; i <length; i++){
        if (auxStack.empty() || auxStack.top() != theString[i]){
            return false;
        }
        auxStack.pop();
    }
    return true;

    // TODO: write this.  The placeholder return is only here so the skeleton
    // has defined behaviour before you do - replace it.
}


/* The c++ stack library has the following methods:
empty() – Returns whether the stack is empty
size() – Returns the size of the stack
top() – Returns a reference to the top most element of the stack
push(g) – Adds the element ‘g’ at the top of the stack
pop() – Deletes the most recent entered element of the stack
stack<int> stack;

Example Stack use:

using namespace std;
int main() {
    stack<int> stack;
    stack.push(21);// The values pushed in the stack should be of the same data
which is written during declaration of stack stack.push(22); stack.push(24);
    stack.push(25);
    int num=0;
    stack.push(num);
    stack.pop();
    stack.pop();
    stack.pop();

    while (!stack.empty()) {
        cout << stack.top() <<" ";
        stack.pop();
    }
}
*/
