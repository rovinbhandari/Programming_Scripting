#include <set>
#include <string>
#include <bitset>
#include <cstdio>
#include <cassert>
using namespace std;

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

set<usi> indicescomputed;

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
			if(exchange[MAP(i, j)] && permutation[j] < minvalue)
			{
				minvalue = permutation[j];
				minindex = j;
			}
		if(minindex != i)
		{
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
	
	for(i = 1; i < sizepermutation; i++)
		scanf(FORMATusi, &permutation[i]);
	
	i = j = 1;
	while(c = getchar())
	{
		if(!(c == 'N' || c == 'Y'))
			continue;

		if(i < j)
		{
			if(c == 'N')
				exchange.set(MAP(i, j), false);
			else if(c == 'Y')
				exchange.set(MAP(i, j), true);
		}
		
		j++;
		if(j == sizepermutation)
		{
			j = 1;
			i++;
		}
		if(i == sizepermutation)
			break;
	}

	computetransitions();

	smallestpermutation();

	for(i = 1; i < sizepermutation; i++)
		printf(FORMATusi " ", permutation[i]);

	return 0;
}
