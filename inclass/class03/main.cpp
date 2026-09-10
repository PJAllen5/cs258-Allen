#include "code.hpp"
#include <iostream>

int main()
{
    // test our void functions
    std::cout << "testing writeBackward:" << std::endl;
    writeBackward("hello");
    std::cout << std::endl << std::endl;

    std::cout << "testing writeInts:" << std::endl;
    writeInts(6);
}
