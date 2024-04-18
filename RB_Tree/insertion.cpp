#include <bits/stdc++.h>
using namespace std;

#include "node.cpp"
#include "rotation.cpp"


Node* insert_traverse(Node *root, Node *node)
{
    if (root == NULL)
    {
        return node;
    }

    if (node->data > root->data)
    {
        root->right = insert_traverse(root->right, node);
    }
    else
    {
        root->left = insert_traverse(root->left, node);
    }

    return root;
}

void insertion_fix(RBTree *tree, Node *node)
{
    Node *uncle;
    while (node->parent->color == 'r' && tree->root != node)
    {
        if (node->parent == node->parent->parent->left)
        {
            uncle = node->parent->parent->right;
            if (uncle->color == 'r') // case1
            {
                node->parent->color = 'b';
                uncle->color = 'b';
                node->parent->parent->color = 'r';
                node = node->parent->parent;
            }
            else if (node == node->parent->right) // case2 triangle  lr
            {
                node = node->parent;
                left_rotate(tree, node);
            }
            else // case3 line   ll
            {
                node->parent->color = 'b';
                node->parent->parent->color = 'r';
                right_rotate(tree, node->parent->parent);
            }
        }
        else
        {
            uncle = node->parent->parent->left;
            if (uncle->color == 'r') // case1
            {
                node->parent->color = 'b';
                uncle->color = 'b';
                node->parent->parent->color = 'r';
                node = node->parent->parent;
            }
            else if (node == node->parent->left) // case2 triangle  rl
            {
                node = node->parent;
                right_rotate(tree, node);
            }
            else // case3 line rr
            {
                node->parent->color = 'b';
                node->parent->parent->color = 'r';
                left_rotate(tree, node->parent->parent);
            }
        }
    }
    tree->root->color = 'b';
}


void insert(RBTree* tree,int data)
{
    Node* node = new Node(data);
    tree->root = insert_traverse(tree->root,node);
    insertion_fix(tree,node);
}