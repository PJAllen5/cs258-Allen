/*
 * File:    fractions.hpp
 * Author:  PJ Allen
 * Course:  CS258, Lab 2
 * Date:    10/11/2026
 *
 * Purpose: Declares the Fractions class, an ADT for fractions with int
 *          numerator and denominator.  Supports add, subtract, multiply,
 *          and divide (each returns a new Fractions in lowest terms),
 *          reducing to lowest terms, equality comparison, and printing.
 */

#ifndef FRACTIONS_HPP
#define FRACTIONS_HPP

#include <iostream>
#include <stdexcept>

// declares the Fractions class and its member functions
class Fractions {
    private:
        // member variable to store the numerator of the fraction
        int numerator;
        // member variable to store the denominator of the fraction
        int denominator;

        // helper function to compute the greatest common divisor of two integers recursively
        static int gcd(int a, int b);

    public:
        // constructor to initialize the numerator and denominator of the fraction
        Fractions(int num, int denom);
        // member function to add two fractions and return the result in lowest terms
        Fractions add(const Fractions& aFraction) const;
        // member function to subtract two fractions and return the result in lowest terms
        Fractions subtract(const Fractions& aFraction) const;
        // member function to multiply two fractions and return the result in lowest terms
        Fractions multiply(const Fractions& aFraction) const;
        // member function to divide two fractions and return the result in lowest terms
        Fractions divide(const Fractions& aFraction) const;
        // member function to reduce the fraction to its lowest terms
        void reduceToLowestTerms();
        // member function to check if two fractions are equal
        bool operator ==(const Fractions& aFraction) const;

        // friend function to print the fraction in the form of a fraction to the output stream
        friend std::ostream& operator<<(std::ostream& out, const Fractions& frac);
};

#endif // FRACTIONS_HPP
