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

#define MAXSIZEEXCHANGE		4500
#define MAXSIZEPERMUTATION	101

bitset<MAXSIZEEXCHANGE> exchange;
usi permutation[MAXSIZEPERMUTATION + 1];

usi k;
ui sizeexchange;
#define sizepermutation		(k + 1)

#define MAP(x, y)	(((k - x) * (k - x - 1)) / 2 + (k - y))

//DBG_BEGIN
void printbitset()
{
	cerr //<< endl
		 << "\t\t"
		 << exchange.to_ulong()
		 << endl;
	string exchangestr = exchange.to_string();
	exchangestr = string(exchangestr.end() - sizeexchange, exchangestr.end());
	for(int sum = 0, i = k - 1; i > 0; i--)
	{
		cerr << "\t\t";
		for(int j = 0; j < k - i - 1; j++)
			cerr << " ";
		cerr << string(exchangestr.begin() + sum, exchangestr.begin() + sum + i)
			 << endl;
		sum += i;
	}
}
//DBG_END

set<usi> indicescomputed;

void individualcomputetransitions(usi root)
{
	assert(indicescomputed.insert(root).second);
	// isolate the part of bitset used by root. //TODO: check if \
												  vertical part \
												  needs to be \
												  checked too.
	// => from root + 1 to k
	// check if the size of this part is non-zero. terminate if zero.
	if(root + 1 == k)
		return;
	// iteratively check if this part has any 1. if found, recursively \
	   compute the transistions of the index pointed to (say, child).
	for(usi child = root + 1; child <= k; child++)
	{
		if(		exchange[MAP(root, child)]
			&&	indicescomputed.find(child) == indicescomputed.end())
			individualcomputetransitions(child);
		// isolate the horizontal part of bitset used by child.
		// => from child + 1 to k
		// traverse this part and add 1's to all the indices for which \
		   the child has 1's.
		for(usi childiterator = child + 1; childiterator <= k; childiterator++)
			if(exchange[MAP(child, childiterator)])
				exchange.set(MAP(root, childiterator), true);
		// isolate the vertical part of bitset of child.
		// => from 1 to child - 1
		// traverse this part and add 1's to all the indices for which \
		   the child has 1's.
		for(usi childiterator = 1; childiterator <= child - 1; childiterator++)
			if(exchange[MAP(childiterator, child)] && root < childiterator)
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
	sizeexchange = (k * (k - 1)) / 2;
	
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
				 << endl;
		//DBG_END

		if(i < j)
		{
			
			//DBG_BEGIN
			if(DBG)
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

	return 0;
}
