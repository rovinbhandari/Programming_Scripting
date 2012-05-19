#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	string filename,s;
	cin >> filename;
	ifstream f;
	f.open(filename);
	f.getline(s,100);
}
