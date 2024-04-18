#include <bits/stdc++.h>
using namespace std;

#include "node.cpp"

void left_rotate(RBTree* tree,Node* node)
{
    Node* r = node->right;
    node->right = r->left;
    if(r->left)
    {
        r->left->parent = node;
    }
    r->parent = node->parent;
    if(node->parent == NULL)
    {
        tree->root = r;
    }
    else if(node == node->parent->left)
    {
        node->parent->left = r;
    }
    else
    {
        node->parent->right = r;
    }
    r->left = node;
    node->parent = r;
}

void right_rotate(RBTree* tree,Node* node)
{
    Node* l = node->left;
    node->left = l->right;

    if(l->right)
    {
        l->right->parent = node;
    }
    l->parent = node->parent;
    if(node->parent == NULL)
    {
        tree->root = l;
    }
    else if(node == node->parent->left)
    {
        node->parent->left = l;
    }
    else
    {
        node->parent->right = l;
    }
    l->right = node;
    node->parent = l;
}