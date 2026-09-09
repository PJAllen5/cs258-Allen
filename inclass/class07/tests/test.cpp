#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() -     only do this in one cpp file

#include "../code.hpp"
#include "catch.hpp"
#include <stack>

// Test our deletOccurr function
TEST_CASE( "### In Class - deleteOccurr ###", "[test2]" ) {
    std::stack<int> myStack;
    for (int i=0; i<8;i++){
        myStack.push(i);
    }
    for (int i=0; i<13;i++){
        myStack.push(4);
    }
    for (int i=0; i<8;i++){
        myStack.push(i);
    }
    std::stack<int> stack2;
    stack2.push(0);
    stack2.push(1);
    stack2.push(2);
    stack2.push(3);
    stack2.push(5);
    stack2.push(6);
    stack2.push(7);
    stack2.push(0);
    stack2.push(1);
    stack2.push(2);
    stack2.push(3);
    stack2.push(5);
    stack2.push(6);
    stack2.push(7);
    REQUIRE( deleteOccurr(myStack, 4) == stack2);
}



TEST_CASE( "### In Class - inLanguage ###", "[test3]" ) {
    REQUIRE( inLanguage("dad") == true);
    REQUIRE( inLanguage("civic") == true);
    REQUIRE( inLanguage("redivider") == true);
    REQUIRE( inLanguage("racecarr") == false);
}


