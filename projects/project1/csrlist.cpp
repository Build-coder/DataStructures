// CMSC 341 - Fall 2020 - Project 1
#include "csrlist.h"

CSRList::CSRList(){
    /***********************************
     *      To be implemented
     * ********************************/

    /***********************************
     * Constructor, creates an empty
     * CSRList object
     * ********************************/

    m_head = nullptr;
    m_size = 0;
}

CSRList::~CSRList(){
    /***********************************
     *      To be implemented
     * ********************************/

    /***********************************
     * Deconstructor
     * ********************************/

    CSR* curr = m_head;

    while(m_head != nullptr){
        // move tracker to next node
        m_head = m_head->m_next;
        // delete prev node
        delete curr;
        // set curr to nullptr
        curr = nullptr;
        // set curr to m_head node
        curr = m_head;
    }
  
    m_head = nullptr;
    m_size = 0;
}

bool CSRList::empty() const{
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/


    /***********************************
     * Returns true if the object is
     * empty, otherwise returns false
     * ********************************/
    return (m_head == nullptr) && (m_size == 0);
}

void CSRList::insertAtHead(const CSR & matrix){
    /***********************************
     *      To be implemented
     * ********************************/

    /***********************************
     * Inserts the CSR object at the head 
     * of the CSRList object
     * ********************************/
    CSR* newPtr = new CSR(matrix);
    CSR* tempPtr;

    if (m_head == nullptr){
        m_head = newPtr;
        m_size++;
    }
    else{
        tempPtr = m_head;

        while ( tempPtr->m_next != nullptr ) {
            tempPtr = tempPtr->m_next;
            m_size++;
        }
        tempPtr->m_next = newPtr;
    }

}

void CSRList::clear(){
    /***********************************
     *      To be implemented
     * ********************************/

    /***********************************
     * Resets the CSRList object to its
     * initial, empty state
     * ********************************/

    CSR* nodePtr = m_head;

    while ( nodePtr != nullptr ) {
        nodePtr->clear();
        nodePtr = nodePtr->m_next;
    }

    m_head = nullptr;
    m_size = 0;

}

int CSRList::getAt(int CSRIndex, int row, int col) const{
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/

    /***********************************
     * Returns the value of a matrix 
     * member with row and col indices,
     * from the matrix at the position
     * CSRIndex in the CSRList object. 
     * Requires exception handling if
     * an index does not exist in CSR 
     * object, or the CSR object does 
     * not exist in the list
     * ********************************/

    CSR* curr = m_head;
    int i = 0;

    while (curr != nullptr){

        if (CSRIndex == i){
            return curr->getAt(row, col);
        }

        i++;  
    }
    
    return NULL;
}


void CSRList::dump(){
    if (!empty()){
        CSR* temp = m_head;
        while (temp != nullptr){
            temp->dump();
            temp = temp->m_next;
        }
    }
    else
        throw runtime_error("Error: List is empty!");
}


bool CSRList::operator== (const CSRList & rhs) const{
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/

    /***********************************
     * Equality Operator, returns true if 
     * both lists have the same matrices 
     * and in the same order, otherwise
     * returns false
     * ********************************/

    CSR* source = rhs.m_head;
    CSR* curr = m_head;

    while (curr != nullptr){

        for (int i = 0; i < curr->m_nonzeros; i++){
            
            if (curr->m_values[i] != source->m_values[i]){

                return false;
            } 
        }
    }
    
    return true;
}

const CSRList& CSRList::operator=(const CSRList & src){
    /***********************************
     *      To be implemented
     * ********************************/

    /***********************************
     * Assignment Operator
     * ********************************/

    if(this != &src) {

        /**************
         * Delete Data
         * ***********/

        CSR* curr = m_head;

        while(m_head != nullptr){
        // move tracker to next node
        m_head = m_head->m_next;
        // delete prev node
        delete curr;
        // set curr to nullptr
        curr = nullptr;
        // set curr to m_head node
        curr = m_head;
        }

        m_head = nullptr;

        /**************
         * Copy Data
         * ***********/

        CSR* source = src.m_head;
        int i = 0;

        while(source != nullptr) {
        
            curr->m_values[i] = source->m_values[i];
            curr->m_col_index[i] = source->m_col_index[i];
            curr->m_row_index[i] = source->m_row_index[i];
            curr->m_nonzeros = source->m_nonzeros;
            curr->m_m = source->m_m;
            curr->m_n = source->m_n;

            m_size++;
            i++;
        }

        //iterate to next node
        source = source->m_next;
    }
    
    return *this;
}

int CSRList::averageSparseRatio(){
    /***********************************
     *      To be implemented
     * Note: to avoid warnings, a
     * fictional return value is added,
     * your implementaion should return
     * a correct value.
     * ********************************/

    /***********************************
     * Returns the average sparse ratio 
     * for all matrices stored in the 
     * CSRList object. It returns the 
     * ratio as a percentage, e.g. if
     * the ratio is 0.656, the func 
     * returns 0.656 x 100 = 65 as int
     * ********************************/

    CSR* curr = m_head;
    float total = 0.0;

    while (curr != nullptr){

        total = curr->sparseRatio() + total;
    }
    
    // return average
    return (total/float(m_size))*100;
}