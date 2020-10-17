#include "wordTree.h"
using namespace std;


WordTree* populateTree(WordTree* tree){

    string inputStr[] = {"D","B","F","A","C","E","G"};
    string inputStr1[] = {"A","B","C","D","E","F","G"};
    string inputStr2[] = {"G","F","E","D","C","B","A"};
    string inputStr3[] = {"aligator","bear","cat","dog",
    "eel","fox","goat"};


    for (int i = 0; i < 7; i++){
        tree->insert(inputStr3[i]);
    }

    return tree;
}

int main(){

    WordTree* ptr = nullptr;

    ptr = populateTree(ptr);

    ptr->dump();
    cout << endl;
    
    return 0;
}

// 1.) Need to balance tree
// 2.) Need to set height of each node

// 3.) insert(string, Node*) is suppose to return
//      a Node* but I'm not sure what to return
