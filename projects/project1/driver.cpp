// CMSC 341 - Fall 2020 - Project 1
// #include "csrlist.h"
#include "csr.h"
using namespace std;

bool testEquality(CSR& a, CSR& b);
// bool testEquality(CSRList& a, CSRList& b);

int main()
{
    // try{

        // create CSR node
        CSR aCSR;

        // create an array and init
        int array1[] = {10,20,0,0,0,0,0,30,0,40,0,0,0,0,50,60,70,0,0,0,0,0,0,80};

        // init aCSR
        aCSR.compress(4,6,array1,24);
        

        aCSR.dump();

        // make a copy of aCSR called bCSR
        CSR bCSR(aCSR);

        // create a new CSR node
        CSR cCSR;

        // create a new array and init
        int array2[] = {0,0,0,0,100,200,0,0,300};

        // init cCSR
        cCSR.compress(3,3,array2,9);

        cCSR.dump();

        // make a copy of cCSR called dCSR
        CSR dCSR(cCSR);

        // // create a CSR list
        // CSRList aCSRList;

    //     aCSRList.insertAtHead(aCSR);
    //     aCSRList.insertAtHead(cCSR);

    //     // create a new CSR list
    //     CSRList bCSRList;
    //     bCSRList.insertAtHead(dCSR);
    //     bCSRList.insertAtHead(bCSR);

    //     cout << endl << "Dumping aCSRList:" << endl;
    //     aCSRList.dump();
    //     cout << endl << "Dumping bCSRList:" << endl;
    //     bCSRList.dump();
        
    //     // make sure nodes have same values but different addresses
    //     if (testEquality(cCSR,dCSR)) cout << endl << "testEquality(cCSR,dCSR) passed!" << endl;
    //     else cout << endl << "testEquality(cCSR,dCSR) failed!" << endl;

    //     // make sure nodes have same values but different addresses
    //     if (testEquality(aCSR,dCSR)) cout << endl << "testEquality(aCSR,dCSR) passed!" << endl;
    //     else cout << endl << "testEquality(aCSR,dCSR) failed!" << endl;

    //     // make sure lists have same values but different addresses
    //     if (testEquality(aCSRList,bCSRList)) cout << "testEquality(aCSRList,bCSRList)) passed!" << endl;
    //     else cout << endl << "testEquality(aCSRList,bCSRList) failed!" << endl;
        
    //     cout << endl << aCSRList.getAt(1,2,4) << endl;//returns the value 70

    //     cout << endl << aCSRList.getAt(5,2,2) << endl;//throws an exception
    // }
    // catch (exception &e){
    //     cout << e.what() << endl;
    // }
    return 0;
}

// // test if addresses of nodes are equal
// bool testEquality(CSR& a, CSR& b){
//     return (a == b);
// }

// // test if addresses of lists are equal
// bool testEquality(CSRList& a, CSRList& b){
//     return (a == b);
// }