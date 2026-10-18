// =============================================================================
// File:    calendar_demo.cpp
// Author:  PJ Allen
// Course:  CS258 - Lab 2a (extra credit)
// Date:    10/18/2026
//
// Demonstrates the Calendar class: building dates, displaying them in numbers
// and words, and advancing across month ends, year ends, and leap days.
// Build and run with:  make run_calendar
// =============================================================================
#include "calendar.h"

#include <iostream>

/**
 * Prints a date in both formats, advances it by one day, and prints it again.
 *
 * @param date  the starting date; passed by value, so the caller's copy is
 *              not advanced
 */
static void showAdvance(Calendar date)
{
    std::cout << "  " << date.toNumberString() << "  (" << date.toWordString()
              << ")" << std::endl;
    date.advanceDay();
    std::cout << "  -> " << date.toNumberString() << "  (" << date.toWordString()
              << ")" << std::endl << std::endl;
}

/**
 * Runs the Calendar demonstration.
 *
 * @return 0 on success
 */
int main()
{
    std::cout << "Display formats for 4/1/2014:" << std::endl;
    Calendar example(4, 1, 2014);
    std::cout << "  numbers: ";
    example.display(false);
    std::cout << "  words:   ";
    example.display(true);
    std::cout << std::endl;

    std::cout << "Ordinary day:" << std::endl;
    showAdvance(Calendar(4, 1, 2014));

    std::cout << "End of a 30-day month:" << std::endl;
    showAdvance(Calendar(4, 30, 2014));

    std::cout << "End of the year:" << std::endl;
    showAdvance(Calendar(12, 31, 2014));

    std::cout << "February in a non-leap year:" << std::endl;
    showAdvance(Calendar(2, 28, 2014));

    std::cout << "February in a leap year:" << std::endl;
    showAdvance(Calendar(2, 28, 2024));
    showAdvance(Calendar(2, 29, 2024));

    std::cout << "Century years (1900 is not a leap year, 2000 is):" << std::endl;
    showAdvance(Calendar(2, 28, 1900));
    showAdvance(Calendar(2, 28, 2000));

    std::cout << "One week starting 10/18/2026:" << std::endl;
    Calendar week(10, 18, 2026);
    for (int i = 0; i < 7; i++)
    {
        std::cout << "  ";
        week.display(true);
        week.advanceDay();
    }
    std::cout << std::endl;

    // An invalid date is rejected by the constructor.
    std::cout << "Trying to build 2/29/2023:" << std::endl;
    try
    {
        Calendar bad(2, 29, 2023);
        std::cout << "  unexpectedly accepted" << std::endl;
    }
    catch (const std::invalid_argument &error)
    {
        std::cout << "  rejected: " << error.what() << std::endl;
    }

    return 0;
}
