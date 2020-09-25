// CMSC 341 - Fall 2020 - Project 1
#include "csr.h"
using namespace std;

CSR::CSR(){
    /***********************************
     *      To be implemented
     * ********************************/

    /***********************************
     * Default constructor, creates an empty
     * object. An empty object does not have
     * any memory allocated
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

    delete [] m_values;
    m_values = nullptr;

    delete [] m_col_index;
    m_col_index = nullptr;

    delete [] m_row_index;
    m_row_index = nullptr;

    m_nonzeros = 0;
    m_m = 0;
    m_n = 0;
}

CSR::CSR(const CSR & src){
    /***********************************
     *      To be implemented
     * ********************************/

    /***********************************
     * Copy constructor, creates a copy 
     * of src.
     * 
     * Create a new CSR node
     * Copy all the values in each member
     * variable of the src node to the new 
     * CSR node
     * ********************************/

    CSR newNode;

    // init all non-pointers
    newNode.m_nonzeros = src.m_nonzeros;
    newNode.m_m = src.m_m;
    newNode.m_n = src.m_n;
    
    // init pointers
    newNode.m_values = new int[newNode.m_nonzeros];
    newNode.m_col_index = new int[newNode.m_nonzeros];
    newNode.m_row_index = new int[newNode.m_nonzeros];

    for (int i = 0; i < newNode.m_nonzeros; i++){
        newNode.m_values[i] = src.m_values[i];
        newNode.m_col_index[i] = src.m_col_index[i];
        newNode.m_row_index[i] = src.m_row_index[i];
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

    /***********************************
     * Deallocates all memory, and makes
     * the object an empty CSR
     * ********************************/

    delete [] m_values;
    m_values = nullptr;

    delete [] m_col_index;
    m_col_index = nullptr;

    delete [] m_row_index;
    m_row_index = nullptr;

    m_nonzeros = 0;
    m_m = 0;
    m_n = 0;
}

bool CSR::empty() const{
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/

    /***********************************
     * Returns true if the object is empty,
     * otherwise returns false
     * 
     * If the dimensions are both 0, then
     * it's a 0x0 matrix which is an empty
     * matrix
     * ********************************/

    return (m_m == 0 || m_n == 0);
}

void CSR::compress(int m, int n, int array[], int arraySize){
    /***********************************
     *      To be implemented
     * ********************************/

    m_m = m;
    m_n = n;

    // init m_nonzeros (size of new arrays)
    for (int i = 0; i < arraySize; i++){

        if (array[i] != 0){
            m_nonzeros++;
        }
    }
    

    /***********************************
     * Create new arrays to store values
     * Save new arrays memory addresses
     * in member vars (int pointers)
     * ********************************/

    m_values = new int[m_nonzeros];
    m_col_index = new int[m_nonzeros];
    m_row_index = new int[m_nonzeros];

    // store values at 0 index
    int var = 0;
    int row = 0;

    // init m_values, m_col_index, and m_row_index
    for (int i = 0; i < arraySize; i++){

        // for each new row of matrix...
        if (i % n == 0){

            // if first row, set m_row to 0
            if (i == 0) {
                m_row_index[0] = 0;

            // otherwise, set m_row to # of values found
            } else {
                row++;
                m_row_index[row] = var;
            }
        }

        // for each nonzero value...
        if (array[i] != 0){

            // save nonzero values to m_values 
            m_values[var] = array[i];

            // save col indices to m_col_index 
            m_col_index[var] = i % n;
            
            // increment var to access next open index
            var++;       
        }

        // if last row
        if (i+1 == arraySize){

            row++;
            m_row_index[row] = var;
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

    /***********************************
     * Returns the value of the matrix 
     * member at indices row and col.
     * 
     * Requires exception handling if an
     * index does not exist. You can use
     * runtime_error exception which is 
     * defined in <stdexcept> library 
     * and is available from std 
     * namespace
     * ********************************/

    int row_start = m_row_index[row];
    int row_end = m_row_index[row+1];

    while (row_start != row_end){

        if (m_col_index[row_start] == col){

            return m_values[row_start];
        }
        
        row_start++;
    }
    
    return 0;
} 

bool CSR::operator==(const CSR & src) const{
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/

    /***********************************
     * Returns true if the object is empty,
     * otherwise returns false
     * ********************************/

    return src.empty();
}

int CSR::sparseRatio(){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/

    /***********************************
     * Returns the sparsity ratio for the
     * CSR object. It returns the ratio
     * as percentage, e.g. if the ratio 
     * is 0.656, the func returns 0.656
     * x 100 = 65 as an integer
     * 
     * The number of zeros divided by the 
     * total number of members in a matrix
     * shows the sparsity ratio
     * 
     * m_m * m_n will always be the total
     * number of members in a matrix
     * ********************************/

    // total number of members
    int total_mems = m_m * m_n;

    // total number of zeros
    int total_zeros = total_mems - m_nonzeros;

    // return ratio as a percentage
    return (total_zeros / total_mems) * 100;
}