// main.cpp
#include <iostream>
#include "utils.h"
#include "math.h"
#include "container.h"

int main() {
    std::cout << "C++ Compilation Example" << std::endl;

    Container<int> mycontainer;


    printMessage("Hello from utils!");

    int result = add(5, 3);
    std::cout << "5 + 3 = " << result << std::endl;

    return 0;
}
