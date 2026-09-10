//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file NotFoundException.h */

#ifndef NOT_FOUND_EXCEPTION_
#define NOT_FOUND_EXCEPTION_

#include <stdexcept>
#include <string>

class NotFoundException : public std::logic_error
{
public:
    NotFoundException(const std::string& message = "")
        : std::logic_error("Not Found Exception: " + message)
    {
    }
};  // end NotFoundException
#endif
