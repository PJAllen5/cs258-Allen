#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() -     only do this in one cpp file

#include "../DoubleLinkNode.h"
#include "catch.hpp"

TEST_CASE("DoubleLinkNode"){
    DoubleLinkNode<int> *n1 = new DoubleLinkNode<int>(1);
    DoubleLinkNode<int> *n2 = new DoubleLinkNode<int>(2);
    n1->setNext(n2);
    n2->setPrev(n1);
    REQUIRE(n1->getNext()->getItem() == 2);
    REQUIRE(n1->getItem() == 1);
    n1->setItem(3);
    REQUIRE(n1->getItem() == 3);
    REQUIRE(n2->getPrev()->getItem() == 3);

    n1->setNext(nullptr);
    REQUIRE(n1->getNext() == nullptr);
    n2->setPrev(nullptr);
    REQUIRE(n2->getPrev() == nullptr);
    delete n1;
    delete n2;
}
