// CMSC 341 - Fall 2020 - Project 1
#include "csr.h"

CSR::CSR(){
    /***********************************
     *      To be implemented
     * ********************************/

    // int* m_values = nullptr;//array to store non-zero values
    // int* m_col_index = nullptr;//array to store column indices
    // int* m_row_index = nullptr;//array to store row indices 
    // int m_nonzeros = 0;//number of non-zero values
    // int m_m = 0;//number of rows
    // int m_n = 0;//number of columns
    // CSR* m_next = nullptr;//pointer to the next CSR object in linked list
}

CSR::~CSR(){
    /***********************************
     *      To be implemented
     * ********************************/
}

CSR::CSR(const CSR & rhs){
    /***********************************
     *      To be implemented
     * ********************************/

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
    return true;
}

void CSR::compress(int m, int n, int array[], int arraySize){
    /***********************************
     *      To be implemented
     * ********************************/

    for (int i = 0; i < m; i++){
        cout << array[i] << endl;
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