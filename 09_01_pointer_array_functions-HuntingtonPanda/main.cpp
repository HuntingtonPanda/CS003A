#include <iostream>
#include <iomanip>


using namespace std;

int main(int argv, char** argc) {
    cout << "\n\n"
         << endl;
    char a[10] = {'c', 'b', 'c', 'd'};
    char* p = a;
    cout << *p;
    cout << "\n\n\n=====================" << endl;
    return 0;
}
