// Xmake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

#include "function.h"
using namespace std;

int main(int argc, char** argv) {
    string version = "0.1.0";

    string arg;
    for (int i = 0; i < argc; ++i)
    {
        arg = argv[i];
        if (arg == "-f") {
            ifstream file(argv[1]);
            if (file.is_open()) {
                string line;
                while (getline(file, line))
                {
                    if (line.rfind("//", 0) == 0) { //comment
                        line.erase(0, 1);
                        continue;
                    }
                    if (line.rfind("$", 0) == 0) { //function
                        if (line == "$" + string(argv[3])) {
                            run_function(string(argv[3]), string(argv[1]));
                        }
                    }
                }
            }
            return 0;
        }
        if (arg == "--init") {
            string filename;
            cout << "Enter filename>";
            std::cin >> filename;
            ofstream file;
            file.open(filename);
            file << "//Xmake File\n$main\necho 'This is a command'";
            file.close();

        }
    }
    ifstream file(argv[1]);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            if (line.rfind("//", 0) == 0) { //comment
                line.erase(0, 1);
                continue;
            }
            if (line.rfind("$", 0) == 0) { //function
                line.erase(0, 1);
                continue;
            }
            if (line.rfind("!EXIT", 0) == 0) { //function
                line.erase(0, 1);
                return 0;
            }
            if (line.rfind("!PAUSE", 0) == 0) { //function
                line.erase(0, 1);
                string input;
                cout << "Press enter to continue>";
                std::cin >> input;
                input.clear();
                continue;
            }
            system(line.c_str());
        }
    }

}