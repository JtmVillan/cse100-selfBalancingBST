// implement balanceFactors here, and don't forget to add proper styles.

#include "BinaryTree.h"

// helper function to find the max height of a node's left or right subtree
int maxHeight(BinaryTree::Node *node) {
    // check if node is present
    if (node == nullptr) {
        return 0;
    }
    else {
        // find the height of each subtree
        int leftHeight = maxHeight(node->leftChild);
        int rightHeight = maxHeight(node->rightChild);
     
        // choose the longest subtree as the node's height
        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        }
        else {
          return rightHeight + 1;
        }
    }
}

// helper function for inorder traversal through tree
void inorder(unordered_map<int, int> &bfmap, BinaryTree::Node *node) {
    if (node != nullptr) {
        // traverse down the tree (in-order)
        inorder(bfmap, node->leftChild);
        inorder(bfmap, node->rightChild);
        // find the height of left and right subtree
        int rh = maxHeight(node->rightChild);
        int lh = maxHeight(node->leftChild);
        // calculate balance factor
        int bf = rh - lh;
        // map label and balance factor to map
        bfmap[node->label] = bf;
    }
    return;
}

/**
 * Implement balanceFactors() correctly
 */
unordered_map<int,int> BinaryTree::balanceFactors() {
    // if root is empty, return empty unordered map
    unordered_map<int,int> bfmap;
    if (this->root == nullptr) {
        return bfmap;
    }
    // perfromn in-order traversal and calculate bf of each Node
    // then populate bfmap with pairs of (label,bf)
    inorder(bfmap, this->root);
    return bfmap;
}


