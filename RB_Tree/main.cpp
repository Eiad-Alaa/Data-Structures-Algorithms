#include <bits/stdc++.h>
using namespace std;

#include "search.cpp"

int main()
{
    RBTree* mytree = new RBTree(); 
    for(int i = 0 ; i < 17 ; i++){
        insert(mytree, i+2);
    }

    cout<< "root->left->data: " << mytree->root->left->data << endl;
    
    for(int i = 0 ; i < 17 ; i++){
        Node* found = search(mytree->root, i);
        cout << i << (found? " exists" : " does not exist") << endl;
    }
    

    return 0;
}


