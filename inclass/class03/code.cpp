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
    if(length == 1){
        std::cout << s;
    }
    if (length > 1)
    {
        // Write last character
        std::cout << s.substr(length - 1, 1);
        writeBackward(s.substr(0, length - 1));  // Write rest
    }  // end if
}  // end writeBackward


int sumOfInts(int start, int end)
{
    // base case
    if (start > end){
        return 0;
    }
    return start + sumOfInts(start + 1, end);

}  // end sumOfInts


void writeInts(int n) {

    if (n == 1){
        std::cout << n;
    }
    else {
        writeInts(n-1);
        std::cout << n;
    }
}  // end writeInts


int sumOfN(int n, int array[])
{
    //base case
    if (n == 0){
        return array[0];
    }
    return array[n] + sumOfN(n-1, array);

}  // end sumOfN


int fibonacci(int n)
{
    return -1;
}  // end fibonacci


int arraySearch(int array[], int length, int item)
{
    // base case
    if (length == 0){
        return 0;
    }
    else {
        if (array[length - 1] == item){
            return 1 + arraySearch(array, length - 1, item);
        }
        return 0 + arraySearch(array, length - 1, item);
    }
    return -1;
}  // end arraySearch
