#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
using namespace std;


#include "../../includes/stack/MyStack.h"
#include "../../includes/queue/MyQueue.h"

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_AH(bool debug = false)
{
  Stack<int> s1;

  cout << "stack.push(): " << endl;
  for (int i = 0; i < 5; i++)
  {
    s1.push(i);
    cout << s1 << endl;
  }

  //cout << "ahh 1\n";

  Stack<int> s2(s1);
  //cout << "ahh 2\n";

  Stack<int> s3;
  //cout << "ahh 3\n";

  s3 = s1;
  // cout << "ahh 4\n";

  cout << "s2: " << s2 << endl;
  cout << "s3: " << s3 << endl;

  cout << "s2 pop(x2): " << s2.pop() << " " << s2.pop() << endl;
  cout << "s2: " << s2 << endl;

  cout << "s3 top: " << s3.top() << endl;

  return true;
}

bool test_AHHH(bool debug = false)
{
  Queue<int> s1;

  cout << "Queue.push(): " << endl;
  for (int i = 0; i < 5; i++)
  {
    s1.push(i);
    cout << s1 << endl;
  }

  //cout << "ahh 1\n";

  Queue<int> s2(s1);
  //cout << "ahh 2\n";

  Queue<int> s3;
  //cout << "ahh 3\n";

  s3 = s1;
  // cout << "ahh 4\n";

  cout << "s2: " << s2 << endl;
  cout << "s3: " << s3 << endl;

  cout << "s2 pop(x2): " << s2.pop() << " " << s2.pop() << endl;
  cout << "s2: " << s2 << endl;

  cout << "s3 top: " << s3.front() << endl;

  return true;
}

TEST(TEST_AH, TestAH) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_AH(false));
}

TEST(TEST_AHHH, TestAHHH) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_AHHH(false));
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

