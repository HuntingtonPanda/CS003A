#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
#include "../../includes/poly/poly.h"
#include "../../includes/array_functions/array_functions.h"
using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}



bool test_ahh(bool debug = false)
{
  double coefs1[] = {8.0,5.0,6.0,0.0,4.0};
  double coefs2[] = {2.0,7.0,3.0,0.0, 1.0, 9.0};
  Poly p(coefs1, 4);
  Poly q(coefs2, 5);
  Term t(10, 5);
  Term d(30, 9);

  cout << "p: " << p << endl;
  cout << "q: " << q << endl;
  cout << "t: " << t << endl;

  cout << "p[0]: " << p[0] << "\n";
  
  cout << "p[4]: "<< p[4] << "\n";

  Poly NewP(p);
  cout << "NewP: " << NewP << endl;
  cout << "NewP + t: " << NewP + t << endl;
  cout << "woowwww\n";
  cout << "NewP + p[0] + p[4]: " << NewP + p[0] + p[4]<< endl;
  cout << "woowwww\n";
  cout << "NewP: " << NewP << endl;

  cout << "NewP + q: " << NewP + q << endl;


  // cout << "p + t: " << p + t << endl;
  // cout << "woowwww\n";

  // cout << "p + t: " << p + t << endl;
  // cout << "woowwww\n";
  // cout << "p + q: " << p + q << endl;
  // cout << "woowwww\n";


  // cout << "p * t: " << p * t << endl;
  // cout << "woowwww\n";
  // cout << "p * d: " << p * d << endl;
  // cout << "woowwww\n";

  // cout << "(p+q) - p == q? " << boolalpha << (((p + q) - p) == q) << endl;
  // cout << (p + q) - p << " <000> " << q << endl;

  // cout << "p * q: " << p * q << endl;
  // cout << "p * q   : [+36.0X^9 +4.0X^8 +54.0X^7 +63.0X^6 +105.0X^5 +34.0X^4 +57.0X^3 +71.0X^2 +66.0X +16.0 ]" << endl;


    // Poly r = p / q;
    // cout<<p<<" / "<<q<<endl;
    // cout<<"      = "<<r;
    // cout<<"  rem = "<<p % q<<"  ";
    // //if r = p / q then r * q + p % q should be equal to p:
    // if(r * q + p % q == p){
    //     cout<<"VERIFIED"<<endl;
    // }
    // else{
    //     cout<<endl<<"   ***VERIFICATION FAILED"<<endl;
    //     cout<<"   r * q: "<<r * q<<endl;
    //     cout<<"   p % q: "<<p % q<<endl;
    //     cout<<"   r * q + p % q: "<<r * q + p % q<<"=/="<<p<<endl;
    // }
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_ahh, TestAhh) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_ahh(false));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

