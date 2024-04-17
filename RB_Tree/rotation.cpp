#include <bits/stdc++.h>
using namespace std;

#include "node.cpp"

Node* left_rotate(Node* node)
{
    Node* r = node->right;
    Node* lr = r->left;
    node->right = lr;
    r->left = node;
    node->parent = r;
    if(lr)
    {
        lr->parent = node;
    }
    return r;
}

Node* right_rotate(Node* node)
{
    Node* l = node->left;
    Node* rl = l->right;
    node->left = rl;
    l->right = node;
    node->parent = l;
    if(rl)
    {
        rl->parent = node;
    }
    return l;
}