#include "wordTree.h"

WordTree::~WordTree(){
    /***********************************
     *      To be implemented
     * ********************************/
}

void WordTree::updateHeight(Node *aNode) {
   /***********************************
     *      To be implemented
     * ********************************/
}

void WordTree::clearTree(Node* aNode){
    /***********************************
     *      To be implemented
     * ********************************/
}

void WordTree::inOrder(Node* aNode, std::ostream& ostr){
    /***********************************
     *      Do not modify
     * ********************************/
    if (aNode != nullptr){
        ostr << "[";
        inOrder(aNode->_left, ostr);
        ostr << aNode->_value << ":" << aNode->_count << ":" << aNode->_height;
        inOrder(aNode->_right, ostr);
        ostr << "]";
    }
}

Node* WordTree::find(Node* aNode, const string& element){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/
    return nullptr;
}
Node* WordTree::find(const string& element){
    /***********************************
     *      To be implemented
     * ********************************/

    return nullptr;
}

Node* WordTree::leftRotation(Node* x){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/

    Node* y = x->_right;
    Node* T2 = y->_left;

    // perform rotation
    y->_left = x;
    x->_right = T2;

    // update getHeights
    x->_height = max(x->_left->_height, x->_right->_height) + 1;
    y->_height = max(y->_left->_height, y->_right->_height) + 1;

    // return new root
    return y;
}

Node* WordTree::rightRotation(Node* y){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/


    Node* x = y->_left;
    Node* T2 = x->_right;

    // perform rotation
    x->_right = y;
    y->_left = T2;

    // update heights
    y->_height = max(y->_left->_height, y->_right->_height) + 1;
    x->_height = max(x->_left->_height, x->_right->_height) + 1;

    // return new root
    return x;
}

int WordTree::checkBalance(Node* N){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/

    if (N == nullptr){ return 0; }
    
    return N->_left->_height - N->_right->_height;
}

Node* WordTree::reBalance(Node* aNode){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/
    return nullptr;
}

void WordTree::insert(const string& element){
    /***********************************
     *      To be implemented
     * ********************************/
    Node* node;

    node = insert(element, _root);


     // update getHeight of ancestor node
    node->_height = 1 + max(node->_left->_height, node->_right->_height);

    // get balance factor for ancestor node to check whether node became
    // unbalanced

    int balance = checkBalance(node);

    // if node became unbalanced, then there are 4 cases
    
    // left left case
    if (balance > 1 && node->_value < node->_left->_value) { 
        rightRotation(node); 
    }

    // right right case
    if (balance < -1 && node->_value > node->_right->_value) { 
        leftRotation(node); 
    }

    // left right case
    if (balance > 1 && node->_value > node->_left->_value) {
        node->_left = leftRotation(node->_left);
        rightRotation(node);
    }

    // right left case
    if (balance < -1 && node->_value < node->_right->_value){
        node->_right = rightRotation(node->_right);
        leftRotation(node);
    }

    // return the (unchanged) node pointer
    return;

}
Node* WordTree::insert(const string& key, Node*& node){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/

    // perform normal insertion
    if (node == nullptr){
        Node* newNode = new Node(key);
        node = newNode;
    }

    if (key < node->_value){ 
        node->_left = insert(node->_value, node); 
    } else if (key > node->_value){ 
        node->_right = insert(node->_value, node); 
    } else { return node; }
}

void WordTree::dump(std::ostream& ostr){
    /***********************************
     *      Do not modify
     * ********************************/
    inOrder(_root, ostr);
}

int WordTree::searchCount(string word){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/
    return 0;
}

int WordTree::searchCountHelp(Node* aNode, string word, int counter){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/
    return 0;
}

int WordTree::getRootHeight(){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/
    return 0;
}

int WordTree::getNodeHeight(string word){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/

    return 0;
}

int WordTree::getNodeHeightHelp(Node* aNode, string word){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/

    return aNode->_height;
}

