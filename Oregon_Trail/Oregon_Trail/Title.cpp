#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void titleScreen()
{
	ifstream f("title.txt");
	string line;
	getline(f, line);
	for (int i = 0; i < 17; i++) {
		cout << line << endl;
		getline(f, line);
	}
	
	f.close();
}