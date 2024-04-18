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

//******************************************************************************//
//print the whole tree
//******************************************************************************//

void printSpace(double n, Node* removed)
{
    for (; n > 0; n--) {
        cout << " ";
    }
    if (removed == NULL) {
        cout << ".";
    }
    else {
        if(removed->color == 'R')
            printf("\033[101m %d \033[m", removed->data); //red color
        else{
            printf("\033[100m %d \033[m", removed->data);  //black color
        }
    }
}
 
void printBinaryTree(Node* root)
{
    queue<Node*> treeLevel, temp;
    treeLevel.push(root);
    int counter = 0;
    int height = printHeight(root) - 1;
    double numberOfElements = pow(2, (height + 1)) - 1;
    while (counter <= height) {
        Node* removed = treeLevel.front();
        treeLevel.pop();
        if (temp.empty()) {
            printSpace(numberOfElements
                           / pow(2, counter + 1),
                       removed);
        }
        else {
            printSpace(numberOfElements / pow(2, counter),
                       removed);
        }
        if (removed == NULL) {
            temp.push(NULL);
            temp.push(NULL);
        }
        else {
            temp.push(removed->left);
            temp.push(removed->right);
        }
        if (treeLevel.empty()) {
            cout << endl << endl;
            treeLevel = temp;
            while (!temp.empty()) {
                temp.pop();
            }
            counter++;
        }
    }
}

//Colors reference
// void print_8_colours()
// {
//     for (int i = 0; i < 108; i++)
//     {
//         if (i % 9 == 0 && i != 0)
//             cout << endl;
//         printf("\033[%dm %3d\033[m", i, i);
//     }
// }