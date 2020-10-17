#include <iostream>
#include "node.h"
using namespace std;

Node* populateTree(Node* root){

        string array1[] = {"10","20","30","40","50","25"};
        string array2[] = {"D","B","F","A","C","E","G"};
        string array3[] = {"aligator","bear","cat","dog","eel","fox","goat"};
        string array4[] = {"Q","W","E","R","T","Y","U","I","O","P"};

        for (int i = 0; i < 10; i++){
                root = root->insert(root, array4[i]);
        }   

        return root;
}

int main(){

        Node* root = nullptr;

        // constructing tree given in the above figure
        root = populateTree(root);

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