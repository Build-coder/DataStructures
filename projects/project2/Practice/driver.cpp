#include <iostream>
#include "node.h"
using namespace std;

int main(){

    Node* root = nullptr;

    // constructing tree given in the above figure
    root = root->insert(root, 10);
    root = root->insert(root, 20);
    root = root->insert(root, 30);
    root = root->insert(root, 40);
    root = root->insert(root, 50);
    root = root->insert(root, 25);


    // Preorder
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    
    root->preOrder(root);
    cout << endl << endl;


    // Inorder
    cout << "Inorder traversal of the "
            "constructed AVL tree is \n";
    
    root->inOrder(root);
    cout << endl << endl;


    // Postorder
    cout << "Postorder traversal of the "
    "constructed AVL tree is \n";

    root->postOrder(root);
    cout << endl << endl;


    return 0;
}