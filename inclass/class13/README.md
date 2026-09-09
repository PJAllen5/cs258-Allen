# CS258 in-class-11: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).

### The assignment
- Consider a slight variation of the ADT queue. In this variation, new items can be added to and removed from
either end. This ADT is commonly called a double-ended queue, or deque. Specify each method of the deque
by stating the method’s purpose; by describing its parameters; and by writing preconditions, postconditions, and
a pseudocode version of its header. Then write a C++ template interface for these methods that includes
javadoc -style comments.
- Use a deque, as described in the previous exercise, to solve the read-and-correct problem given in
Section 6.1.1 of Chapter 6 . In that problem, you enter text at a keyboard and correct typing mistakes by
using the Backspace key. Each backspace erases the most recently entered character. Your pseudocode
solution should provide a corrected string of characters in the order in which they were entered at the
keyboard.
- Implement the event-driven simulation of a bank that this chapter described. A queue of arrival events will represent the line of customers in the bank. Maintain the arrival events and departure events in a priority queue,
sorted by the time of the event. Use a link-based implementation for the event list.
The input is a text file of arrival and transaction times. Each line of the file contains the arrival time and
required transaction time for a customer. The arrival times are ordered by increasing time.
Your program must count customers and keep track of their cumulative waiting time. These statistics are
sufficient to compute the average waiting time after the last event has been processed. Display a trace of the
events executed and a summary of the computed statistics (the total number of arrivals and average time spent
waiting in line). For example, the input file shown in the left columns of the following table should produce the
output shown in the right column.

| Input | file |
| ------------- | ------------- |
| 1 | 5 |
| 2 | 5 |
| 4 | 5 |
| 20 | 5  |
| 22 | 5 |
| 24 | 5 |
| 26 | 5 |
| 28 | 5 |
| 30 | 5 |
| 88 | 3 |


Output from processing file \
Simulation Begins \
Processing an arrival event at time: 1\
Processing an arrival event at time: 2\
Processing an arrival event at time: 4\
Processing a departure event at time: 6\
Processing a departure event at time: 11\
Processing a departure event at time: 16\
Processing an arrival event at time: 20\
Processing an arrival event at time: 22\
Processing an arrival event at time: 24\
Processing a departure event at time: 25\
Processing an arrival event at time: 26\
Processing an arrival event at time: 28\
Processing an arrival event at time: 30\
Processing a departure event at time: 30\
Processing a departure event at time: 35\
Processing a departure event at time: 40\
Processing a departure event at time: 45\
Processing a departure event at time: 50\
Processing an arrival event at time: 88\
Processing a departure event at time: 91\
Simulation Ends\
Final Statistics:\
Total number of people processed: 10\
Average amount of time spent waiting: 5.6


- The people who run the Motor Vehicle Department (MVD) have a problem. They are concerned that people do
not spend enough time waiting in lines to appreciate the privilege of owning and driving an automobile. The
current arrangement is as follows:
  - When people walk in the door, they must wait in a line to sign in.
  - Once they have signed in, they are told either to stand in line for registration renewal or to wait until they
are called for license renewal.
  - Once they have completed their desired transaction, they must go and wait in line for the cashier.
  - When they finally get to the front of the cashier’s line, if they expect to pay by check, they are told that all
checks must get approved. To do this, it is necessary to go to the check-approver’s table and then reenter
the cashier’s line at the end.
- Write an event-driven simulation to help the MVD gather statistics. Each line of input will contain
  - A desired transaction code ( L for license renewal, R for registration renewal)
  - A method-of-payment code ( $ for cash, C for check)
  - An arrival time (integer)
  - A name
- Write out the specifics of each event (when, who, what, and so on). Then display these final statistics:
  - The total number of license renewals and the average time spent in MVD (arrival until completion of
payment) to renew a license
  - The total number of registration renewals and the average time spent in MVD (arrival until completion of
payment) to renew a registration
- Incorporate the following details into your program:
  - Define the following events: arrive, sign in, renew license, renew registration, and cope with the cashier
(make a payment or find out about check approval).
  - In the case of a tie, let the order of events be determined by the list of events just given—that is, arrivals
have the highest priority.
  - Assume that the various transactions take the following amounts of time:
Sign in 10 seconds\
Renew license 90 seconds\
Register automobile 60 seconds\
See cashier (payment) 30 seconds\
See cashier (check not approved) 10 seconds\
  - For the sake of this simulation, you can assume that checks are approved instantly. Therefore, the rule for
arriving at the front of the cashier’s line with a check that has not been approved is to go to the back of the
cashier’s line with a check that has been approved.





### Setup command
N/A

### Run command
`make ?`

### Other test commands
If you want to run just one of the tests, you can use `make test<x>` and replace `<x>` with the test number.

If you just want to compile without running tests, use `make`
### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.
