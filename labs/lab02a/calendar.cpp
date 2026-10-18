// =============================================================================
// File:    calendar.cpp
// Author:  PJ Allen
// Course:  CS258 - Lab 2a (extra credit)
// Date:    10/18/2026
//
// Implementation of the Calendar class declared in calendar.h.
// =============================================================================
#include "calendar.h"

#include <iostream>

// Names used when displaying a date in words.  Index 0 of MONTH_NAMES is
// unused so that month numbers (1-12) can be used directly as indexes.
static const std::string MONTH_NAMES[] = {
    "", "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};
static const std::string DAY_NAMES[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

Calendar::Calendar(int month, int day, int year)
{
    if (month < 1 || month > 12)
    {
        throw std::invalid_argument("Calendar: month must be between 1 and 12");
    }
    if (day < 1 || day > daysInMonth(month, year))
    {
        throw std::invalid_argument("Calendar: day does not exist in that month");
    }

    this->month = month;
    this->day = day;
    this->year = year;
}

int Calendar::getMonth() const
{
    return month;
}

int Calendar::getDay() const
{
    return day;
}

int Calendar::getYear() const
{
    return year;
}

void Calendar::advanceDay()
{
    day++;

    // Past the end of the month: start the next month.
    if (day > daysInMonth(month, year))
    {
        day = 1;
        month++;

        // Past December: start a new year.
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
}

std::string Calendar::toNumberString() const
{
    return std::to_string(month) + "/" + std::to_string(day) + "/" +
           std::to_string(year);
}

std::string Calendar::toWordString() const
{
    return dayOfWeekName() + ", " + MONTH_NAMES[month] + " " +
           std::to_string(day) + ", " + std::to_string(year);
}

std::string Calendar::dayOfWeekName() const
{
    return DAY_NAMES[dayOfWeek()];
}

void Calendar::display(bool useWords) const
{
    if (useWords)
    {
        std::cout << toWordString() << std::endl;
    }
    else
    {
        std::cout << toNumberString() << std::endl;
    }
}

bool Calendar::isLeapYear(int year)
{
    // Every 4th year is a leap year, except century years, unless the
    // century year is also divisible by 400 (so 2000 was, 1900 was not).
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int Calendar::daysInMonth(int month, int year)
{
    // Index 0 is unused so month numbers can be used directly.
    static const int DAYS[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
    {
        return 29;
    }
    return DAYS[month];
}

int Calendar::dayOfWeek() const
{
    // Sakamoto's method.  Each entry in OFFSETS shifts the result for the
    // start of that month.  January and February are treated as the last
    // months of the previous year, so a leap day falls at the end of the
    // "year" and the year / 4 - year / 100 + year / 400 terms count it
    // correctly.
    static const int OFFSETS[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

    int y = year;
    if (month < 3)
    {
        y--;
    }
    return (y + y / 4 - y / 100 + y / 400 + OFFSETS[month - 1] + day) % 7;
}
