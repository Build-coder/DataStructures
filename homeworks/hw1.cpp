// CMSC 341 - Fall 2020 - Homework 1

#include <iostream>

using namespace std;


// 1.) Fix the following functions so it runs. You can try to compile and run the code

    void initArrayPointers() {

        double* dp[10];

        for (int i = 0; i < 10; i++){
            dp[i] = new double(0.0);
            cout << *dp[i] << ", ";
        }
    }

// 2.) Fix the following function so it runs

    void myTest(int** dataStructure[][10]) {
        
        int init = 10;
        int rows = 10;
        int columns = 10;
        
            for (int i=0;i<rows;i++){
                for (int j=0;j<columns;j++){
                
                    dataStructure[i][j] = new int*(&init);
                    init = init+10;
                    cout << **dataStructure[i][j] << ", ";
                }
            }
    }

// 3.) What is diff about the behavior of the following funcs?

    // argument is the value stored in 'x'
    void f(int x){
        cout << ++x << endl;
    }
    
    // argument is the memory address of 'x'
    void g(int &x){
        cout << ++x << endl;
    }

// 4.) Explain questions 4a and 4b in two-three sentences.
//     DO NOT MODIFY THE DATA STRUCTURE. 
//     The variable matrix represents a 2D array of ints


    void buildMatrix(int **matrix, int m, int n){
        int init = 10;
        matrix = new int*[m];
        
        for(int i = 0; i < m; i++){
            matrix[i] = new int[n];
            *matrix[i] = init;
            cout << *matrix[i] << endl;
        }  
    }

    void deleteMatrix(int **matrix, int m){
    
        for (int i=0;i<m;i++){
            delete [] matrix[i];
        }  
        delete [] matrix;
    }

//  4a.) Why does the following code have memory leaks?

// line 69: delete[] matrix[i] causes a seg fault b/c matrix[i] 
// cannot be reached. this is because it was not properly 
// created and initialized in the buildMatrix function


// 4b.) How can we fix the problem? Find bug causing problem.

// we can properly create and initialize matrix[i] in the
// buildMatrix function


// 5.) The following code presents the interface of a linked
//     list class. Write implementation for the functions
//     append() and removeTail().

//     Note: a correct algorithm is required in your code,
//           but fully compiling code is not expected.

//     Throw "std::runtime_error" exceptions to handle
//     special cases. The "runtime_error" class is defined
//     in the include file <stdexcept>. You can simply throw
//     runtime_error("your message").
        
class Node { // a node in a linked list
    public:
        Node():m_next(nullptr),m_elem(""){};

    private:
        string m_elem; // element value
        Node* m_next; // next item in the list
        // provide LinkedList access
        friend class LinkedList;

        // friend ostream& operator<< (ostream &sout, const Node &x){
        //     sout << x.m_elem << endl;
        // };

};

class LinkedList { // a linked list
    public:
        LinkedList(){
            m_head = nullptr;
        }; // empty list constructor

        ~LinkedList(){
              
            Node* curr = m_head;

            while(m_head != nullptr){
                // move tracker to next node
                m_head = m_head->m_next;
                // delete prev node
                delete curr;
                // set curr to nullptr
                curr = nullptr;
                // set curr to mm_head node
                curr = m_head;
            }
            
            m_head = nullptr;
        }; // destructor

        bool empty() const{
            return m_head == nullptr;
        }; // is list empty?

        // get the front (head) member
        const string& front() const;

        // get head
        Node* getHead() const{
            return m_head;
        }

        Node* getNext() const{
            Node* nodePtr;

            return nodePtr->m_next;
        }

        // get the last member
        const string& tail() const;

        //insert at the tail of list
        void append(const string& toInsert){

            // implement here
            Node* newPtr = new Node();
            Node* tempPtr;

            if (m_head == nullptr){
                m_head = newPtr;
                newPtr->m_elem = toInsert;
            }
            else{
                tempPtr = m_head;
                while ( tempPtr-> m_next != nullptr ) {
                    tempPtr = tempPtr->m_next;
                }
                tempPtr->m_next = newPtr;
                newPtr->m_elem = toInsert;
            }
        }

        //remove the last member of the list
        void removeTail(){
            
            // implement here
            if ( empty() ) {
                throw range_error("Queue<T>::dequeue(): attempt to dequeue an empty Queue.");
            }

            Node* curr;
            Node* prev;

            if (m_head == nullptr){
                m_head = m_head;
            }
            else{
                curr = m_head;

                while ( curr-> m_next != nullptr ) {
                    prev = curr;
                    curr = curr->m_next;
                }

                prev->m_next = nullptr;
                delete curr; 
                curr = nullptr;         
            }
        }

        //prints all members in order from head to tail
        void printList(){
            Node* nodePtr = m_head;

            while ( nodePtr != nullptr) {
                cout << nodePtr->m_elem << endl;
                nodePtr = nodePtr->m_next;
            }
        };

        bool testLastValue(){

            Node* curr = m_head;

            while (curr != nullptr){
                curr = curr->m_next;
            }

            return curr->m_next == nullptr;
        }

    private:
        Node* m_head; // pointer to the head of list
};


//  6.) List the test cases required to test the append(..) function

//      - bool test to make sure there are no duplicate values
//      - bool test to make sure there are no duplicate addresses


// 7.)  List the test cases required to test the removeTail() function

//      - bool test to make sure tail's next is nullptr
//      - bool test to make sure one element is deleted everytime func is called


// 8.) Implement a testing function for the function removeTail()
//     All required operations can be executed in your funciton 
//     The main function will call your function
//     Your func returns a bool for pass or fail
//     Specify which case from question 7 your func is testing

//     Note: a correct algorithm is required in your code,
//           but fully compiling code is not expected.

//     You can use the funcs provided by the class interface
//     If required, you can catch exceptions thrown in your
//     implementation of the func removeTail()



int main(){

    // Question 1
    initArrayPointers();
    cout << endl << endl;

    // Question 2
    int** data[10][10];

    myTest(data);
    cout << endl;

    // Question 3
    int x = 10;
    f(x);
    g(x);
    cout << endl;

    // Question 4
    int **array;
    buildMatrix(array, 4, 2);
    deleteMatrix(array, 2);
    cout << endl;

    // Question 5

    LinkedList LL1;

    for (int i = 1; i <= 5; i++) {

        switch (i) {
        case 1:
            LL1.append("Syd");
            break;
        case 2:
            LL1.append("Nala");
            break;
        case 3:
            LL1.append("Simba");
            break;
        case 4:
            LL1.append("Scar");
            break;
        case 5:
            LL1.append("Mufasa");
            break;
                        
        default:
            break;
        }
    }

    LL1.printList();

    cout << endl;

    // make sure queues aren't empty before being copied
    cout << "\nAttempt dequeue() of empty queue:\n";
    try {

        // try to remove the head of the queue
        LL1.removeTail();

        // queue is empty so dequeue will throw an exception
        // and exit

        // pass in exception message  
    } catch (exception &e) {

        // print exception message 
        cout << "Caught exception:\n" << e.what() << endl;
    }

    LL1.printList();

    cout << endl;

    LL1.removeTail();

    LL1.printList();

    cout << endl;
    
    return 0;

}
