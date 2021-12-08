// This is the function handler file
// This script is only used on the -f argument 
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

#include "Xmake.h"
int run_function(string function, string f) {
    ifstream file(f);
    string line;
    bool skip{};
    while (getline(file, line))
    {
        if (line.rfind("//", 0) == 0) { //comment
            continue;
        }
        if (line.rfind("$", 0) == 0) { //function
            line.erase(0, 1);
            if (line != function) {
                skip = true;
            }
            if (line == function) {
                skip = false;
                continue;
            }
        }
        if (line.rfind("!EXIT", 0) == 0) { //function
            if (skip == false) {
                line.erase(0, 1);
                return 0;
            }
        }
        if (line.rfind("!PAUSE", 0) == 0) { //function
            if (skip == false) {
                line.erase(0, 1);
                string input;
                cout << "Press enter to continue>";
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                input.clear();
                continue;
            }
        }
        if (skip == false) {
            system(line.c_str());
        }
    }
    return 0;
}