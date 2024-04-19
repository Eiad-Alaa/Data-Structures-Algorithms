#include <bits/stdc++.h>
using namespace std;

#include "insertion.cpp"

Node* search(Node* root ,int data){
    if (root == NULL || root->data == data) return root;
    
    if (root->data < data) {
        return search(root->left, data);
    }

    return search(root->right, data);
}


