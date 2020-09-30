// CMSC 341 - Fall 2020 - Project 1

#include "csr.h"
#include "csrlist.h"
using namespace std;


/*****************************
 * Bool Unit Tests
 * **************************/

// test if CSR objects are copies
bool testValuesEQ(CSR& a, CSR& b){

    return ( a == b );
}


// test if CSR objects are deep copies
bool testAddressNEQ(CSR& a, CSR& b){

    return ( &a != &b );
}


// test if CSR lists are copies
bool testValuesEQ(CSRList& a, CSRList& b){

    return ( a == b );
}

// test if CSR lists are deep copies
bool testAddressNEQ(CSRList& a, CSRList& b){

    return ( &a != &b );
}


int main(){

    cout << "----------------------------------------------------" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "----------------------------------------------------" << endl;
   

    /*****************************
     * Create and Init CSR Nodes
     * **************************/

    // create CSR node
    CSR aCSR;

    // create array
    int array1[] = {10,20,0,0,0,0,0,30,0,40,0,0,0,0,50,60,70,0,0,0,0,0,0,80};

    // init aCSR
    aCSR.compress(4,6,array1,24);

 
    cout << "\n/**************************************************/\n" <<
    "/********TESTING COPY CONSTRUCTOR of CSR***********/\n" <<
    "/**************************************************/\n";

    // make copy of aCSR
    CSR bCSR(aCSR);

    // test to check if CSR objects are copies of one aNOTher
    if (testValuesEQ(aCSR,bCSR)) cout << endl << "CSR objects are" <<
    " copies" << endl;
    else cout << endl << "CSR objects are NOT copies" << endl;

    // test to check if copies are deep or shallow
    if (testAddressNEQ(aCSR,bCSR)) cout << endl << "CSR objects are" <<
    " NOT shallow copies" << endl;
    else cout << endl << "CSR objects are shallow copies" << endl;
    cout << endl;

    cout << "Contents of aCSR are dumped below:" << endl;
    aCSR.dump();
    cout << endl;

    cout << "Contents of bCSR are dumped below:" << endl;
    bCSR.dump();
    cout << endl;

    /**********************************************************
     * Create a bunch of CSR objects to later link together
     * to create a list
     * *******************************************************/

    // CSR nodes
    CSR cCSR;
    CSR dCSR;
    CSR eCSR;
    CSR fCSR;
    CSR gCSR;
    CSR hCSR;

    // arrays to store in CSR objects
    int array2[] = {0,0,0,0,100,200,0,0,300};
    int array3[] = {0,0,0,0,5,8,0,0,0,0,3,0,0,6,0,0};
    int array4[] = {0,0,0,0,0,0,0,0,2,0,3,0,0,6,0,0};
    int array5[] = {0,0,0,0,0,0,1,1};
    int array6[] = {10,3,8,0,0,0};
    int array7[] = {0,0,1,2};
    int array8[] = {};
    

    // init nodes
    cCSR.compress(3, 3, array2, 9);
    dCSR.compress(4, 4, array3, 16);
    eCSR.compress(2, 8, array4, 16);

    fCSR.compress(2, 4, array5, 8);
    gCSR.compress(2, 3, array6, 6);
    hCSR.compress(2, 2, array7, 4);


    cout << "\n/**************************************************/\n" <<
    "/********TESTING COPY CONSTRUCTOR of CSRList*******/\n" <<
    "/**************************************************/\n";

    // create list
    CSRList aCSRList;

    /**** init list here ******/
    aCSRList.insertAtHead(cCSR);
    aCSRList.insertAtHead(dCSR);
    aCSRList.insertAtHead(eCSR);

    /**** call list copy constructor here *****/
    CSRList bCSRList(aCSRList);

    // test to check if CSR objects are copies of one aNOTher
    if (testValuesEQ(aCSRList,bCSRList)) cout << endl << "CSR lists are" <<
    " copies" << endl;
    else cout << endl << "CSR lists are NOT copies" << endl;

    // test to check if copies are deep or shallow
    if (testAddressNEQ(aCSRList,bCSRList)) cout << endl << "CSR lists are" <<
    " NOT shallow copies" << endl;
    else cout << endl << "CSR lists are shallow copies" << endl;
    cout << endl;

    cout << "Contents of aCSR list are dumped below:" << endl;
    aCSRList.dump();
    cout << endl;

    cout << "Contents of bCSR list are dumped below:" << endl;
    bCSRList.dump();
    cout << endl;

    cout << "\n/**************************************************/\n" <<
    "/*******TESTING Assignment Operator of CSRList*****/\n" <<
    "/**************************************************/\n";

    /**** create lists here ****/
    CSRList cCSRList;
    CSRList dCSRList;

    /**** init lists here ****/
    cCSRList.insertAtHead(fCSR);
    cCSRList.insertAtHead(gCSR);
    cCSRList.insertAtHead(hCSR);
    
    dCSRList.insertAtHead(cCSR);
    dCSRList.insertAtHead(dCSR);
    dCSRList.insertAtHead(eCSR);

    /**** call assignment oper here ****/
    dCSRList = cCSRList;

    // test to check if CSR objects are copies of one aNOTher
    if (testValuesEQ(cCSRList,dCSRList)) cout << endl << "CSR lists are" <<
    " copies" << endl;
    else cout << endl << "CSR lists are NOT copies" << endl;

    // test to check if copies are deep or shallow
    if (testAddressNEQ(cCSRList,dCSRList)) cout << endl << "CSR lists are" <<
    " NOT shallow copies" << endl;
    else cout << endl << "CSR lists are shallow copies" << endl;
    cout << endl;

    cout << "Contents of dCSR list are dumped below:" << endl;
    cCSRList.dump();
    cout << endl;

    cout << "Contents of cCSR list are dumped below:" << endl;
    dCSRList.dump();
    cout << endl;


    
    /*********************
     * Check that clear() removes
     * all data, leaving an empty 
     * node and CSRList
     * *******************/
    cout << "\n/**************************************************/\n" <<
    "/*******TESTING Clear on CSR Node and List*********/\n" <<
    "/**************************************************/\n";

    cout << endl;
    aCSR.clear();
    cout << "After calling clear on aCSR node: ";

    if (aCSR.empty()){
        cout << "The node is empty\n";
    } else{
        cout << "The node is NOT empty\n";
    }

    aCSRList.clear();
    cout << "After calling clear on aCSRList: ";

    if (aCSRList.empty()){
        cout << "The list is empty\n";
    } else {
        cout << "The list is NOT empty\n";
    }

    cout << endl;

    /*********************
     * Check that the CSR equality 
     * operator returns the correct
     * boolean value
     * *******************/
    cout << "\n/**************************************************/\n" <<
    "/*************TESTING CSR Boolean Operator*********/\n" <<
    "/**************************************************/\n";

    // test to check if CSR objects are copies of one aNOTher
    if (testValuesEQ(bCSR,cCSR)) cout << endl << "CSR objects are" <<
    " copies" << endl;
    else cout << endl << "CSR objects are NOT copies" << endl;

    // test to check if copies are deep or shallow
    if (testAddressNEQ(bCSR,cCSR)) cout << endl << "CSR objects are" <<
    " NOT shallow copies" << endl;
    else cout << endl << "CSR objects are shallow copies" << endl;
    cout << endl;

    cout << "Contents of bCSR are dumped below:" << endl;
    bCSR.dump();
    cout << endl;

    cout << "Contents of cCSR are dumped below:" << endl;
    cCSR.dump();
    cout << endl;


    /*********************
     * Check that the CSRList equality 
     * operator returns the correct
     * boolean value
     * *******************/
    cout << "\n/**************************************************/\n" <<
    "/*********TESTING CSRList Boolean Operator*********/\n" <<
    "/**************************************************/\n";

    // test to check if CSR objects are copies of one another
    if (testValuesEQ(bCSRList,cCSRList)) cout << endl << "CSR lists are" <<
    " copies" << endl;
    else cout << endl << "CSR lists are NOT copies" << endl;

    // test to check if copies are deep or shallow
    if (testAddressNEQ(bCSRList,cCSRList)) cout << endl << "CSR lists are" <<
    " NOT shallow copies" << endl;
    else cout << endl << "CSR lists are shallow copies" << endl;
    cout << endl;

    cout << "Contents of bCSR list are dumped below:" << endl;
    bCSRList.dump();
    cout << endl;

    cout << "Contents of cCSR list are dumped below:" << endl;
    cCSRList.dump();
    cout << endl;
    

    /***************************************************
     * 
     * Test compress():
     * 
     * if the number of data members in the input array 
     * is less than (m x n), the constructor uses the 
     * array to initialize the matrix, and the rest of 
     * matrix members will be initialized to zero. 
     * 
     * if the number of data members in the input array is 
     * greater than (m x n), the constructor uses 
     * the array to initialize the matrix, and the 
     * rest of array data will be ignored. 
     * 
     * if the user decides to make a 0 x 0 matrix, that would 
     * be considered an empty object, even if user 
     * provides data in the array. 
     * 
     * Also, it is possible that user specifies the matrix size, 
     * but does not provide data in the array; this would be 
     * considered a matrix with all members set to zero.
     * **************************************************/
    cout << "\n/**************************************************/\n" <<
    "/********TESTING Compress 0x0 Matrix Input*********/\n" <<
    "/**************************************************/\n";

    // test for arraySize < m*n
    cout << "Test for array size < m*n: ";
    aCSR.compress(6, 4, array1, 20);

    cout << "\nBelow are the contents of a matrix with dimensions\n" <<
    "greater than it's array size:" << endl;

    aCSR.dump();
    cout << endl;

    // test for arraySize > m*n
    cout << "Test for array size > m*n: ";
    aCSR.compress(6, 4, array1, 30);

    cout << "\nBelow are the contents of a matrix with dimensions\n" <<
    "less than it's array size:" << endl;

    aCSR.dump();
    cout << endl;

    // test for empty matrix
    cout << "Test for empty matrix: ";
    aCSR.compress(0, 0, array1, 24);

    cout << "\nBelow are the contents of a matrix with at least one\n" <<
    "of it's dimensions as 0:" << endl;

    aCSR.dump();
    cout << endl;

    // test for matrix with no members
    cout << "Test for matrix with no members: ";
    aCSR.compress(4, 2, array8, 8);

    cout << "\nBelow are the contents of a matrix with no members:\n";

    aCSR.dump();
    cout << endl;


    return 0;
}