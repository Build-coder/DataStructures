#include <iostream>
#include "node.h"
using namespace std;

// if a > b, return a, otherwise return b
int Node::max(int a, int b) { return (a > b) ? a : b; }

// utility function to get height of tree
int Node::getHeight(Node* N){

    if (N == nullptr) { return 0; }
    return N->height;
}

Node* Node::newNode(int key){

    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;

    return(node);
}

Node* Node::rightRotate(Node* y){

    Node* x = y->left;
    Node* T2 = x->right;

    // perform rotation
    x->right = y;
    y->left = T2;

    // update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // return new root
    return x;
}

Node* Node::leftRotate(Node* x){

    Node* y = x->right;
    Node* T2 = x->left;

    // perform rotation
    y->left = x;
    x->right = T2;

    // update getHeights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // return new root
    return y;
}

int Node::getBalance(Node* N){


    if (N == nullptr){ return 0; }
    
    return getHeight(N->left) - getHeight(N->right);
}

Node* Node::insert(Node* node, int key){

    // perform normal insertion
    if (node == nullptr){ return(newNode(key)); }
    if (key < node->key){ node->left = insert(node->left, key); }
    else if (key > node->key){ node->right = insert(node->right, key); }
    else { return node; }

    // update getHeight of ancestor node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // get balance factor for ancestor node to check whether node became
    // unbalanced

    int balance = getBalance(node);

    // if node became unbalanced, then there are 4 cases
    
    // left left case
    if (balance > 1 && key < node->left->key) { return rightRotate(node); }

    // right right case
    if (balance < -1 && key > node->right->key) { return leftRotate(node); }

    // left right case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // right left case
    if (balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // return the (unchanged) node pointer
    return node;
}

// Utility function to print preorder traversal
// of the tree. The function also prints getHeight
// of every node
void Node::preOrder(Node* root){
    if (root != nullptr){
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
} 