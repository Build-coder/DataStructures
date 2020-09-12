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

// 2.) Fix the following functions so they run

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

    // prints the value stored in 'x'
    void f(int x){
        std::cout << ++x;
    }
    
    // prints the memory address of 'x'
    void g(int &x){
        std::cout << ++x;
    }

// 4.) Explain questions 4a and 4b in two-three sentences.
//     DO NOT MODIFY THE DATA STRUCTURE. 
//     The variable matrix represents a 2D array of ints

    void buildMatrix(int **matrix, int m, int n){
        int init = 10;
        matrix = new int*[m];
        
        for(int i = 0; i < m; i++)
            matrix[i] = new int[n];
    }

    void deleteMatrix(int **matrix, int m){
    
        for (int i=0;i<m;i++){
            delete [] matrix[i];
            delete [] matrix;
        }  
    }

//  4a.) Why does the following code have memory leaks?







// 4b.) How can we fix the problem? Find bug causing problem.




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
};

class LinkedList { // a linked list
    public:
        LinkedList(); // empty list constructor
        ~LinkedList(); // destructor
        bool empty() const; // is list empty?
        // get the front (head) member
        const string& front() const;
        // get the last member
        const string& tail() const;

        //insert at the tail of list
        void append(const string& toInsert){

            // implement here



        };

        //remove the last member of the list
        void removeTail(){
            
            // implement here


        };

        //prints all members in order from head to tail
        void printList();

    private:
        Node* m_head; // pointer to the head of list
};


//  6.) List the test cases required to test the append(..) function


// 7.)  List the test cases required to test the removeTail() function


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
    buildMatrix(array, 2, 2);
    deleteMatrix(array, 2);

    // Question 5

    
    return 0;

}






