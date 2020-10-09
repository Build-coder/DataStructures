#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Node{

    public:

        int max(int a, int b);
        int getHeight(Node* N);
        Node* newNode(int key);
        Node* rightRotate(Node* y);
        Node* leftRotate(Node* x);
        int getBalance(Node* N);
        Node* insert(Node* node, int key);
        void preOrder(Node* root);

    private:

        int key;
        Node* left;
        Node* right;
        int height;
};

