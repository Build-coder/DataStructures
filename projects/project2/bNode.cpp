#include "bNode.h"


BNode::BNode(){}
/************************************
 * Constructor initializes an object 
 * 
 * Note: The implementation of this
 *       function is provided for you.
 *       You do not need to modify it.
 * *********************************/

// overloaded constructor
BNode::BNode(string key, string author, string text){
            _key = key;
            _author = author;
            _left = nullptr;
            _right = nullptr;
            _flag = false;
            createTextTree(text);
        }


BNode::~BNode(){
/***********************************
 * Destructor, no memory allocation is 
 * required in this class
 * *********************************/
    
}

// There is a private function member to 
// contruct the WordTree object
void BNode::createTextTree(string text){
    /********************************
     * This function constructs the WordTree
     * object by tokenizing text and inserting
     * the words one by one into the tree.
     * 
     * Note: The implementation for this
     * function is provided. You do not 
     * need to modify it
     * ******************************/

    istringstream iss(text);
    vector<string> tokens;
    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));

    for (std::vector<string>::iterator it = tokens.begin() ; it != tokens.end(); ++it){
        _tree.insert(*it);
    }
}

int BNode::findFrequency(string word){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * 
     * This function calls the corresponding 
     * function from WordTree class and returns
     * the word's number of occurrences.
     * 
     * If the word is not found, the function 
     * returns zero
     * ********************************/
    


    return 0;
}

int BNode::searchCount(string word){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * 
     * This function calls the corresponding
     * function from WordTree class
     * ********************************/
    return 0;
}

int BNode::getTextTreeHeight(){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * 
     * This function calls the corresponding
     * function from WordTree class
     * ********************************/
    return 0;
}

int BNode::getNodeHeight(string word){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * 
     * This function calls the corresponding
     * function from WordTree class
     * ********************************/
    return 0;
}