#include <string>
//#include <fstream>
#include <iostream>
using namespace std;

class node
{
	private:
			string word;
			node *next;
	public:
			node();
			node * pointnext();
			//void setwords(ifstream);
			void setword(node *);
			void printwords(node *);
};
