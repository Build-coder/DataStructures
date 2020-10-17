#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Node{

    public:

        // Node(const int& v): key(v), left(nullptr), right(nullptr), height(0){};
        int max(int a, int b);
        int getHeight(Node* N);
        Node* newNode(string key);
        Node* rightRotate(Node* y);
        Node* leftRotate(Node* x);
        int getBalance(Node* N);
        Node* insert(Node* node, string key);
        void preOrder(Node* root);
        void inOrder(Node* root);
        void postOrder(Node* root);

    private:

        string key;
        Node* left;
        Node* right;
        int height;
};

