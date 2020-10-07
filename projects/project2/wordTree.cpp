#include "wordTree.h"

/************************************
 * Constructor initializes an object
 * 
 * Note: The implementation of this
 *       function is provided to you.
 *       You do not need to modify it.
 * 
 *       (Implemented in the .h file)
 * *********************************/


WordTree::~WordTree(){
    /***********************************
     *      To be implemented
     * 
     * Destructor deallocates all 
     * dynamically created memory
     * ********************************/
}

void WordTree::updateHeight(Node *aNode) {
   /***********************************
     *      To be implemented
     * 
     * This function recalculates and 
     * updates the height of aNode
     * 
     * Note: The children which are nullptr
     *       hold a height of -1. The
     *       lowest level nodes with a key
     *       value hold the height of 0
     * ********************************/
}

void WordTree::clearTree(Node* aNode){
    /***********************************
     *      To be implemented
     * 
     * This function deallocates all 
     * memory in the AVL tree recursively
     * ********************************/
}

void WordTree::inOrder(Node* aNode, std::ostream& ostr){
    /***********************************
     *      Do not modify
     * 
     * This function prints out the contents
     * of the AVL tree using in-order traversal.
     * The default output for the function is 
     * the standard output (std::cout).
     * 
     * Note: The implementation for this function
     *       is provided. You do not need to modify
     *       it.
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
     * 
     * This is a helper function which
     * recursively looks for element and
     * returns it if element is found
     * ********************************/
    return nullptr;
}
Node* WordTree::find(const string& element){
    /***********************************
     *      To be implemented
     * 
     * This function finds a node using 
     * the provided key and returns the node
     * ********************************/
}

Node* WordTree::leftRotation(Node* aNode){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * 
     * This function performs left rotation
     * around aNode and returns the new root
     * for the current sub-tree
     * ********************************/
    return nullptr;
}

Node* WordTree::rightRotation(Node* aNode){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * 
     * This function performs right rotation
     * around aNode and returns the new root
     * for the current sub-tree
     * ********************************/
    return nullptr;
}

int WordTree::checkBalance(Node* aNode){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * 
     * This function returns the height
     * difference between the left child
     * and right child of aNode. If left
     * child has greater height, it returns
     * a positive number, and if the right
     * child has a greater height then it 
     * returns a negative number
     * 
     * Note: The children which are nullptr
     *       hold a height of -1. The lowest
     *       level nodes with a key value
     *       hold a height of 0
     * ********************************/
    return 0;
}

Node* WordTree::reBalance(Node* aNode){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * 
     * This function rebalances the AVL
     * tree using the propert rotation
     * operations when the tree becomes
     * unbalanced.
     * 
     * For example, after inserting a new
     * node, we need to check whether the
     * tree becomes unbalanced. If it is 
     * unbalanced, we need to rebalance the
     * tree using this function. The function
     * returns the new root for the current
     * sub-tree.
     * ********************************/
    return nullptr;
}

void WordTree::insert(const string& element){
    /***********************************
     *      To be implemented
     * 
     * This function inserts the word in
     * the tree. Since, the tree is an AVL
     * tree, it needs to rebalance the tree
     * and recalculate heights after insertion.
     * A duplicate key is not allowed. In the 
     * case of duplicate insertion we only 
     * update the word count in the node
     * ********************************/
}
Node* WordTree::insert(const string& element, Node*& aNode){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * 
     * This is a helper function which is
     * called by the public insert(...)
     * function and inserts a new node
     * with element as key. A duplicate key
     * is not allowed. In the case of duplicate
     * insertion, we only update the word count
     * in the node
     * ********************************/
    return nullptr;
}

void WordTree::dump(std::ostream& ostr){
    /***********************************
     *      Do not modify
     * 
     * This function prints out the list
     * of all nodes in tree. The word
     * (node key) is printed along with 
     * its number of occurrences and its
     * height in the tree. The default
     * output for the function is the 
     * standard output (std::out). 
     * 
     * An example of the output is provided
     * in the Additional Requirements section
     * below. 
     * 
     * Note: The implementation for this
     *       function is provided. You do
     *       not need to modify it.
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
     * 
     * This function returns the number
     * of visited nodes in the WordTree
     * when searching for a word. It
     * starts at zero when visiting root,
     * then the path from root to its child
     * counts as one, and it continues
     * until the word is found or is not
     * found
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
     * 
     * The helper function that returns 
     * the number of visited nodes in the
     * AVL when searching for a word. It
     * starts at zero when visiting root,
     * then the path from root to its child
     * counts as one, and it continues until
     * the word is found or is not found
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
     * 
     * This function returns the height 
     * of the tree
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
     * 
     * This function returns the height
     * of the word node in the tree
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
     * 
     * The helper function that looks
     * recursively for the node with 
     * the key value word and returns 
     * its height. If the node is not 
     * found the function returns -1
     * 
     * Note: The height of null children
     *        is -1
     * ********************************/
    return 0;
}