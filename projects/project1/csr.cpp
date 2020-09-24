// CMSC 341 - Fall 2020 - Project 1
#include "csr.h"
using namespace std;

CSR::CSR(){
    /***********************************
     *      To be implemented
     * ********************************/

    int* m_values = nullptr;//array to store non-zero values
    int* m_col_index = nullptr;//array to store column indices
    int* m_row_index = nullptr;//array to store row indices 
    int m_nonzeros = 0;//number of non-zero values
    int m_m = 0;//number of rows
    int m_n = 0;//number of columns
    CSR* m_next = nullptr;//pointer to the next CSR object in linked list

    cout << "CSR constructor called" << endl;
}

CSR::~CSR(){
    /***********************************
     *      To be implemented
     * ********************************/
}

// copy constructor
CSR::CSR(const CSR & src){
    /***********************************
     *      To be implemented
     * ********************************/

    // create a new CSR node
    // copy all the values in each member variable
    // of the rhs node to the new CSR node

    CSR newNode;

    // init all non-pointers
    newNode.m_nonzeros = src.m_nonzeros;
    newNode.m_m = src.m_m;
    newNode.m_n = src.m_n;
    
    // init pointers
    newNode.m_values = new int[newNode.m_nonzeros];
    newNode.m_col_index = new int[newNode.m_nonzeros];
    newNode.m_row_index = new int[newNode.m_nonzeros];

    for (int i = 0; i < m_nonzeros; i++)
    {
        /* code */
    }
    

}

void CSR::dump(){
    cout << endl;
    if (!empty()){
        for (int i=0;i<m_nonzeros;i++)
            cout << m_values[i] << " ";
        cout << endl;
        for (int i=0;i<m_nonzeros;i++)
            cout << m_col_index[i] << " ";
        cout << endl;
        for (int i=0;i<m_m+1;i++)
            cout << m_row_index[i] << " ";
    }
    else
        cout << "The object is empty!";
    cout << endl;
}

void CSR::clear(){
    /***********************************
     *      To be implemented
     * ********************************/
}

bool CSR::empty() const{
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/
    return false;
}

void CSR::compress(int m, int n, int array[], int arraySize){
    /***********************************
     *      To be implemented
     * ********************************/

    m_m = m;

    // init m_nonzeros (size of new arrays)
    for (int i = 0; i < arraySize; i++){

        if (array[i] != 0){
            m_nonzeros++;
        }
    }
    
    // create new arrays to store values
    // save new arrays memory addresses 
    // in member variables (int pointers)
    m_values = new int[m_nonzeros];
    m_col_index = new int[m_nonzeros];
    m_row_index = new int[m_nonzeros];

    // store values at 0 index
    int var = 0;
    int row = 0;

    // init m_values, m_col_index, and m_row_index
    for (int i = 0; i < arraySize; i++){

        if (array[i] != 0){

            // save nonzero values to m_values array
            m_values[var] = array[i];

            // save col indices to m_col_index array
            m_col_index[var] = i % n;
            
            // increment var to access next open index
            var++;       
        }

        // if next row of matrix or last row
        if (i % n == 0 || i+1 == arraySize){

            // if first row, set to 0
            if (i == 0) {
                m_row_index[0] = 0;

            // otherwise, set to # of values found
            } else {
                row++;
                m_row_index[row] = var;
            }
        }
    }   
}

int CSR::getAt(int row, int  col) const{
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/
    return 0;
} 

bool CSR::operator==(const CSR & rhs) const{
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/

    return true;
}

int CSR::sparseRatio(){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/
    return 0;
}