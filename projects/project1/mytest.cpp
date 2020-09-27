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

    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;
   

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

    // test to check if CSR objects are copies of one another
    if (testValuesEQ(aCSR,bCSR)) cout << endl << "CSR objects are" <<
    " copies" << endl;
    else cout << endl << "CSR objects are not copies" << endl;

    // test to check if copies are deep or shallow
    if (testAddressNEQ(aCSR,bCSR)) cout << endl << "CSR objects are" <<
    " deep copies" << endl;
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

    // arrays to store in CSR objects
    int array2[] = {0,0,0,0,100,200,0,0,300};
    int array3[] = {0,0,0,0,5,8,0,0,0,0,3,0,0,6,0,0};
    int array4[] = {0,0,0,0,0,0,0,0,2,0,3,0,0,6,0,0};

    // init nodes
    cCSR.compress(3, 3, array2, 9);
    dCSR.compress(4, 4, array3, 16);
    eCSR.compress(2, 8, array4, 16);


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

    // test to check if CSR objects are copies of one another
    if (testValuesEQ(aCSRList,bCSRList)) cout << endl << "CSR lists are" <<
    " copies" << endl;
    else cout << endl << "CSR lists are not copies" << endl;

    // test to check if copies are deep or shallow
    if (testAddressNEQ(aCSRList,bCSRList)) cout << endl << "CSR lists are" <<
    " deep copies" << endl;
    else cout << endl << "CSR lists are shallow copies" << endl;


    cout << endl;

   

    cout << "\n/**************************************************/\n" <<
    "/*******TESTING Assignment Operator of CSRList*****/\n" <<
    "/**************************************************/\n";

    /**** create list here ****/

    /**** init list here ****/

    /**** call assignment oper here ****/

    // test to check if CSR objects are copies of one another
    if (testValuesEQ(aCSRList,bCSRList)) cout << endl << "CSR lists are" <<
    " copies" << endl;
    else cout << endl << "CSR lists are not copies" << endl;

    // test to check if copies are deep or shallow
    if (testAddressNEQ(aCSRList,bCSRList)) cout << endl << "CSR lists are" <<
    " deep copies" << endl;
    else cout << endl << "CSR lists are shallow copies" << endl;

    cout << endl;



    cout << "Contents of aCSR list are dumped below:" << endl;

    aCSRList.dump();

    cout << endl;

    cout << "Contents of bCSR list are dumped below:" << endl;

    bCSRList.dump();

    cout << endl;
    


    // /*********************
    //  * Check that clear() removes
    //  * all data, leaving an empty 
    //  * CSRList
    //  * *******************/


    // /*********************
    //  * Check that the equality 
    //  * operator returns the correct
    //  * boolean value
    //  * *******************/

    // /*********************
    //  * Test compress():
    //  * if user creates a matrix
    //  * of 0x0 
    //  * ******************/

    // /*********************
    //  * Check that the equality 
    //  * operator returns the correct
    //  * boolean value
    //  * *******************/
    

    return 0;
}