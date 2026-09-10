#include <iostream>
using namespace std;

#include "event.h"

Event::Event(int time, int priority)
    : time(time), priority(priority), waittime(-1)
{
}
int Event::getPriority()
{
    return priority;
}

int Event::getTime()
{
    return time;
}

int Event::getWaitTime()
{
    return waittime;
}

void Event::updateWaitTime(int time)
{
    waittime = time;
}


ostream& operator<<(ostream& os, const Event& ev)
{
    os << ev.time << ':' << ev.priority;
    return os;
}

bool operator==(const Event& c1, const Event& c2)
{
    return c1.priority == c2.priority;
}

bool operator!=(const Event& c1, const Event& c2)
{
    return c1.priority != c2.priority;
}

bool operator<(const Event& c1, const Event& c2)
{
    return c1.priority > c2.priority;
}

bool operator>(const Event& c1, const Event& c2)
{
    return c1.priority < c2.priority;
}

bool operator<=(const Event& c1, const Event& c2)
{
    return c1.priority >= c2.priority;
}

bool operator>=(const Event& c1, const Event& c2)
{
    return c1.priority <= c2.priority;
}
