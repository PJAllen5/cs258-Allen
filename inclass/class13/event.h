#pragma once
#include <iostream>
using namespace std;

class Event
{
    private:
        int time;   // how much time does a transation take?
        int priority; // the priority represents the time the person arrives
        int waittime; // after this event is processed, we can store how long
                      // the user had to wait

    public:
        Event(int time, int priority);
        
        /**
         * @brief fetches the priority of the event
         *
         * @return priority
         */
        int getPriority();
        /**
         * @brief returns the time taken by the event
         *
         * @return time
         */
        int getTime();
        /**
         * @brief returns the time spent waiting for this event
         *
         * @return waittime 
         */
        int getWaitTime();
        /**
         * @brief updates the waittime
         *
         * @param time the new waittime 
         */
        void updateWaitTime(int time);

        /**
         * @brief overloaded == operator
         *
         * @param c1 the first event
         * @param c2 the 2nd event to compare
         * @return true if c1 == c2
         */
        friend bool operator== (const Event& c1, const Event& c2);
        friend bool operator!= (const Event& c1, const Event& c2);

        friend bool operator< (const Event& c1, const Event& c2);
        friend bool operator> (const Event& c1, const Event& c2);

        friend bool operator<= (const Event& c1, const Event& c2);
        friend bool operator>= (const Event& c1, const Event& c2);
        friend ostream& operator<<(ostream& os, const Event& ev);

};

