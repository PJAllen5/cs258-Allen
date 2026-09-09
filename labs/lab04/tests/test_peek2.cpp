#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() -     only do this in one cpp file

#include "../StackPeek2.h"
#include "catch.hpp"


TEST_CASE( "### Peek2 ###", "[test4]" ) {
    StackPeek2<int> myStack;
    // peek2 should fail (stack size is zero), make sure
    // it throws an exception
    REQUIRE_THROWS_AS( myStack.peek2(), std::exception);
    for(int i=0;i<7;i++){
        myStack.push(i);
    }
    REQUIRE( myStack.peek2() == 5 );
    REQUIRE( myStack.peek2() == 5 );
    myStack.push(7);
    REQUIRE( myStack.peek2() == 6 );

}
