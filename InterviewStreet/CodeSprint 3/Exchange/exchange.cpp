#include <set>
#include <string>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <iostream>
using namespace std;

#define DBG true

typedef unsigned short int	usi;
#define FORMATusi			"%hu"

typedef unsigned int		ui;
#define FORMATui			"%u"

#define MAXSIZEEXCHANGE		4500
#define MAXSIZEPERMUTATION	101

bitset<MAXSIZEEXCHANGE> exchange;
usi permutation[MAXSIZEPERMUTATION];

usi k;
ui sizeexchange;
#define sizepermutation		k

#define MAP(x, y)	(((k - x) * (k - x - 1)) / 2 + (k - y))

//DBG_BEGIN
void printbitset()
{
	string exchangestr = exchange.to_string();
	exchangestr = string(exchangestr.end() - sizeexchange, exchangestr.end());
	cerr << exchangestr
		 << endl;
	cerr << "\t\t";
	for(int sum = 0, i = k - 1; i > 0; i--)
	{
		cerr << string(exchangestr.begin() + sum, exchangestr.begin() + sum + i)
			 << " ";
		sum += i;
	}
	cerr << endl
		 << "\t\t"
		 << exchange.to_ulong()
		 << endl;
}
//DBG_END

set<usi> indicescomputed;

void isolatepartofbitset(usi i, ui& bigindex, ui& smallindex)	// indices are inclusive
{
	if(i == k)
		bigindex = smallindex = 0;
	bigindex = MAP(i, k) - 1;
	i--;
	smallindex = MAP(i, k);
}

void individualcomputetransitions(usi root)
{
	assert(indicescomputed.insert(root).second);
	// isolate the part of bitset used by root.
	// => from root + 1 to k
	// check if the size of this part is non-zero. terminate if zero.
	if(root + 1 == k)
		return;
	// iteratively check if this part has any 1. if found, recursively \
	   compute the transistions of the index pointed to (say, child).
	for(usi child = root + 1; child <= k; child++)
	{
		if(exchange[MAP(root, child)])
			individualcomputetransitions(child);
		// isolate the part of bitset used by child.
		// => from child + 1 to k
		// traverse this part and add 1's to all the indices for which \
		   the child has 1's.
		for(usi childiterator = child + 1; childiterator <= k; childiterator++)
			if(exchange[MAP(child, childiterator)])
				exchange.set(MAP(root, childiterator), true);
	}
}

void computetransitions()
{
	for(usi i = 1; i < k; i++)
		// if i is present in indicescomputed, it is taken \
		   care of already, otherwise, \
		   individualcomputetransitions(i) needs to be evoked.
		if(indicescomputed.find(i) == indicescomputed.end())
			individualcomputetransitions(i);
}

void individualsmallestvalue(usi i)
{
	return;
}

void smallestpermutation()
{
	return;
}

int main(void)
{
	char c;
	scanf(FORMATusi, &k);
	sizeexchange = (k * (k - 1)) / 2;
	
	//DBG_BEGIN
	if(DBG)
		cerr << "sizeexchange = "
			 << sizeexchange
			 << endl;
	//DBG_END
	
	int i, j;
	for(i = 0; i < sizepermutation; i++)
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
	
	i = 1;
	j = 1;
	while(c = getchar())
	{
		if(!(c == 'N' || c == 'Y'))
			continue;
		
		//DBG_BEGIN
		if(0 && DBG)
			cerr << "read '"
				 << c
				 << "' at ("
				 << i
				 << ", "
				 << j
				 << ")"
				 << endl;
		//DBG_END

		if(i < j)
		{
			
			//DBG_BEGIN
			if(0 && DBG)
				cerr << "storing..."
					 << endl;
			//DBG_END
			
			if(c == 'N')
				exchange.set(MAP(i, j), false);
			else if(c == 'Y')
				exchange.set(MAP(i, j), true);
		}
		
		//DBG_BEGIN
		if(0 && DBG)
		{
			cerr << "exchange :\t";
			printbitset();
		}
		//DBG_END

		j++;
		if(j > sizepermutation)
		{
			j = 1;
			i++;
		}
		if(i > sizepermutation)
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

	smallestpermutation();

	return 0;
}
