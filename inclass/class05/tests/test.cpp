#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() -     only do this in one cpp file

#include "../code.hpp"
#include "../LinkedBag.h"
#include "catch.hpp"

/**
 * Test deleteNode function with a normal chain of three nodes.
 * Verifies that the second node (value 20) is deleted and the first node
 * now points directly to the third node (value 30).
 */
TEST_CASE("deleteNode - Normal case with three nodes")
{
    Node<int>* node3 = new Node<int>(30);
    Node<int>* node2 = new Node<int>(20, node3);
    Node<int>* head = new Node<int>(10, node2);

    deleteNode(head);

    REQUIRE(head->getItem() == 10);
    REQUIRE(head->getNext()->getItem() == 30);
    REQUIRE(head->getNext()->getNext() == nullptr);

    delete head->getNext();
    delete head;
}

/**
 * Test deleteNode function with a longer chain of five nodes.
 * Verifies that the second node is properly deleted from a longer chain
 * and the remaining chain maintains proper connectivity.
 */
TEST_CASE("deleteNode - Chain with many nodes")
{
    Node<int>* node5 = new Node<int>(50);
    Node<int>* node4 = new Node<int>(40, node5);
    Node<int>* node3 = new Node<int>(30, node4);
    Node<int>* node2 = new Node<int>(20, node3);
    Node<int>* head = new Node<int>(10, node2);

    deleteNode(head);

    REQUIRE(head->getItem() == 10);
    REQUIRE(head->getNext()->getItem() == 30);
    REQUIRE(head->getNext()->getNext()->getItem() == 40);
    REQUIRE(head->getNext()->getNext()->getNext()->getItem() == 50);

    delete head->getNext()->getNext()->getNext();
    delete head->getNext()->getNext();
    delete head->getNext();
    delete head;
}

/**
 * Test deleteNode function with a null head pointer.
 * Verifies that the function handles null input gracefully without crashing.
 */
TEST_CASE("deleteNode - Null head pointer")
{
    Node<int>* head = nullptr;
    deleteNode(head);
    REQUIRE(head == nullptr);
}

/**
 * Test deleteNode function with a single node chain.
 * Verifies that when there's no second node to delete, the single node
 * remains unchanged.
 */
TEST_CASE("deleteNode - Single node chain")
{
    Node<int>* head = new Node<int>(10);
    deleteNode(head);
    REQUIRE(head->getItem() == 10);
    REQUIRE(head->getNext() == nullptr);
    delete head;
}

/**
 * Test deleteNode function with exactly two nodes.
 * Verifies that the second node is deleted and the first node's
 * next pointer is set to null.
 */
TEST_CASE("deleteNode - Two node chain")
{
    Node<int>* node2 = new Node<int>(20);
    Node<int>* head = new Node<int>(10, node2);

    deleteNode(head);

    REQUIRE(head->getItem() == 10);
    REQUIRE(head->getNext() == nullptr);
    delete head;
}

/**
 * Test deleteNode function with string data type.
 * Verifies that the template function works correctly with non-integer
 * data types, specifically std::string.
 */
TEST_CASE("deleteNode - String data type")
{
    Node<std::string>* node3 = new Node<std::string>("third");
    Node<std::string>* node2 = new Node<std::string>("second", node3);
    Node<std::string>* head = new Node<std::string>("first", node2);

    deleteNode(head);

    REQUIRE(head->getItem() == "first");
    REQUIRE(head->getNext()->getItem() == "third");
    REQUIRE(head->getNext()->getNext() == nullptr);

    delete head->getNext();
    delete head;
}
