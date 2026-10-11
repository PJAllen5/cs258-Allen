/*
 * File:    fractions.cpp
 * Author:  PJ Allen
 * Course:  CS258, Lab 2
 * Date:    10/11/2026
 *
 * Purpose: Implements the Fractions class, an ADT for fractions with int numerator and denominator.
 *          Supports add, subtract, multiply, and divide (each returns a new Fractions in lowest terms),
 *          reducing to lowest terms, equality comparison, and printing.
 *          Throws an exception if the denominator is zero.
 */

#include "fractions.hpp"

#include <cstdlib>
#include <iostream>
#include <stdexcept>

// implements the constructor which initializes the numerator and denominator of the fraction.
Fractions::Fractions(int num, int denom) : numerator(num), denominator(denom) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
}

// computes gcd recursively while checking for base case when b equals zero.
// if b is not zero, the function calls itself with b and a % b as the new parameters until it reaches
// the base case, when it returns a as the gcd.
int Fractions::gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

// implements the add function which adds two fractions and returns the lowest terms of the new fraction.
// creates a shared denominator to add the fractions.
Fractions Fractions::add(const Fractions& aFraction) const {
    Fractions result(numerator * aFraction.denominator + aFraction.numerator * denominator,
                     denominator * aFraction.denominator);
    result.reduceToLowestTerms();
    return result;
}

// implements the subtract function which subtracts two fractions and returns the result in lowest terms.
// creates a shared denominator to enable fraction subtraction.
Fractions Fractions::subtract(const Fractions& aFraction) const {
    Fractions result(numerator * aFraction.denominator - aFraction.numerator * denominator,
                     denominator * aFraction.denominator);
    result.reduceToLowestTerms();
    return result;
}

// implements the multiply function which multiplies two fractions
// and reduces the final product to lowest terms.
Fractions Fractions::multiply(const Fractions& aFraction) const {
    Fractions result(numerator * aFraction.numerator,
                     denominator * aFraction.denominator);
    result.reduceToLowestTerms();
    return result;
}

// implements the divide function which divides two fractions by
// multiplying the first by the reciprocal of the second,
// then reduces to lowest terms.
Fractions Fractions::divide(const Fractions& aFraction) const {
    Fractions result(numerator * aFraction.denominator,
                     denominator * aFraction.numerator);
    result.reduceToLowestTerms();
    return result;
}

// implements the reduceToLowestTerms function which
// reduces fractions by dividing them by their greatest common divisor. 
// if the denominator is negative, it makes it positive and negates the numerator.
void Fractions::reduceToLowestTerms() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    int divisor = gcd(std::abs(numerator), denominator);
    numerator = numerator / divisor;
    denominator = denominator / divisor;
}

// implements equality operator to check if two fractions are equal to each other by cross
// multiplying the numerator by the denominator of the other fraction.
bool Fractions::operator ==(const Fractions& aFraction) const {
    return numerator * aFraction.denominator == aFraction.numerator * denominator;
}

// prints the fraction in the form of a fraction to the output stream.
std::ostream& operator<<(std::ostream& out, const Fractions& frac) {
    out << frac.numerator << '/' << frac.denominator;
    return out;
}
