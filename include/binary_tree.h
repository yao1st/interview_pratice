//
// Created by senseadmin on 18-7-4.
//

#ifndef INTERVIEW_BINARY_TREE_H
#define INTERVIEW_BINARY_TREE_H

#include <iostream>
#include <queue>
struct BinaryTreeNode {
    int value;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

class BinaryTree{
public:
    BinaryTreeNode *root;
    int *pre_order;
    int *in_order;
    int length;
    int depth;

    BinaryTree();

    void initTreeByPreOrderAndInOrder();

    BinaryTreeNode* constructTree(int *pre_order_start, int *pre_order_end, int *in_order_start, int *in_order_end);

    void printPreOrder(BinaryTreeNode *current_node);

    void printByLine();

    int getDepth(BinaryTreeNode* root);

    bool isBalancedTree();
};

#endif //INTERVIEW_BINARY_TREE_H
