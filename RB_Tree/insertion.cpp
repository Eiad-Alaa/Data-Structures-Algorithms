#include <bits/stdc++.h>
using namespace std;

#include "rotation.cpp"


Node* insert_traverse(Node *root, Node *node)
{
    if (root == NULL)
    {
        return node;
    }
    node->parent = root;
    if (node->data > root->data)
    {
        root->right = insert_traverse(root->right, node);
    }
    else if(node->data < root->data)
    {
        root->left = insert_traverse(root->left, node);
    }
    return root;
}

void insertion_fix(RBTree *tree, Node *node)
{
    Node *uncle;
    while(tree->root != node && node->parent->color == 'R')
    {
        if (node->parent == node->parent->parent->left)
        {
            uncle = node->parent->parent->right;
            if (uncle != NULL && uncle->color == 'R') // case1
            {
                node->parent->color = 'B';
                uncle->color = 'B';
                node->parent->parent->color = 'R';
                node = node->parent->parent;
            }
            else if (node == node->parent->right) // case2 triangle  lr
            {
                node = node->parent;
                left_rotate(tree,node);
            }
            else // case3 line   ll
            {
                node->parent->color = 'B';
                node->parent->parent->color = 'R';
                right_rotate(tree,node->parent->parent);
            }
        }
        else
        {
            uncle = node->parent->parent->left;
            if (uncle != NULL && uncle->color == 'R') // case1
            {
                node->parent->color = 'B';
                uncle->color = 'B';
                node->parent->parent->color = 'R';
                node = node->parent->parent;
            }
            else if (node == node->parent->left) // case2 triangle  rl
            {
                node = node->parent;
                right_rotate(tree,node);
            }
            else // case3 line rr
            {
                node->parent->color = 'B';
                node->parent->parent->color = 'R';
                left_rotate(tree,node->parent->parent);
            }
        }
    }
    tree->root->color = 'B';
}


void insert(RBTree* tree,int data)
{
    Node* node = new Node(data);
    tree->root = insert_traverse(tree->root,node);
    insertion_fix(tree,node);
}