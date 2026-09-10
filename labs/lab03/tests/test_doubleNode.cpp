#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() -     only do
                           // this in one cpp file

#include "../DoubleLinkNode.h"
#include "catch.hpp"

TEST_CASE("DoubleLinkNode")
{
    DoubleLinkNode<int>* n1 = new DoubleLinkNode<int>(1);
    DoubleLinkNode<int>* n2 = new DoubleLinkNode<int>(2);
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

// ---------------------------------------------------------------------------
// A new node must not point anywhere yet.  Your constructor is responsible for
// setting BOTH next and prev to nullptr.
//
// Testing that is harder than it looks, and the first few lines of this test
// exist only to make it possible.  Here is why.
//
// If a constructor forgets to initialise a pointer member, that member is left
// holding whatever bytes already happened to be sitting in that piece of
// memory.  Reading such a pointer is *undefined behaviour*: the C++ standard
// places no requirement on what happens, which includes the unhelpful
// possibility that the program appears to work perfectly.
//
// In practice, the first time a program asks the operating system for memory,
// it is given pages that have been filled with zeros.  The OS does this for
// security, so that one program can never read the leftover data of another.
// The practical consequence for us is that an uninitialised pointer in a young
// program very often reads as nullptr purely by accident.  A test that simply
// constructed a node and checked its pointers would therefore PASS an
// implementation whose constructor initialises nothing at all - which makes
// the test worse than useless, because it looks like coverage.
//
// The three lines below prevent that:
//
//   1. allocate a node,
//   2. deliberately store a non-null value in both of its pointers,
//   3. delete it.
//
// Deleting does not erase anything.  It returns that block of memory to the
// allocator's free list with our non-null bytes still sitting inside it, and
// the next request for a node of the same size is handed that same block back.
//
// So when the real node is constructed on the line after that:
//
//   - a correct constructor overwrites those bytes with nullptr -> test passes
//   - a forgetful one inherits the recycled non-null bytes      -> test fails
//
// One honest caveat: this is a practical trick, not a proof.  Undefined
// behaviour is undefined, and a different compiler, allocator, or platform
// could behave differently.  It is reliable enough on Linux with g++ to be
// worth doing, and the lesson it is teaching - initialise your pointers, and
// never rely on what uninitialised memory happens to contain - is not
// platform specific at all.
// ---------------------------------------------------------------------------
TEST_CASE("DoubleLinkNode - a new node points nowhere")
{
    // deliberately leave non-null bytes in a block the allocator will reuse
    DoubleLinkNode<int>* warm = new DoubleLinkNode<int>(42);
    warm->setNext(warm);
    warm->setPrev(warm);
    delete warm;

    // this node lands in the memory we just dirtied

    DoubleLinkNode<int>* n = new DoubleLinkNode<int>(1);
    REQUIRE(n->getNext() == nullptr);
    REQUIRE(n->getPrev() == nullptr);
    delete n;
}

// next and prev are two SEPARATE pointers.  The middle node of a three node
// chain points forward and backward at the same time, to different nodes.
TEST_CASE("DoubleLinkNode - next and prev are independent")
{
    DoubleLinkNode<int>* n1 = new DoubleLinkNode<int>(1);
    DoubleLinkNode<int>* n2 = new DoubleLinkNode<int>(2);
    DoubleLinkNode<int>* n3 = new DoubleLinkNode<int>(3);

    n1->setNext(n2);
    n2->setPrev(n1);
    n2->setNext(n3);
    n3->setPrev(n2);

    // the middle node holds both links at once
    REQUIRE(n2->getPrev()->getItem() == 1);
    REQUIRE(n2->getNext()->getItem() == 3);

    // walk the whole chain forward, then all the way back
    REQUIRE(n1->getNext()->getNext()->getItem() == 3);
    REQUIRE(n3->getPrev()->getPrev()->getItem() == 1);

    // the ends still point nowhere
    REQUIRE(n1->getPrev() == nullptr);
    REQUIRE(n3->getNext() == nullptr);

    delete n1;
    delete n2;
    delete n3;
}
