// Xmake help file
// This script is only run when the --help argument is used
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

#include "Xmake.h"

using namespace std;
int help() {
	cout << "This is the Xmake help file \n";
	cout << "Xmake is an alternative to Make\n";
	cout << "Xmake has its own syntax\n";
	cout << "\n";
	cout << "Syntax\n";
	cout << "https://github.com/awesomelewis2007/Xmake#syntax\n";
	cout << "\n";
	cout << "To define a function use a $ sign to define a function like this\n";
	cout << "Anything that has no !,// or $ is a command that is sent to the OS\n";
	cout << "An ! is a command that is sent to Xmake\n";
	cout << "\n";
	cout << "!PAUSE\n";
	cout << "This will pause the Xmake script untill a enter key is pressed\n";
	cout << "!EXIT\n";
	cout << "This stops the program\n";
	cout << "\n";
	cout << "Comments\n";
	cout << "A comment is made by adding // to the start of the line\n";
	return 0;
}