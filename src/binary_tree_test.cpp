//
// Created by senseadmin on 18-7-4.
//
#include <iostream>
#include "binary_tree.h"

int main()
{
    BinaryTree binaryTree;
////    ordinary binary tree
//    int pre_order[] = {1, 2, 4, 7, 3, 5, 6, 8};
//    int in_order[] = {4, 7, 2, 1, 5, 3, 8, 6};
//    balanced binary tree
    int pre_order[] = {1, 2, 4, 5, 7, 3, 6};
    int in_order[] = {4, 2, 7, 5, 1, 3, 6};

    if (sizeof(pre_order) / sizeof(pre_order[0]) != sizeof(in_order) / sizeof(in_order[0]))
        throw "Invalid Input!\n";
    binaryTree.length = sizeof(pre_order) / sizeof(pre_order[0]);
    binaryTree.pre_order = pre_order;
    binaryTree.in_order = in_order;
    binaryTree.initTreeByPreOrderAndInOrder();
    binaryTree.printPreOrder(binaryTree.root);
    binaryTree.printByLine();
    binaryTree.depth = binaryTree.getDepth(binaryTree.root);
    std::cout << "\n************ Tree Depth **************\n" << binaryTree.depth << std::endl;
    std::cout << "\n Is Balanced? \n" << (binaryTree.isBalancedTree() ? "yes\n" : "no\n") << std::endl;
    return 0;
}
