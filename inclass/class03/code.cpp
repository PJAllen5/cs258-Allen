// Example assignment

#include <string>
#include "code.hpp"
#include <iostream>


/* writeBackward with base case of zero
 * revise with a base case of 1
 */
void writeBackward(std::string s)
{
    int length = s.size();
    if (length > 0)
    {
        // Write last character
        std::cout << s.substr(length - 1, 1);
        writeBackward(s.substr(0, length - 1));  // Write rest
    }  // end if
}  // end writeBackward


int sumOfInts(int start, int end)
{
    return -1;
}  // end sumOfInts


void writeInts(int n)
{

}  // end writeInts


int sumOfN(int n, int array[])
{
    return -1;
}  // end sumOfN


int fibonacci(int n)
{
    return -1;
}  // end fibonacci


int arraySearch(int array[], int length, int item)
{
    return -1;
}  // end arraySearch
