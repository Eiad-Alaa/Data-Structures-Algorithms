#include <bits/stdc++.h>
using namespace std;

#include "search.cpp"

int printHeight(Node* root){
    if(root == NULL) return 0;

    return 1 + max(printHeight(root->right), printHeight(root->left));
}

int printBlackHeight(Node* root){
    if(root == NULL) return 0;

    return (root->color == 'B'? 1 : 0) + printBlackHeight(root->left);
}

int printSize(Node* root){
    if(root == NULL) return 0;

    return 1 + printSize(root->right) + printSize(root->left);
}