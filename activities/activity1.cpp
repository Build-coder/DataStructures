#include <string>
#include <iostream>
using namespace std;

class test{
private:
  int* _ar[5];

public:
  test(){
    for (int i=0;i<5;i++)
      _ar[i] = nullptr;
  }

  /*************************
  * Destructor
  *************************/
  ~test(){

    for (int i = 0; i < 5; i++) {
      if (_ar[i] != nullptr){
        delete _ar[i];
        _ar[i] = nullptr;
      }  
    }
  }

  /*************************
  * Copy Constructor
  *************************/
  test(const test& another){

    // init to nullptr
    for (int i=0;i<5;i++)
      _ar[i] = nullptr;

    for (int j = 0; j < 5; j++){

      if (!another.isNull(j)){
        set(j, another.get(j));
      } 
    }
  }

  /*************************
  * Assignment Operator
  *************************/
  const test& operator=(const test& another){

      if (this != &another){
        
        for (int i = 0; i < 5; i++){
          
          if (_ar[i] != nullptr){
            delete _ar[i];
            _ar[i] = nullptr;
          }
        }

        // create new object

        for (int j = 0; j < 5; j++){

          if (!another.isNull(j)){
            set(j, another.get(j));
          } 
        }
      }

    return *this;
  }

  void set(int index, int value){
    if (_ar[index] == nullptr)
      _ar[index] = new int(value);
    else
      *_ar[index] = value;
  }
  
  int get(int index) const{
    return *_ar[index];
  }

  int* getPointer(int index) const{
    return _ar[index];
  }

  bool isNull(int index) const {
    return (_ar[index] == nullptr);
  }

  void printAll(){
    for (int i=0;i<5;i++){
      if (_ar[i] != nullptr)
	cout << "\n" << i << " " << _ar[i] << " " << *_ar[i] << endl;
      else
	cout << "\n" << i << " " << _ar[i] << " " << "NO VALUE" << endl;
    }
    cout << endl;
  }
};

/***************************************************
 * Test case to test equality of values in 2 objects
 **************************************************/
bool testValuesEQ(const test& t1, const test& t2){

  bool returnValue = false;

  for (int i = 0; i < 5; i++){
    if (t1.get(i) == t2.get(i)){
      returnValue = true;
    } else {
      returnValue = false;
    } 
  }

  return returnValue;
}

/*******************************************************
 * Test case to test inequality of pointers in 2 objects
 ******************************************************/
bool testPointerNEQ(const test& t1, const test& t2){

  int count = 0;

  for (int i = 0; i < 5; i++){

    if (t1.getPointer(i) == t2.getPointer(i)){
      count++;
    }
  }

  return (count == 0);
}

/*******************************************
 * Driver program to test the data structure
 ******************************************/
int main(){
  test t1;
  for (int i=0;i<5;i++)
    t1.set(i, i*10);

  //section to test copy constructor
  test t2(t1);
  cout << "Testing the copy constructor:" << endl;
  if (testValuesEQ(t1,t2))
    cout << "Good! Values are equal!" << endl;
  else
    cout << "Something is wrong with values!" << endl;
  if (testPointerNEQ(t1,t2))
    cout << "Good! Pointers are different!" << endl;
  else
    cout << "Something is wrong with pointers!" << endl;
  
  //section to test overloaded assignment operator
  test t3 = t2;
  cout << "Testing the assignment operator:" << endl;
  if (testValuesEQ(t2,t3))
    cout << "Good! Values are equal!" << endl;
  else
    cout << "Something is wrong with values!" << endl;
  if (testPointerNEQ(t2,t3))
    cout << "Good! Pointers are different!" << endl;
  else
    cout << "Something is wrong with pointers!" << endl;
  
  return 0;
}