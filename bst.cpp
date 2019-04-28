#include <iostream>
#include <cmath>
using namespace std;

class Node
{
public:
    Node *left, *right;
    int value;

    Node()
    {
        this->left = NULL;
        this->right = NULL;
    }
    ~Node()
    {
        this->left = NULL;
        this->right = NULL;
        int value = NULL;
    }
};

bool isBST(Node *node)
{
    Node *left = node->left;
    Node *right = node->right;

    if (node == NULL)
        return true;
    if (left != NULL && left->value > node->value)
        return false;
    if (right != NULL && right->value < node->value)
        return false;
    if (!isBST(left) || !isBST(right))
    {
        return false;
    }
    return true;
}

