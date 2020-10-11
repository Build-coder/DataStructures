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
    clearTree(_root);
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
        if (aNode == nullptr){ return; }
        int leftHeight = -1;
        int rightHeight = -1;
        if (aNode->_left != nullptr){
            leftHeight = aNode->_left->_height;
        }
        if (aNode->_right != nullptr){
            rightHeight = aNode->_right->_height;
        }
        if (leftHeight > rightHeight){
            aNode->_height = 1 + leftHeight;
        } else{
            aNode->_height = 1 + rightHeight;
        }
}

void WordTree::clearTree(Node* aNode){
    /***********************************
     *      To be implemented
     * 
     * This function deallocates all 
     * memory in the AVL tree recursively
     * 
     * 
     * ********************************/
    if (aNode == nullptr){
        return;
    } else{
        clearTree(aNode->_left);
        clearTree(aNode->_right);
        delete aNode;
    } 
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

    return nullptr;
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
    Node* z = aNode;
    Node* y = z->_right;
    z->_right = y->_left;
    y->_left = z;
    updateHeight(z);
    updateHeight(y);

    return y;
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
    Node* z = aNode;
    Node* x = z->_left;
    z->_left = x->_right;
    x->_right = z;
    updateHeight(z);
    updateHeight(x);

    return x;
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
     * 
     * 1.) Node's left child has greater height
     * and left child of left child has a 
     * greater height - right rotation 
     * 
     * 2.) Node's right child has greater height
     * and right child of right child has a 
     * greater height
     * 
     * 3.) Node's left child has greater height
     * and right child of left child has a 
     * greater height - left rotation about 
     * node's left child, right rotation about
     * node
     * 
     * 4.) Node's right child has greater height
     * and left child of right child has a 
     * greater height - right rotation about 
     * node's right child, left rotation 
     * about node
     * ********************************/
    if (aNode == nullptr){ return -1; }

    return getNodeHeightHelp(aNode->_left, aNode->_value) 
    - getNodeHeightHelp(aNode->_right, aNode->_value);
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
    if ((checkBalance(aNode) < -1) &&
    (checkBalance(aNode->_right) <= 0)) {
        return leftRotation(aNode);

    } else if ((checkBalance(aNode) < -1)
    && (checkBalance(aNode->_right) >= 0)){
        // rotation around y
        aNode->_right = rightRotation(aNode->_right);
        // rotation around z
        return leftRotation(aNode); 
    }

    // other cases not implemented
    
    


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
     * 
     * 1.) Node's left child has greater height
     * and left child of left child has a 
     * greater height - right rotation 
     * 
     * 2.) Node's right child has greater height
     * and right child of right child has a 
     * greater height
     * 
     * 3.) Node's left child has greater height
     * and right child of left child has a 
     * greater height - left rotation about 
     * node's left child, right rotation about
     * node
     * 
     * 4.) Node's right child has greater height
     * and left child of right child has a 
     * greater height - right rotation about 
     * node's right child, left rotation 
     * about node
     * ********************************/
    int balance = 0;
    
    // call helper insert function
    _root = insert(element, _root);

    // rebalance tree
    balance = checkBalance(_root);

    // 1.) left child has greater height
    if (balance > 0){
        _root = rightRotation(_root);
        updateHeight(_root);

    // 2.) right child has greater height   
    } else if (balance < 0){
        _root = leftRotation(_root);
        updateHeight(_root);

    // need to implement left-right
    // and right-left

    // don't rebalance    
    } else{
        balance = 0;
    }
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
     * function and inserts a NEW NODE
     * with element as key. A duplicate key
     * is not allowed. In the case of duplicate
     * insertion, we only update the word count
     * in the node
     * ********************************/

    // base case
    if (aNode == nullptr){
        Node* newNode = new Node(element);
        aNode = newNode;
    // recursive call
    } else {
        if (element < aNode->_value){
            aNode->_height++;
            insert(element, aNode->_left);
        }else{
            aNode->_height++;
            insert(element, aNode->_right);
        }
    }    

    return aNode;
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
    if (aNode == nullptr){ return 0; }

    return aNode->_height;
}