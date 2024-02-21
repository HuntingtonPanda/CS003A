#include <iostream>
#include <iomanip>
#include "includes/animate/animate.h"

using namespace std;

int main(int argv, char** argc) {
    cout << "\n\n"
         << endl;

    animate game;
    game.run();
    cout << "\n\n\n=====================" << endl;
    return 0;
}
