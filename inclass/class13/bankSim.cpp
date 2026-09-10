#include <iostream>
#include <queue>
#include "event.h"
using namespace std;

/* Priority queue library: https://cplusplus.com/reference/queue/priority_queue/
 * methods:
    empty()
    size()
    top()  -- access top element
    push()  -- insert element
    pop()  -- remove top element (highest priority)
*/


void showpq(priority_queue<Event> gq)
{
    priority_queue<Event> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}

// Driver Code
int main()
{
    // just some code to demonstrate the use of the
    // C++ priority_queue library
    priority_queue<Event> banksim;
    banksim.push(Event(3, 4));
    banksim.push(Event(3, 1));

    cout << "The priority queue banksim is : ";
    showpq(banksim);

    cout << "\nbanksim.size() : " << banksim.size();
    cout << "\nbanksim.top() : " << banksim.top();

    cout << "\nbanksim.pop() : ";
    banksim.pop();
    showpq(banksim);

    return 0;
}
