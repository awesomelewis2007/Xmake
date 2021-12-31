//Xmake Main file 
//GitHub: https://github.com/awesomelewis2007/Xmake
//[Args]
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <stdlib.h>
#include "Xmake.h"
#include "Global.h" // <-- includes global varibles
using namespace std;

int main(int argc, char** argv) {
    string version = ver;
    bool verbose = false;
    string arg;
    for (int i = 0; i < argc; ++i)
    {
        arg = argv[i];
        if (arg == "--help") {
            help();
        }
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
            exit(0);
        }
        if (arg == "--init") {
            string filename;
            cout << "Enter filename>";
            cin >> filename;
            string description;
            cout << "Enter description>";
            cin >> description;
            ofstream file;
            file.open(filename);
            file << "//Xmake file\n//" << description << "\n";
            file << "$main\necho 'This is a command'";
            file.close();
            exit(0);
        }
        if (arg == "-v") {
            verbose = true;
        }
        if (arg == "--version") {
            cout << version << "\n";
            exit(0);
        }
    }
    ifstream file(argv[1]);
    int n_command = 1;
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
                if (verbose) {
                    cout << "F" << "  |" << line << "\n";
                }
                continue;
            }
            if (line.rfind("!EXIT", 0) == 0) { //exit
                line.erase(0, 1);
                if (verbose) {
                    cout << "exiting due to a !EXIT call\n";
                }
                exit(0);
            }
            if (line.rfind("!PAUSE", 0) == 0) { //pause
                line.erase(0, 1);
                string input;
                cout << "Press enter to continue>";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                input.clear();
                continue;
            }
            if (line.rfind("Always:", 0) == 0) { //always run
                line.erase(0, 7);
                if (verbose) {
                    cout << "A" << n_command << " |" << line << "\n";
                    n_command = n_command + 1;
                }
                system(line.c_str());
                continue;
            }
            if (verbose) {
                cout << "C" << n_command << " |" << line << "\n";
                n_command = n_command + 1;
            }

            system(line.c_str());
        }
    }
    else {
        cout << "Cant find file\n";
    }

}