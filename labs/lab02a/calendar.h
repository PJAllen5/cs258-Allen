// =============================================================================
// File:    calendar.h
// Author:  PJ Allen
// Course:  CS258 - Lab 2a (extra credit)
// Date:    10/18/2026
//
// Header file for the Calendar class: an ADT that represents a single date in
// the Gregorian calendar as a month, day, and year.  The date can be advanced
// one day at a time and displayed using numbers (4/1/2014) or words
// (Tuesday, April 1, 2014).
// =============================================================================
#pragma once

#include <stdexcept>
#include <string>

class Calendar
{
    public:
        /**
         * Builds the date month/day/year.
         *
         * @param month  the month, 1 (January) through 12 (December)
         * @param day    the day of the month, 1 through the last day of month
         * @param year   the year, e.g. 2014
         * @throws std::invalid_argument if the date does not exist
         *         (for example 2/30/2014, or 2/29 in a non-leap year)
         */
        Calendar(int month, int day, int year);

        /**
         * Gets the month of this date.
         *
         * @return the month, 1 (January) through 12 (December)
         */
        int getMonth() const;

        /**
         * Gets the day of the month of this date.
         *
         * @return the day, 1 through the number of days in the month
         */
        int getDay() const;

        /**
         * Gets the year of this date.
         *
         * @return the year
         */
        int getYear() const;

        /**
         * Moves the date forward by one day, rolling over to the next month
         * and year when needed (e.g. 12/31/2014 becomes 1/1/2015).
         */
        void advanceDay();

        /**
         * Formats the date using numbers.
         *
         * @return the date as month/day/year, e.g. "4/1/2014"
         */
        std::string toNumberString() const;

        /**
         * Formats the date using words, including the day of the week.
         *
         * @return the date in words, e.g. "Tuesday, April 1, 2014"
         */
        std::string toWordString() const;

        /**
         * Gets the name of the day of the week this date falls on.
         *
         * @return the day name, e.g. "Tuesday"
         */
        std::string dayOfWeekName() const;

        /**
         * Prints the date to standard output, followed by a newline.
         *
         * @param useWords  true to print in words ("Tuesday, April 1, 2014"),
         *                  false to print in numbers ("4/1/2014")
         */
        void display(bool useWords) const;

    private:
        int month;   // 1 = January ... 12 = December
        int day;     // 1 ... number of days in the month
        int year;

        /**
         * Checks whether a year is a leap year in the Gregorian calendar.
         *
         * @param year  the year to check
         * @return true if the year has a February 29, false otherwise
         */
        static bool isLeapYear(int year);

        /**
         * Gets the number of days in a month, accounting for leap years.
         *
         * @param month  the month, 1 through 12
         * @param year   the year the month is in
         * @return the number of days in that month, 28 through 31
         */
        static int daysInMonth(int month, int year);

        /**
         * Calculates which day of the week this date falls on.
         *
         * @return 0 for Sunday, 1 for Monday, ... 6 for Saturday
         */
        int dayOfWeek() const;
};
