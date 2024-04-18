#include <bits/stdc++.h>
using namespace std;

#include "print.cpp"

int main()
{
    RBTree* mytree = new RBTree(); 
    for(int i = 0 ; i < 10 ; i++){
        insert(mytree, i+2);
    }

    cout<< "root->left->data: " << mytree->root->left->data << endl;
    
    for(int i = 0 ; i < 17 ; i++){
        Node* found = search(mytree->root, i);
        cout << i << (found? " exists" : " does not exist") << endl;
    }

    cout << printHeight(mytree->root) << endl;
    cout << printBlackHeight(mytree->root) << endl;
    cout << printSize(mytree->root) << endl;
    

    return 0;
}


