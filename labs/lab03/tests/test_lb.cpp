#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() -     only do this in one cpp file

#include "../LinkedBag.h"
#include "catch.hpp"

// Test linked bag 
TEST_CASE( "### 1 - Linked Bag ###", "[test1]" ) {
    LinkedBag <int> theBag;
    for(int i=1;i<6;i++){
        theBag.add(i);
        REQUIRE( theBag.getCurrentSize() == i )
    }
    //std::vector<int> v1 = {1,2,3,4,5};
    std::vector<int> v1 = {5,4,3,2,1};
    REQUIRE( theBag.toVector() == v1 );
    REQUIRE( theBag.getCurrentSizeRecursive()== 5 );
    REQUIRE( theBag.getCurrentSizeIterative()== 5 );
    REQUIRE( theBag.getCurrentSize()== 5 );

    theBag.add(3);
    theBag.addEnd(3);

    REQUIRE( theBag.getFrequencyOfRecursive(3)== 3 );
    REQUIRE( theBag.getCurrentSizeRecursive()== 7 );
    REQUIRE( theBag.getCurrentSizeIterative()== 7 );
    REQUIRE( theBag.getCurrentSize()== 7 );
}
