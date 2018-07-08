//
// Created by senseadmin on 18-7-4.
//
#include "binary_tree.h"
BinaryTree::BinaryTree()
{
    this->root = NULL;
    this->pre_order = NULL;
    this->in_order = NULL;
    this->length = 0;
}

void BinaryTree::initTreeByPreOrderAndInOrder()
{
    std::cout << "construct tree...\n";

    if (this->pre_order == NULL || this->in_order == NULL)
        throw "Invalid input!\n";

    this->root = this->constructTree(this->pre_order, this->pre_order+this->length-1, this->in_order, this->in_order+this->length-1);
}


BinaryTreeNode* BinaryTree::constructTree(int *pre_order_start, int *pre_order_end, int *in_order_start,
                                          int *in_order_end)
{
    int root_value = *pre_order_start;
    BinaryTreeNode *root = new BinaryTreeNode();
    root->value = root_value;
    root->left = NULL;root->right = NULL;

    if (pre_order_start == pre_order_end)
    {
        if (in_order_start == in_order_end && *pre_order_start == *in_order_start)
            return root;
        else
            throw "Invalid input!\n";
    }

    int *root_in_order = in_order_start;
    while (root_in_order <= in_order_end && *root_in_order != root_value)
        ++root_in_order;
    if (root_in_order == in_order_end && *root_in_order != root_value)
        throw "Invalid input!\n";

    int left_length = root_in_order - in_order_start;

    if (left_length > 0)
    {
        root->left = this->constructTree(pre_order_start + 1, pre_order_start+1 +left_length-1, in_order_start, root_in_order - 1);
    }
    if (left_length < pre_order_end - pre_order_start + 1 - 1)
    {
        root->right = this->constructTree(pre_order_start+1 + left_length-1 +1, pre_order_end, root_in_order + 1, in_order_end);
    }

    return root;
}

void BinaryTree::printPreOrder(BinaryTreeNode *current_node)
{
    if (current_node == NULL)
        return;
    std::cout << current_node->value << '\t';
    if (current_node->left != NULL)
        this->printPreOrder(current_node->left);
    if (current_node->right != NULL)
        this->printPreOrder(current_node->right);
}
void BinaryTree::printByLine()
{
    std::cout << "\n ************ Print Binary Tree By Line ***************\n";
    if (this->root == NULL)
        throw "Empty Tree";
    BinaryTreeNode *current_node = this->root;
    int current_layer = 1;
    int next_layer = 0;
    std::queue<BinaryTreeNode *> queue;
    queue.push(current_node);
    while (!queue.empty())
    {
        if (current_layer > 0)
        {
            current_node = queue.front();

            if (current_node->left != NULL)
            {
                queue.push(current_node->left);
                next_layer ++;
            }


            if (current_node->right != NULL)
            {
                queue.push(current_node->right);
                next_layer ++;
            }

            std::cout << current_node->value << '\t';

            queue.pop();
            current_layer --;
        }
        else
        {
            current_layer = next_layer;
            next_layer = 0;
            std::cout << std::endl;
        }


    }

}

int BinaryTree::getDepth(BinaryTreeNode *root)
{
    if (root == NULL)
        return 0;

    int left_child_depth = this->getDepth(root->left);
    int right_child_depth = this->getDepth(root->right);

    return (left_child_depth > right_child_depth) ? (left_child_depth + 1) : (right_child_depth + 1);
}

bool isBalancedTreeCore(BinaryTreeNode *p_root, int *depth)
{
    if (p_root == NULL)
    {
        *depth = 0;
        return true;
    }

    int left, right;
    if (isBalancedTreeCore(p_root->left, &left) && isBalancedTreeCore(p_root->right, &right))
    {
        int depth_diff = left - right;
        if (depth_diff <= 1 && depth_diff >= -1)
        {
            *depth = (left > right) ? (left + 1) : (right + 1);
            return true;
        }
    }
    return false;
}

bool BinaryTree::isBalancedTree()
{
    int depth = 0;
    return isBalancedTreeCore(this->root, &depth);
}