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


    cout << "\n/**************************************************/\n" <<
    "/********TESTING COPY CONSTRUCTOR of CSRList*******/\n" <<
    "/**************************************************/\n";

    // create list
    CSRList aCSRList;
    CSRList bCSRList;

    /**** init list here ******/

    /**** call list copy constructor here *****/

    // test to check if CSR objects are copies of one another
    if (testValuesEQ(aCSRList,bCSRList)) cout << endl << "CSR objects are" <<
    " copies" << endl;
    else cout << endl << "CSR objects are not copies" << endl;

    // test to check if copies are deep or shallow
    if (testAddressNEQ(aCSRList,bCSRList)) cout << endl << "CSR objects are" <<
    " deep copies" << endl;
    else cout << endl << "CSR objects are shallow copies" << endl;


    cout << endl;

   

    cout << "\n/**************************************************/\n" <<
    "/*******TESTING Assignment Operator of CSRList*****/\n" <<
    "/**************************************************/\n";

    /**** create list here ****/

    /**** init list here ****/

    /**** call assignment oper here ****/

    // test to check if CSR objects are copies of one another
    if (testValuesEQ(aCSRList,bCSRList)) cout << endl << "CSR objects are" <<
    " copies" << endl;
    else cout << endl << "CSR objects are not copies" << endl;

    // test to check if copies are deep or shallow
    if (testAddressNEQ(aCSRList,bCSRList)) cout << endl << "CSR objects are" <<
    " deep copies" << endl;
    else cout << endl << "CSR objects are shallow copies" << endl;

    cout << endl;


    /*********************
     * Check that clear() removes
     * all data, leaving an empty 
     * CSRList
     * *******************/


    /*********************
     * Check that the equality 
     * operator returns the correct
     * boolean value
     * *******************/

    /*********************
     * Test compress():
     * if user creates a matrix
     * of 0x0 
     * ******************/

    /*********************
     * Check that the equality 
     * operator returns the correct
     * boolean value
     * *******************/
    

    return 0;
}