// =============================================================================
// File:    poly.cpp
// Author:  PJ Allen
// Course:  CS258 - Lab 2a
// Date:    10/18/2026
//
// Implementation of the array-based Polynomial class declared in poly.h.
// =============================================================================
#include "poly.h"

Polynomial::Polynomial(double coefficients[], int degree)
{
    if (degree < 0)
    {
        throw std::out_of_range("Polynomial: degree must not be negative");
    }

    // Copy into our own array rather than keeping a pointer to the caller's,
    // so later changes to their array do not affect us.
    polyDegree = degree;
    coeffs = copyArray(coefficients, degree);
}

Polynomial::Polynomial(const Polynomial &other)
{
    // Deep copy: allocate a separate array instead of copying the pointer,
    // otherwise both objects would delete[] the same memory.
    polyDegree = other.polyDegree;
    coeffs = copyArray(other.coeffs, other.polyDegree);
}

Polynomial &Polynomial::operator=(const Polynomial &other)
{
    // Without this check, "p = p" would free the array it is about to copy.
    if (this != &other)
    {
        // Allocate the new array before freeing the old one, so that if new
        // throws, this polynomial is left unchanged.
        double *newCoeffs = copyArray(other.coeffs, other.polyDegree);
        delete[] coeffs;
        coeffs = newCoeffs;
        polyDegree = other.polyDegree;
    }
    return *this;
}

Polynomial::~Polynomial()
{
    delete[] coeffs;
}

int Polynomial::degree() const
{
    return polyDegree;
}

double Polynomial::coefficient(int exponent) const
{
    checkExponent(exponent);
    return coeffs[exponent];
}

void Polynomial::changeCoefficient(double value, int exponent)
{
    checkExponent(exponent);
    coeffs[exponent] = value;
}

double *Polynomial::copyArray(const double source[], int degree)
{
    // A degree-n polynomial has n + 1 coefficients, so the loop includes n.
    double *copy = new double[degree + 1];
    for (int i = 0; i <= degree; i++)
    {
        copy[i] = source[i];
    }
    return copy;
}

void Polynomial::checkExponent(int exponent) const
{
    if (exponent < 0 || exponent > polyDegree)
    {
        throw std::out_of_range("Polynomial: exponent must be between 0 and degree");
    }
}
