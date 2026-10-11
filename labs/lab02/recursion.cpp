/*
 * File:    recursion.cpp
 * Author:  PJ Allen
 * Course:  CS258, Lab 2
 * Date:    10/11/2026
 *
 * Purpose: Implements the recursion class, which provides recursive functions for
 *          calculating the sum of squares and power of a number.
 */

#include "recursion.hpp"

// implements the constructor for the recursion class
recursion::recursion()
{
}

// implements the sumOfSquares function which calculates the sum of
// squares of the first n natural numbers recursively
int recursion::sumOfSquares(int n)
{
    if (n == 0){
        return 0; // base case: the sum of squares of the first 0 natural numbers is 0
    }
    else {
        // recursive case: n^2 + sum of squares of 1..(n-1)
        return n * n + sumOfSquares(n-1);
    }
}

// implements the power function which calculates the power of a number a raised to n recursively
double recursion::power(double a, int n)
{
    if (n == 0){
        return 1.0; // base case: any number raised to the power of 0 is 1
    }
    else {
        // recursive case: a raised to the power of n is a multiplied by a raised to the power of (n-1)
        return a * power(a, n - 1);
    }
}

