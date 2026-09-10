// Example assignment

#include <string>
#include "code.hpp"
#include <stack>
#include <iostream>  // if we want to print


// display the stack in reverse order
void displayBackward(std::stack<int>& aStack)
{
}

// count the items in the stack
int countStack(std::stack<int>& aStack)
{
    // TODO: write this.  The placeholder return is only here so the skeleton
    // has defined behaviour before you do - replace it.
    return 0;
}

// delete every occurrence of a specified item from a Stack
std::stack<int> deleteOccurr(std::stack<int>& aStack, int item)
{
    // TODO: write this.  The placeholder return is only here so the skeleton
    // has defined behaviour before you do - replace it.
    return aStack;
}

// specify remove n


// determine whether a string is in the language
bool inLanguage(std::string theString)
{
    // TODO: write this.  The placeholder return is only here so the skeleton
    // has defined behaviour before you do - replace it.
    return false;
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
    stack.push(21);// The values pushed in the stack should be of the same data which is written during declaration of stack
    stack.push(22);
    stack.push(24);
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
