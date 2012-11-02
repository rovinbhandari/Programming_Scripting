#include <set>
#include <vector>
#include <string>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <iostream>
using namespace std;

#define DBG true
/*
	
	//DBG_BEGIN
	if(DBG)
	{

	}
	//DBG_END

*/

typedef unsigned short int	usi;
#define FORMATusi			"%hu"

typedef unsigned int		ui;

#define MAXSIZEEXCHANGE		10201
#define MAXSIZEPERMUTATION	101

bitset<MAXSIZEEXCHANGE> exchange;
usi permutation[MAXSIZEPERMUTATION + 1];

usi k;
ui sizeexchange;
#define sizepermutation		(k + 1)

#define MAP(x, y)	((k - x) * k + (k - y))

//DBG_BEGIN
void printbitset()
{
	string exchangestr = exchange.to_string();
	exchangestr = string(exchangestr.end() - sizeexchange, exchangestr.end());
	cerr //<< endl
		 << "\t\t"
		 << exchangestr
		 << endl;
	const char* exchangecstr = exchangestr.c_str();
	//cerr << endl;
	for(int i = 1; i <= k; i++)
	{
		cerr << "\t\t";
		for(int j = 1; j <= k; j++)
			cerr << exchangecstr[(i - 1) * k + (j - 1)]
				 << " ";
		cerr << endl;
	}
}
//DBG_END

set<usi> depthfirstvisited;
vector<usi> depthfirstvisitedtemp;
set<usi> indicescomputed;
vector<usi> indicescomputedtemp;

set<usi> individualcomputetransitions(usi x)
{
	
	//DBG_BEGIN
	if(DBG)
	{
		cerr << "Computing transitions for: "
			 << x
			 << endl;
	}
	//DBG_END
	
	depthfirstvisited.insert(x);
	depthfirstvisitedtemp.push_back(x);
	set<usi> indicestoset;
	set<usi> indicestoreturn;
	for(usi y = 1; y <= k; y++)
	{
	
		//DBG_BEGIN
		if(DBG)
		{
			cerr << "\ty = "
				 << y
				 << endl;
		}
		//DBG_END

		if(!exchange[MAP(x, y)])
			continue;
		
		indicestoreturn.insert(y);
		
		if(indicescomputed.find(y) != indicescomputed.end())
		{
			// found
		
			//DBG_BEGIN
			if(DBG)
			{
				cerr << "\t"
					 << y
					 << " is already computed."
					 << endl;
			}
			//DBG_END
			
			continue;
		}
		
		//DBG_BEGIN
		if(DBG)
		{
			cerr << "\t"
				 << y
				 << " is NOT already computed."
				 << endl;
		}
		//DBG_END
		
		// not found in computed list.

		if(depthfirstvisited.find(y) == depthfirstvisited.end())
		{
			// not found in visited list.
			
			//DBG_BEGIN
			if(DBG)
			{
				cerr << "\t"
					 << y
					 << " is NOT already visited."
					 << endl;
			}
			//DBG_END
			
			indicestoset = individualcomputetransitions(y);
		}

		//DBG_BEGIN
		if(DBG)
		{
			cerr << "\t"
				 << y
				 << " is already visited."
				 << endl;
		}
		//DBG_END
			
		//DBG_BEGIN
		if(DBG)
		{
			cerr << "\tindicestoset: ";
			for(set<usi>::iterator it = indicestoset.begin();
					it != indicestoset.end(); it++)
				cerr << *it << " ";
			cerr << endl;
		}
		//DBG_END

		for(set<usi>::iterator it = indicestoset.begin();
				it != indicestoset.end(); it++)
		{
			indicestoreturn.insert(*it);
			if(x != *it)
				exchange.set(MAP(x, *it), true);
		}
	}

	//DBG_BEGIN
	if(DBG)
	{
		cerr << "\tindicestoreturn: ";
		for(set<usi>::iterator it = indicestoreturn.begin();
				it != indicestoreturn.end(); it++)
			cerr << *it << " ";
		cerr << endl;
	}
	//DBG_END

	indicescomputed.insert(x);
	indicescomputedtemp.push_back(x);
	depthfirstvisited.erase(x);

	return indicestoreturn;
}

void computetransitions()
{
	for(usi i = 1; i < k; i++)
		// if i is present in indicescomputed, it is taken \
		   care of already, otherwise, \
		   individualcomputetransitions(i) needs to be evoked.
		if(indicescomputed.find(i) == indicescomputed.end())
			individualcomputetransitions(i);
	
	//DBG_BEGIN
	if(DBG)
	{
		cerr << "Final values:";
		cerr << endl;
		cerr << "\tDepth First Visited List: ";
		for(vector<usi>::iterator it = depthfirstvisitedtemp.begin();
				it != depthfirstvisitedtemp.end(); it++)
			cerr << *it << " ";
		cerr << endl;
		cerr << "\tComputed List: ";
		for(vector<usi>::iterator it = indicescomputedtemp.begin();
				it != indicescomputedtemp.end(); it++)
			cerr << *it << " ";
		cerr << endl;
	}
	//DBG_END
}

void smallestpermutation()
{
	// for each i starting from 1, find the smallest value \
	   that can be reached from i. Once found, swap the \
	   current value at i in permutation[] with that value.
	for(usi i = 1; i < sizepermutation - 1; i++)
	{
		usi minvalue = permutation[i], minindex = i;
		for(usi j = i + 1; j < sizepermutation; j++)
		{
			if(exchange[MAP(i, j)] && permutation[j] < minvalue)
			{
				minvalue = permutation[j];
				minindex = j;
			}
		}
		if(minindex != i)
		{
			
			//DBG_BEGIN
			if(DBG)
				cerr << "swapping values at indices "
					 << i
					 << " and "
					 << minindex
					 << endl;
			//DBG_END

			usi temp = permutation[i];
			permutation[i] = permutation[minindex];
			permutation[minindex] = temp;
		}
	}				
}

int main(void)
{
	int i, j;
	char c;
	scanf(FORMATusi, &k);
	sizeexchange = k * k;
	
	//DBG_BEGIN
	if(DBG)
		cerr << "sizepermutation = "
			 << k
			 << endl
			 << "sizeexchange = "
			 << sizeexchange
			 << endl;
	//DBG_END
	
	for(i = 1; i < sizepermutation; i++)
		scanf(FORMATusi, &permutation[i]);
	
	//DBG_BEGIN
	if(DBG)
	{
		cerr << "permutation :";
		for(i = 0; i < sizepermutation; i++)
			cerr << " "
				 << permutation[i];
		cerr << endl;
	}
	//DBG_END
	
	i = j = 1;
	while(c = getchar())
	{
		if(!(c == 'N' || c == 'Y'))
			continue;
		
		//DBG_BEGIN
		if(DBG)
			cerr << "read '"
				 << c
				 << "' at ("
				 << i
				 << ", "
				 << j
				 << ")"
				 << " storing at position "
				 << MAP(i, j)
				 << " in exchange[]"
				 << endl;
		//DBG_END

		if(c == 'N')
			exchange.set(MAP(i, j), false);
		else if(c == 'Y')
			exchange.set(MAP(i, j), true);
		
		//DBG_BEGIN
		if(0 && DBG)
		{
			cerr << "exchange :\t";
			printbitset();
		}
		//DBG_END

		j++;
		if(j == sizepermutation)
		{
			j = 1;
			i++;
		}
		if(i == sizepermutation)
			break;
	}

	//DBG_BEGIN
	if(DBG)
	{
		cerr << "exchange :\t";
		printbitset();
	}
	//DBG_END

	computetransitions();

	//DBG_BEGIN
	if(DBG)
	{
		cerr << "exchange :\t";
		printbitset();
	}
	//DBG_END

	/*
	smallestpermutation();

	//DBG_BEGIN
	cerr << "smallest permutation :";
	for(i = 0; i < sizepermutation; i++)
		cerr << " "
			 << permutation[i];
	cerr << endl;
	//DBG_END

	for(i = 1; i < sizepermutation; i++)
		printf(FORMATusi " ", permutation[i]);
	*/

	return 0;
}
