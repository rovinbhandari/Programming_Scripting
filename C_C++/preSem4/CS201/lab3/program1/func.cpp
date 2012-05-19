#include "head.h"
#include <string>
#include <iostream>
//#include <fstream>
using namespace std;

node :: node()
{
	this->word = "";
	this->next = 0;
}

node * node :: pointnext()
{
	return (next);
}

void node :: setword(node * p, string t)
{
	strcpy(p->word,t);
}

/*void node :: setwords(ifstream f)
{
	f.getline(word,256);
}*/

/*void printwords(node * first)
{
	while(*/
