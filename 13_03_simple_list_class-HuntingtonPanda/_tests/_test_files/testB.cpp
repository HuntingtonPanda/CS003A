#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
using namespace std;

#include "../../includes/list_simple/list_simple.h"
#include "../../includes/linked_list_functions/linked_list_functions.h"
#include "../../includes/node/node.h"

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
    cout << "testB:: test-initial" << endl;
  }
  cout << "\n\n\n---------------------\n";

  // int hi = 5;
  // node<int> ah(hi);
  // cout << ah;

  List<int> list;
  node<int> *marker;

  node<int> *TAG;



  cout << "list.empty(): " << boolalpha << list.empty() << endl;

  list.Print();

  list.insert_head(20);
  list.insert_head(10);

  list.Print();

  marker = list.search(20);

  cout << "THIS IS MARKER: " << *marker << endl;

  TAG = list.insert_after(30, marker);

  list.Print();

  cout << "THIS IS TAG(after): " << *TAG << endl  << endl;

  TAG = list.insert_before(15, marker);

  list.Print();

  cout << "THIS IS TAG(before): " << *TAG << endl << endl;

  //TAG = list.insert_sorted(22);

  list.Print();

  cout << list << " IDK ";

  cout << "THIS IS TAG(sorted): " << *TAG << endl << endl;

  int Marked = list.Delete(TAG);

  cout << "Marked: " << Marked << endl << list << "\n\n"; 



//--------------------------------------//
cout << "\n ---> TESTING BEGINNING EDGE <---\n";

List<int> list2;

cout << list2;

list2.insert_after(99, TAG);

cout << list2;

list2.Delete(list2.begin());

cout << list2;

//-------------------------------------//

//--------------------------------------//
cout << "\n ---> TESTING INSERT AFTER <---\n";

List<int> list4;



cout << "LIST 4: "<< list4;


list4.insert_after(1, list4.begin());
list4.insert_after(2, list4.begin());
list4.insert_after(3, list4.begin());

cout << "LIST 4: "<< list4;

cout << *list4.begin();
cout << *list4.end() << "\n\n";

list4.insert_after(4, list4.end());
list4.insert_after(5, list4.end());

cout << "LIST 4: "<< list4;

list4.insert_after(6, list4.search(4));
list4.insert_after(7, list4.search(4));

cout << "LIST 4: "<< list4;



//-------------------------------------//

//--------------------------------------//
cout << "\n ---> TESTING INSERT BEFORE <---\n";

List<int> list5;



cout << "LIST 5: "<< list5;


list5.insert_before(1, list5.begin());
cout << "LIST 5: "<< list5;
list5.insert_before(2, list5.begin());
cout << "LIST 5: "<< list5;
list5.insert_before(3, list5.begin());

cout << "LIST 5: "<< list5;

cout << *list5.begin();
cout << *list5.end() << "\n\n";

list5.insert_before(4, list5.end());
list5.insert_before(5, list5.end());

cout << "LIST 5: "<< list5;

list5.insert_before(6, list5.search(4));
list5.insert_before(7, list5.search(4));

cout << "LIST 5: "<< list5;

cout << "\n ---> TESTING DELETE <---\n";



//-------------------------------------//

//--------------------------------------//
cout << "\n ---> TESTING COPY LIST <---\n";

List<int> list3(list);

cout << "LIST 3: " << list3;

list.insert_head(299);

list3.insert_head(288);

cout << "LIST 1: "<< list;

cout << "LIST 3: "<< list3;

cout << "LIST 3 @ index 2: "<< list3[2] << endl;

list3[2] = 30;

cout << "LIST 3: "<< list3;

cout << "\nTESTING prev AND search\n\n";

node<int> *marker2 = list3.search(30);

cout << *marker2;

marker2 = list3.prev(marker2);

cout << *marker2;

//-------------------------------------//


/*
//--------------------------------------//
cout << "\n ---> TESTING COPY LIST <---\n";

List<int> aList;
node<int> *aMarker;

node<int> *aTAG;

aList.Print();

aList.insert_head(80);
aList.insert_head(70);
aList.insert_head(60);
aList.insert_head(50);
aList.insert_head(40);
aList.insert_head(30);
aList.insert_head(20);
aList.insert_head(10);

aList.Print();

aMarker = aList.search(20);

cout << "THIS IS MARKER: " << *aMarker << endl;

aTAG = aList.insert_after(30, aMarker);

aList.Print();

cout << "THIS IS TAG(after): " << *aTAG << endl  << endl;

aTAG = list.insert_before(15, marker);

list.Print();

cout << "THIS IS TAG(before): " << *TAG << endl << endl;

TAG = list.insert_sorted(22);
//--------------------------------------//
*/



  cout << "\n\n\n---------------------\n";
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

