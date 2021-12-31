// This is the function handler file
// This script is only used on the -f argument 
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

#include "Xmake.h"
using namespace std;

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
        if (line.rfind("!EXIT", 0) == 0) { //exit
            if (skip == false) {
                line.erase(0, 1);
                return 0;
            }
        }
        if (line.rfind("!PAUSE", 0) == 0) { //pause
            if (skip == false) {
                line.erase(0, 1);
                string input;
                cout << "Press enter to continue>";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                input.clear();
                continue;
            }
        }
        if (skip == false) {
            system(line.c_str());
        }
        if (line.rfind("Always:", 0) == 0) { //always run
            line.erase(0, 7);
            system(line.c_str());
            continue;
        }
    }
    return 0;
}