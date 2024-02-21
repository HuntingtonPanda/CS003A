#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/array_functions/array_functions.h"
using namespace std;
 
 //test case for _stub function
bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}
 
 //test case for _at function
bool test_at(bool debug = false){
  int a[20];
  int size =5;
  const char tabs[] = "\t---------------\t";
  if (debug){
    cout << tabs << "size: 5, init array to -1" << endl;
  }
  _array_init(a,size,-1);
  if (debug){
    cout << tabs;
    _print_array(a, size);
    cout << endl;
  }
  int at_i;
  for (int i = 0; i< size; i++){
    at_i = _at(a,size, i);
    if (at_i != -1){
      cout << "FAILED: Expected at(i) to return -1, but found : " << at_i << endl;
      return false;
    }
  }
  _at(a,size,3) =300;
  at_i = _at (a,size,3);
  if (at_i != 300){
    cout << "FAILED: Expected to find 300 at(3), but found " << at_i << endl;
    return false;
  }
  return true;
}

//test case for _init_array function
bool test_init_array(bool debug = false){
  int a[20];
  int size = 5;
  const char tabs[] = "\t---------------\t";
  if (debug){
    cout << tabs << "size: " << size << ", init array to -1" << endl;
  }
  _array_init(a, size, -1);
  if (debug){
    cout << tabs;
    _print_array(a, size);
    cout << endl;
  }
  for (int i = 0; i < size; i++){
    if (a[i] != -1){
      cout << "FAILED: Expected -1 at a[" << i << "]but found: "
      << a[i] << endl;
      return false;
    }
  }
 
  return true;
}

//test case for _append function 
bool test_append(bool debug = false){
  const int MAX = 20;
  int size = 5;
  int a[MAX];
  const char tabs[] = "\t---------------\t";
  if (debug){
    cout << tabs << "size: 5, init array to -1" << endl;
  }
  _array_init(a, size, -1);
  if (debug){
    cout << tabs;
    if (debug) _print_array(a, size);
    cout << endl;
  }
  for (int i = size; i < 10; i++){
    _append(a, size, i * 10);
    if (debug){
      cout << tabs << " " << i << ": ";
      _print_array(a, size);
      cout << endl;
    }
  }
  if (size != 10){
    cout << "FAILED: Expected size to be 10, but found" << size << endl;
    return false;
  }
  if (a[size - 1] != (size - 1) * 10){
    cout << "FAILED : Expected " << (size - 1) * 10 << " at a[" << size << "] "
         << "but found: " << a[size - 1] << endl;
    return false;
  }
  return true;
}

//test case for _find function
bool test_find(bool debug = false){
int a[20] = {42, 1, 2, 43, 4, 5, 44};
int index;
int size = 7;

index = _find(a, size, 42);

if (index != 0){
  cout << "failed to find at the start of the lsit" << endl;
  return false;
}

index = _find(a, size, 43);

if (index != 3){
  cout << "failed to find in the middle of the list" << endl;
  return false;
}

index = _find(a, size, 44);

if (index != 6){
  cout << "failed to find at the end of the list" << endl;
  return false;
}


  return true;
}
 
 ////test suit for test_stub
TEST(TEST_STUB, TestStub) {
 
  //EXPECT_EQ(0, <your individual test functions are called here>);
 
  EXPECT_EQ(1, test_stub(false));
}
 
 //test suit for test_init_array
TEST(TEST_INIT_ARRAY, TestInitArray) {
 
  //EXPECT_EQ(0, <your individual test functions are called here>);
 
  EXPECT_EQ(1, test_init_array(false));
}
 
 //test suit for test_append
TEST(TEST_APPEND, TestAppend) {
 
  //EXPECT_EQ(0, <your individual test functions are called here>);
 
  EXPECT_EQ(1, test_append(false));
}

//test suit for test_at
TEST(TEST_AT, TestAt) {
 
  //EXPECT_EQ(0, <your individual test functions are called here>);
 
  EXPECT_EQ(1, test_at(false));
}

//test suit for test_find
TEST(TEST_FIND, TestFind) {
 
  //EXPECT_EQ(0, <your individual test functions are called here>);
 
  EXPECT_EQ(1, test_find(false));
}
 
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}
