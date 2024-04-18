#include <bits/stdc++.h>
using namespace std;

#include "insertion.cpp"

Node* search(Node* root ,int data){
    if(root == NULL || root->data == data) return root;

    Node* left = search(root->left, data);
    Node* right = search(root->right, data);

    if(left == NULL) return right;
    return left;
}


