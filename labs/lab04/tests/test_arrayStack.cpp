#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() -     only do this in one cpp file

#include "../ArrayStackRS.h"
#include "catch.hpp"



TEST_CASE( "### ArrayStack ###", "[test3]" ) {
    ArrayStackRS<int> myStack;

    for(int i=0;i<7;i++){
        myStack.push(i);
    }
    REQUIRE( myStack.getSize() == 10 );
    for(int i=0;i<27;i++){
        myStack.push(i);
    }
    REQUIRE( myStack.getSize() == 40 );
}



