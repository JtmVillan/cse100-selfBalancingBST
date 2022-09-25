/*
 * Name: CSE 100 Staff
 * Email: cs100sp22@ucsd.edu
 *
 * Sources Used: None.
 *
 * This file is a tester file for CSE 100 PA3 in Spring 2022.
 * It tests whether balanceFactors returns the correct map for the example tree
 * given in the BinaryTree.h file.
 */

/* Macro to explicity print tests that are run along with colorized result. */
#define TEST(EX) (void)((fprintf(stdout, "(%s:%d) %s:", __FILE__, __LINE__,\
                 #EX)) && ((EX && fprintf(stdout, "\t\x1b[32mPASSED\x1b[0m\n"))\
                 || (fprintf(stdout, "\t\x1b[31mFAILED\x1b[0m\n")) ))

#include "BinaryTree.h"

typedef BinaryTree::Node Node;

/**
 * Test the example tree in the BinaryTree.h file.
 */
void testExampleTree() {
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    node2->parent = node1;
    node1->leftChild = node2;

    Node *node6 = new Node(6);
    node6->parent = node1;
    node1->rightChild = node6;

    Node *node5 = new Node(5);
    node5->parent = node2;
    node2->leftChild = node5;

    Node *node3 = new Node(3);
    node3->parent = node2;
    node2->rightChild = node3;

    Node *node4 = new Node(4);
    node4->parent = node3;
    node3->rightChild = node4;

    auto tree = BinaryTree(node1);
    auto factors = tree.balanceFactors();
    for (auto pair: factors) {
        cout << pair.first << '\t' << pair.second << endl;
    }

    tree.newick();

    TEST(factors.size() == 6);
    TEST(factors[1] == -2);
    TEST(factors[2] == 1);
    TEST(factors[3] == 1);
    TEST(factors[4] == 0);
    TEST(factors[5] == 0);
    TEST(factors[6] == 0);
}

/**
 * Run our test cases.
 */
int main() {
    testExampleTree();
    return 0;
}

