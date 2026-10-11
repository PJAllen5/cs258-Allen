/*
 * File:    recursion.hpp
 * Author:  PJ Allen
 * Course:  CS258, Lab 2
 * Date:    10/11/2026
 *
 * Purpose: Declares the recursion class, which provides recursive functions
 *          for calculating the sum of squares and power of a number.
 */

#ifndef RECURSION_HPP_
#define RECURSION_HPP_

#include <string>

// declares the recursion class and its member functions
class recursion
{
public:
    // constructor for the recursion class
    recursion();
    // member function to calculate the sum of squares of the first n (n > 0) natural numbers recursively
    int sumOfSquares(int n);
    // member function to calculate the power of a number a raised to n (n >= 0) recursively
    double power(double a, int n);
};

#endif  // RECURSION_HPP_
