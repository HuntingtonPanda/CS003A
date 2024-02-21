#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include "../../includes/vector/vector_class.h"
using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_initial(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }

  int a[] = {0,1,2,3,4,5,6,7,8,9};

  Vector<int> v1(a, 10);
  cout << v1 << endl;

  int b[] = {10,20,30,40,50,60,70,80,90};


  Vector<int> v2(b, 10);
  cout << "V2: " << v2 << endl;

  v1 = v1;
  cout << "V1: " << v1 << endl;

  v1 = v2;
  cout << "V1: " << v1 << endl;

  v1.push_back(11);
  cout << "V1: " << v1 << endl;

  v1.push_back(21);
  cout << "V1: " << v1 << endl;

  for (int i = 0; i < 11; i++){
    cout << "POPPED: " << v1.pop_back() << endl;
    cout << "V1: " << v1 << endl;
  }
  
  print_array(b, 9, 9);
  int* c = reallocate(b, 5, 5);
  print_array(c, 4, 4);


  // cout << "BACK: " << v1.back() << endl;

  // v1.back() = 1291293828;
  // cout << "BACK: " << v1.back() << endl;

  // cout << "FRONT: " << v1.front() << endl;

  // v1.front() = 9898988;
  // cout << "FRONT: " << v1.front() << endl;


  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_INITIAL, TestInitial) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_initial(false));
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

