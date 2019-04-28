#include <iostream>
#include <cmath>
using namespace std;

class Node
{
public:
    Node *left, *right;
    int value;

    Node(int value)
    {
        this->left = NULL;
        this->right = NULL;
        this->value = value;
    }

    ~Node()
    {
        this->left = NULL;
        this->right = NULL;
        int value = NULL;
    }
};

class BST
{
public:
    Node *root;

    BST()
    {
        this->root = NULL;
    }

    Node *insertValue(int value)
    {
        Node *node = this->insert(value, this->root);
        if (this->root == NULL)
            this->root = node;
    }
    Node *insert(int value, Node *node)
    {
        if (node == NULL)
            return new Node(value);
        if (node->value > value)
        {
            node->left = this->insert(value, node->left);
        }
        else
        {
            node->right = this->insert(value, node->right);
        }
    }
    void printInorder()
    {
        this->inorder(this->root);
    }
    Node *inorder(Node *node)
    {
        if (node != NULL)
        {
            this->inorder(node->left);
            printf("%d ", node->value);
            this->inorder(node->right);
        }
    }
    void printPreorder()
    {
        this->preorder(this->root);
    }
    Node *preorder(Node *node)
    {
        if (node != NULL)
        {
            printf("%d ", node->value);
            this->inorder(node->left);
            this->inorder(node->right);
        }
    }
    void printPostorder()
    {
        this->postorder(this->root);
    }
    Node *postorder(Node *node)
    {
        if (node != NULL)
        {
            this->inorder(node->left);
            this->inorder(node->right);
            printf("%d ", node->value);
        }
    }
};

bool isBST(Node *node)
{

    if (node == NULL)
        return true;
    Node *left = node->left;
    Node *right = node->right;

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

int main()
{
    BST n;
    n.insertValue(50);
    n.insertValue(30);
    n.insertValue(20);
    n.insertValue(40);
    n.insertValue(70);
    n.insertValue(60);
    n.insertValue(80);
    cout << "IS BST " << isBST(n.root) <<endl;
    n.printInorder();
    cout << endl;
    n.printPreorder();
    cout << endl;
    n.printPostorder();
}
