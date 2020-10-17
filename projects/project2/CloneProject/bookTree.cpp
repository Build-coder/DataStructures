#include "bookTree.h"


BookTree::BookTree(){_root=nullptr;}
/*****************************************
 * Constructor initializes an empty object
 * 
 * Note: The implementation of this function
 *       is provided to you. You do not 
 *       need to modify it.
 * **************************************/

BookTree::~BookTree(){
	/***********************************
     *      To be implemented
     * 
     * Destructor deallocates all dynamically
     * created memory
     * ********************************/
}

BNode* BookTree::makeSplay(BNode* root, string key){
	/***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * 
     * This function performs the splay operation
     * using rotations recursively. It returns a new
     * root everytime for the current sub-tree. When
     * the recursive calls end, the returned value
     * would be the current root of the splay tree. 
     * Then, we need to set the tree root to the 
     * returned value
     * ********************************/
    return nullptr;
}
BNode* BookTree::rightRotate(BNode* x){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * 
     * This function performs the right 
     * rotation around x and returns the new 
     * root for the current sub-tree
     * ********************************/
    return nullptr;
}
BNode* BookTree::leftRotate(BNode* x){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * 
     * This function performs left rotation
     * around x and returns the new root
     * for the current sub-tree
     * ********************************/
    return nullptr;
}

bool BookTree::insert(string key, string author, string text){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * 
     * This function inserts the data for 
     * a book title into the splay tree.
     * If the title already exists, it does
     * not insert a duplicate and it returns
     * false. Otherwise it inserts the title
     * and returns true
     * ********************************/
    return true;
}
void BookTree::clear(BNode* root){
	/***********************************
     *      To be implemented
     * 
     * This function deallocates all memory
     * in the splay tree recursively
     * ********************************/
}

void BookTree::inorderHelp(BNode* root, bool verbose) const{
     /***********************************
     *      Do not modify
     * 
     * This function prints out the
     * contents of the splay tree using
     * in-order traversal. If verbose is
     * true, it also prints out the contents
     * of AVL trees. 
     * 
     * Note: The implementation for this
     *       function is provided. You do
     *       not need to modify it
     * ********************************/
    if (root != nullptr){
        if (verbose){
            cout << "(";
            inorderHelp( root->_left, verbose );
            cout << root->_key << ":" << root->_author;
			root->_tree.dump();
            inorderHelp( root->_right, verbose );
            cout << ")";
        }
        else{
            inorderHelp( root->_left, verbose );
            cout << root->_key;
            inorderHelp( root->_right, verbose );
        }
    }
}

void BookTree::dump(bool verbose) const{
     /***********************************
     *      Do not modify
     * 
     * This function prints out the contents
     * of the splay tree using in-order 
     * traversal. If verbose is true, it
     * also will dump the contents of the
     * AVL trees
     * 
     * Note: The implementation is provided.
     *       You do not need to modify it
     * ********************************/
    inorderHelp(_root, verbose);
}

int BookTree::findFrequency(string title, string word){
	/***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/
    return 0;
}

void BookTree::dumpTitle(string title){
	/***********************************
     *      To be implemented
     * 
     * The function prints out the list
     * of all nodes in the word tree of 
     * a book title. The word is printed
     * along with its number of occurrences
     * and its height in the tree.
     * 
     * An example of the output is provided
     * in the Additional Requirements section
     * below.
     * 
     * Note: This function tries to access
     *       a node in the splay tree. Then,
     *       it requires splay operation too
     * ********************************/
}

int BookTree::searchCount(string title, string word){
	/***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * 
     * This function returns the numbers of
     * visited nodes in the WordTree when
     * searching for a word. It starts at 
     * zero when visiting root, then the
     * path from root to its child counts
     * as one, and it continues until the 
     * word is found or is not found.
     * 
     * Note: This operation tries to access
     *       a node in the splay tree, then
     *       it requires splay operation too.
     *       If the title does not exist in 
     *       the splay tree, the function 
     *       returns zero, otherwise it returns
     *       the number of operations that
     *       happen in the AVL tree. This 
     *       function does not count the 
     *       number of operations in the splay
     *       tree
     * ********************************/
    return 0;
}

int BookTree::getTextTreeHeight(string title){
	/***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * 
     * This function returns the height
     * of the word tree for a book title.
     * 
     * Note: This function tries to access
     *       a node in the splay tree. Then, 
     *       it requires splay operation too
     * ********************************/
    return -1;
}
int BookTree::getWordHeight(string title, string word){
	/***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * 
     * This function returns the height
     * of the word node in the word tree
     * of a book title.
     * 
     * Note: This function tries to access
     *       a node in the splay tree. Then
     *       it requires splay operation too
     * ********************************/
    return -1;
}

string BookTree::getRootKey(){
     /***********************************
     *      Do not modify
     * 
     * This function returns the root's 
     * title of the splay tree. The
     * implementation is provided. You
     * do not need to modify this function.
     * It will be used to test the splay
     * operation. 
     * 
     * For example, after an access the 
     * root should contain the node that
     * was accessed
     * ********************************/
	return _root->_key;
}

void BookTree::loadData(string dataFile){
     /***********************************
     *      This function is implemented
     *      to help you. You should't need
     *      to modify it.
     * 
     * This function reads the data file,
     * and parses the data. It inserts the
     * data into the Splay tree.
     * 
     * Note: The implementation of this
     *       function is provided to you.
     *       You do not need to modify it
     * ********************************/
	//read the entire file at once
	std::ifstream t(dataFile);
	std::stringstream buffer;
	buffer << t.rdbuf();

	//time to parse the information
	string titleDelimiter = "<==>";
	string itemsDeleimiter = "<=>";
	string s = buffer.str();
	size_t pos = 0;
	string token;
	while ((pos = s.find(titleDelimiter)) != string::npos) {
		token = s.substr(0, pos);//token is complete data for one title
		//get the title
		int tempPos = token.find(itemsDeleimiter);
		string title = token.substr(0,tempPos);
		//convert title to lower case
		std::transform (title.begin(), title.end(), title.begin(), ::tolower);
		token.erase(0, tempPos + itemsDeleimiter.length()+1);
		//get the author
		tempPos = token.find(itemsDeleimiter);
		string author = token.substr(0,tempPos);
		//convert author to lower case
		std::transform (author.begin(), author.end(), author.begin(), ::tolower);
		token.erase(0, tempPos + itemsDeleimiter.length()+1);
		//get the text
		string text = token.substr(0,token.length() - 1);//remove last newline
		//clean up the text, remove all non-alphanumeric characters
          for( std::string::iterator iter = text.begin() ; iter != text.end() ; ){
               if( !std::isalnum(*iter) && *iter != ' ') 
                    iter = text.erase(iter) ;
               else 
                    ++iter ; // not erased, increment iterator
          }
		//convert text to lower case
		std::transform (text.begin(), text.end(), text.begin(), ::tolower);
		
		insert(title,author,text);

		//move to info for the next title
		s.erase(0, pos + titleDelimiter.length()+1);
	}
}