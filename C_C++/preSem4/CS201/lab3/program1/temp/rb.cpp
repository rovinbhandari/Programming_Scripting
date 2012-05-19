#include<cstdio>
#include<iostream>
#include<fstream>
using namespace std;

void usingc()
{
	FILE *f, *g;
	f = fopen("abc", "r");
	g = fopen("qwe", "w");
	int i = 0;
	char a [50];
	while(!feof(f))
	{
		fscanf(f, "%s", a);
		if(i % 2 == 0)
		{
			fprintf(g, "%s ", a);
		}	
		i++;
	}
}

void usingcpp()
{

}

int main()
{
	usingc();
	return 0;
}
