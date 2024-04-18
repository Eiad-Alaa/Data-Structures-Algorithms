#include <bits/stdc++.h>
using namespace std;

#include "insertion.cpp"

int main()
{
    RBTree* mytree = new RBTree(); 
    insert(mytree,5);
    insert(mytree,3);
    insert(mytree,4);
    cout<<mytree->root->left->data;
    return 0;
}


