#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>

#include "../../includes/array_functions/array_functions.h"

using namespace std;

void fill_array(int* p, int size){
  int* walker = p;
  for(int i = 0; i < size; i++){
    *walker = i*10;
    walker++;
  }
}

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_allocate(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_allocate" << endl;
  }
  int size = 7;
  int capacity = 10;
  int *a = allocate<int>(capacity);
  fill_array(a, size);
  print_array(a, size, capacity);

  return true;
}

bool test_copy_array(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_copy_array" << endl;
  }
  int size = 9;
  int capacity = 10;
  int *a = allocate<int>(capacity);
  fill_array(a, size);
  print_array(a, size, capacity);

  int *b = copy_array(a, size);
  print_array(b, size, size);

  int *c;
  size = 5;
  c = new int[size];
  copy_array(c, a, size);
  print_array(c, size, size);

  return true;
}

bool test_print_array(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_print_array" << endl;
  }

  int size = 7;
  int capacity = 10;
  int* p;
  p = new int[capacity];
  fill_array(p, size);

  cout << "\n\n-----------------------\n\n";
  print_array(p, size, capacity);
  cout << "\n-----------------------\n\n";
  delete p;

  return true;
}

bool test_print(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_print" << endl;
  }
  int size = 7;
  int capacity = 10;
  int* p;
  p = new int[capacity];
  fill_array(p, size);

  cout << "\n\n-----------------------\n\n";
  print(p, 5);
  cout << "\n-----------------------\n\n";
  delete p;

  return true;
}

bool test_search_entry(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_search_entry" << endl;
  }
  int size = 7;
  int capacity = 10;
  int* p;
  p = new int[capacity];
  fill_array(p, size);

  int key;
  int *found;
  int correct = 0;

  key = 30;
  found = search_entry(p, size, key);
  if (found){
    correct++;
  }


  key = 35;
  found = search_entry(p, size, key);
  if (!found){
    correct++;
  }


  delete p;
  if (correct == 2)
    return true;
  else
    return false;
}

bool test_search(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_search" << endl;
  }
  int size = 7;
  int capacity = 10;
  int* p, *found;
  p = new int[capacity];
  fill_array(p, size);

  int correct = 0;

  int found_index;
  int key;
  key = 30;
  found_index = search(p, size, key);
  if (found_index>=0){
    correct++;
  }
  

  key = 35;
  found_index = search(p, size, key);
  if (!(found_index>=0)){
    correct++;
  }

  delete p;
  if (correct == 2)
    return true;
  else
    return false;
}

bool test_shift_left(bool debug = false){
  int size = 11;
  int capacity = 20;
  int* a, *found;
  a = new int[capacity]{0,0,10,20,20,30,30,40,50,60,60};
  
  int key, *mark;

  cout << "\n\narray now:  " ;
  print_array(a, size, capacity);


  key = 60;
  cout << " - shift left at "<<key<<":";
  mark = search_entry(a, size, key);
  shift_left(a, size, mark);
  print_array(a, size, capacity);




  cout << " - shift left at index 5:";
  
  shift_left(a, size, 5);
  print_array(a, size, capacity);



  key = 20;
  cout << " - shift left at "<<key<<":";
  mark = search_entry(a, size, key);
  shift_left(a, size, mark);
  print_array(a, size, capacity);


  
  cout << " - shift left at index 2:";
  
  shift_left(a, size, 2);
  print_array(a, size, capacity);

  return true;
}

bool test_shift_right(bool debug = false){
  int size = 7;
  int capacity = 10;
  int* a, *found;
  a = new int[capacity]{0,10,20,30,40,50,60};
  
  int key, *mark;

  cout << "\n\narray now:  " ;
  print_array(a, size, capacity);


  key = 30;
  cout << " - shift right at "<<key<<":";
  mark = search_entry(a, size, key);
  shift_right(a, size, mark);
  print_array(a, size, capacity);

  key = 60;
  cout << " - shift right at index 5:";
  shift_right(a, size, 5);
  print_array(a, size, capacity);

  key = 0;
  cout << " - shift right at  "<<key<<":";
  shift_right(a, size, 0);
  print_array(a, size, capacity);

  return true;
}

bool test_array_string(bool debug = false){
  int size = 7;
  int capacity = 10;
  int* a, *found;
  a = new int[capacity]{0,10,20,30,40,50,60};

  cout << "        array now:  " ;
  print_array(a, size, capacity);
  cout << "  array to string: " << array_string(a, size) << endl;

  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_PRINT_ARRAY, TestPrintArray) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_print_array(false));
}

TEST(TEST_PRINT, TestPrint) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_print(false));
}

TEST(TEST_SEARCH_ENTRY, TestSearchEntry) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_search_entry(false));
}

TEST(TEST_SEARCH, TestSearch) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_search(false));
}



TEST(TEST_ARRAY_STRING, TestArrayString) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_array_string(false));
}

TEST(TEST_ALLOCATE, TestAllocate) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_allocate(false));
}

TEST(TEST_COPY_ARRAY, TestCopyArray) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_copy_array(false));
}

TEST(TEST_SHIFT_LEFT, TestShiftLeft) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_shift_left(false));
}

TEST(TEST_SHIFT_RIGHT, TestShiftRight) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_shift_right(false));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

