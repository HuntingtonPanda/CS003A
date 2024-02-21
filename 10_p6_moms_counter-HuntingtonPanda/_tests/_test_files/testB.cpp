#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
using namespace std;

#include "../../includes/mcounter/mcounter.h"

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_MCounter(bool debug = false)
{
  MCounter m;
  cout << "+1: " << m.add_1() << endl;
  cout << "+10: " << m.add_10() << endl;
  cout << "+100: " << m.add_100() << endl;
  cout << "+1000: " << m.add_1000() << endl;
  cout <<"count: "<< m.count() << endl;
  if (m.error()){
    cout << "THERE'S AN ERROR " << endl;
    }
    else{
      cout << "NO ERROR" << endl;
  }

  cout << "ERROR: " << boolalpha << m.error() << endl;
  cout << endl;
  for (int i = 0; i < 20 && !m.error(); i++)
  {
    cout << "adding another 1000: " << m.add_1000() << endl;
    if (m.error()){
      cout << "THERE'S AN ERROR " << endl;
    }
    else{
      cout << "NO ERROR" << endl;
    }
  }
  cout << endl;
  cout << "ERROR: " << boolalpha << m.error() << endl;
  cout << "+1: " << m.add_1() << endl;
  cout << "+10: " << m.add_10() << endl;
  cout << "+100: " << m.add_100() << endl;
  cout << "+1000: " << m.add_1000() << endl;
  m.reset();
  cout << endl;
  cout << "RESET: " << m.count() << endl;
  cout << "ERROR: " << boolalpha << m.error() << endl;
  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_MCOUNTER, TestMCounter) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_MCounter(false));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

