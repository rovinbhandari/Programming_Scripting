#include "head.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	/*string filename;
	cout << "Enter the name of file : ";
	cin >> filename;
	ifstream f;
	f.open(filename);
	while(!f.eof)
	{*/
	int count = 0;
	node first;
	node * root, ptr;
	root = ptr = &first;
	string temp;	
	while(1)
	{
		cout << "\n	Enter word for current node : ";
		cin >> temp;
		if(temp == "")
		{
			continue;
		}
		if(temp == "_end_")
		{
			break;
		}
		count++;
		ptr = new node();
		
