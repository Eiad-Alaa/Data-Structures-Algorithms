#include <bits/stdc++.h>

using namespace std;

struct Node {
    string data;
    Node *parent;
    Node *left;
    Node *right;
    char color;

    Node(string x) : data(x), parent(NULL), left(NULL), right(NULL), color('R') {}
};

struct RBTree {
    Node *root;

    RBTree() : root(NULL) {}
};

void toLower(string& s) {
    for (int i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }
}

void left_rotate(RBTree *tree, Node *node) {
    Node *r = node->right;
    node->right = r->left;
    if (r->left) {
        r->left->parent = node;
    }
    r->parent = node->parent;
    if (node->parent == NULL) {
        tree->root = r;
    } else if (node == node->parent->left) {
        node->parent->left = r;
    } else {
        node->parent->right = r;
    }
    r->left = node;
    node->parent = r;
}

void right_rotate(RBTree *tree, Node *node) {
    Node *l = node->left;
    node->left = l->right;

    if (l->right) {
        l->right->parent = node;
    }
    l->parent = node->parent;
    if (node->parent == NULL) {
        tree->root = l;
    } else if (node == node->parent->left) {
        node->parent->left = l;
    } else {
        node->parent->right = l;
    }
    l->right = node;
    node->parent = l;
}

Node *insert_traverse(Node *root, Node *node) {
    if (root == NULL) {
        return node;
    }
    node->parent = root;
    if (node->data > root->data) {
        root->right = insert_traverse(root->right, node);
    } else if (node->data < root->data) {
        root->left = insert_traverse(root->left, node);
    }
    return root;
}

void insertion_fix(RBTree *tree, Node *node) {
    Node *uncle;
    while (tree->root != node && node->parent->color == 'R') {
        if (node->parent == node->parent->parent->left) {
            uncle = node->parent->parent->right;
            if (uncle != NULL && uncle->color == 'R') // case1
            {
                node->parent->color = 'B';
                uncle->color = 'B';
                node->parent->parent->color = 'R';
                node = node->parent->parent;
            } else if (node == node->parent->right) // case2 triangle  lr
            {
                node = node->parent;
                left_rotate(tree, node);
            } else // case3 line   ll
            {
                node->parent->color = 'B';
                node->parent->parent->color = 'R';
                right_rotate(tree, node->parent->parent);
            }
        } else {
            uncle = node->parent->parent->left;
            if (uncle != NULL && uncle->color == 'R') // case1
            {
                node->parent->color = 'B';
                uncle->color = 'B';
                node->parent->parent->color = 'R';
                node = node->parent->parent;
            } else if (node == node->parent->left) // case2 triangle  rl
            {
                node = node->parent;
                right_rotate(tree, node);
            } else // case3 line rr
            {
                node->parent->color = 'B';
                node->parent->parent->color = 'R';
                left_rotate(tree, node->parent->parent);
            }
        }
    }
    tree->root->color = 'B';
}

void insert(RBTree *tree, string data) {
    Node *node = new Node(data);
    tree->root = insert_traverse(tree->root, node);
    insertion_fix(tree, node);
}

Node *search(Node *root, string data) {
    if (root == NULL || root->data == data) return root;
    
    if (root->data < data) {
        return search(root->left, data);
    }

    return search(root->right, data);
}

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

void insert_dict(RBTree *tree, string word) {
    Node *root = tree->root;
    toLower(word);
    if (!search(root, word)) {
        insert(tree, word);

        ofstream file("dictionary.txt", ios::app);
        file << word << endl;
        file.close();

        cout << "Height: " << printHeight(root) << endl;
        cout << "Black Height: " << printBlackHeight(root) << endl;
        cout << "Dictionary's Size: " << printSize(root) << endl << endl;
    } else {
        cout << "ERROR: Word already in the dictionary!" << endl << endl;
    }
}

void load_dict(RBTree *tree) {
    ifstream file("dictionary.txt");

    string word;
    while (getline(file, word)) {
        toLower(word);
        if (!search(tree->root, word))
            insert(tree, word);
    }

    file.close();

    cout << "Dictionary loaded successfully!" << endl;
    cout << "Height: " << printHeight(tree->root) << endl;
    cout << "Black Height: " << printBlackHeight(tree->root) << endl;
    cout << "Dictionary's Size: " << printSize(tree->root) << endl << endl;

}

void search_dict(RBTree *tree, string word) {
    Node* root = tree->root;
    toLower(word);
    if (search(root, word)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    RBTree *tree = new RBTree();
    load_dict(tree);

    while (true) {
        cout << "1. Insert Word" << endl;
        cout << "2. Search for Word" << endl << endl;

        string response;
        cout << ">> ";
        cin >> response;
        cout << endl;

        if (response == "1") {      // insert
            string word;
            cout << ">> ";
            cin >> word;
            cout << endl;

            insert_dict(tree, word);
        } else if (response == "2") {
            string word;
            cout << ">> ";
            cin >> word;
            cout << endl;

            search_dict(tree, word);
        } else {
            cout << "Please choose a valid option!" << endl << endl;
            continue;
        }
    }

    return 0;
}