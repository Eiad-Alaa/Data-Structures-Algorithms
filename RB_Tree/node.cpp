#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *parent;
    Node *left;
    Node *right;
    char color;

    Node(int x): data(x), parent(NULL), left(NULL), right(NULL), color('r'){}
};

struct RBTree{
    Node* root;
    RBTree(): root(NULL){}
};