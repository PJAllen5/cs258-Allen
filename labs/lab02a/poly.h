// =============================================================================
// File:    poly.h
// Author:  PJ Allen
// Course:  CS258 - Lab 2a
// Date:    10/18/2026
//
// Header file for the Polynomial class: an array-based implementation of the
// Polynomial ADT (Chapter 1, Exercise 9).
//
// A polynomial is stored as an array of coefficients, where the index of each
// coefficient is its exponent.  For example, 9 + 1x^2 + 7x^3 + 4x^5 is stored
// as {9, 0, 1, 7, 0, 4} with degree 5.
//
// The array is allocated dynamically to exactly degree + 1 elements, so the
// class manages its own memory with a destructor, copy constructor, and copy
// assignment operator (the "Rule of Three").  Every Polynomial owns its own
// array; copies never share storage.
// =============================================================================
#pragma once

#include <stdexcept>

class Polynomial
{
    public:
        /**
         * Builds a polynomial from an array of coefficients.  The array is
         * copied, so the caller may change or destroy it afterwards.
         *
         * @param coefficients  an array of degree + 1 values, where
         *                      coefficients[i] is the coefficient of x^i
         * @param degree        the largest exponent; must not be negative
         * @throws std::out_of_range if degree is negative
         */
        Polynomial(double coefficients[], int degree);

        /**
         * Builds a deep copy of another polynomial.  The new polynomial gets
         * its own array, so changing one does not affect the other.
         *
         * @param other  the polynomial to copy
         */
        Polynomial(const Polynomial &other);

        /**
         * Replaces this polynomial with a deep copy of another one, freeing
         * this polynomial's old array.  Assigning a polynomial to itself
         * leaves it unchanged.
         *
         * @param other  the polynomial to copy
         * @return a reference to this polynomial, so assignments can chain
         */
        Polynomial &operator=(const Polynomial &other);

        /**
         * Frees the dynamically allocated coefficient array.
         */
        ~Polynomial();

        /**
         * Gets the degree of the polynomial.
         *
         * @return the largest exponent
         */
        int degree() const;

        /**
         * Gets the coefficient of one term.
         *
         * @param exponent  the exponent of the term, 0 through degree
         * @return the coefficient of x^exponent
         * @throws std::out_of_range if exponent is not in 0..degree
         */
        double coefficient(int exponent) const;

        /**
         * Changes the coefficient of one term.  The polynomial never grows,
         * so the term must already exist.
         *
         * @param value     the new coefficient
         * @param exponent  the exponent of the term, 0 through degree
         * @throws std::out_of_range if exponent is not in 0..degree
         */
        void changeCoefficient(double value, int exponent);

    private:
        int polyDegree;    // largest exponent
        double *coeffs;    // dynamic array of polyDegree + 1 coefficients;
                           // coeffs[i] is the coefficient of x^i

        /**
         * Allocates a new array of degree + 1 elements and copies the
         * coefficients into it.  Shared by the constructor, copy
         * constructor, and assignment operator.
         *
         * @param source  an array of at least degree + 1 values to copy
         * @param degree  the largest exponent of source
         * @return a newly allocated array the caller is responsible for
         *         freeing with delete[]
         */
        static double *copyArray(const double source[], int degree);

        /**
         * Validates an exponent against this polynomial's degree.
         *
         * @param exponent  the exponent to check
         * @throws std::out_of_range if exponent is not in 0..polyDegree
         */
        void checkExponent(int exponent) const;
};
