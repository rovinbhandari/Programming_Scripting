#include <set>
#include <bitset>
#include <cstdio>
using namespace std;

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

set<usi> depthfirstvisited;
set<usi> indicescomputed;

set<usi> individualcomputetransitions(usi x)
{
	depthfirstvisited.insert(x);
	set<usi> indicestoset;
	set<usi> indicestoreturn;
	for(usi y = 1; y <= k; y++)
	{
		if(!exchange[MAP(x, y)])
			continue;
		
		indicestoreturn.insert(y);
		
		if(indicescomputed.find(y) != indicescomputed.end())
			// found
			continue;
		
		// not found in computed list.

		if(depthfirstvisited.find(y) == depthfirstvisited.end())
			// not found in visited list.
			indicestoset = individualcomputetransitions(y);

		for(set<usi>::iterator it = indicestoset.begin();
				it != indicestoset.end(); it++)
		{
			indicestoreturn.insert(*it);
			if(x != *it)
				exchange.set(MAP(x, *it), true);
		}
	}
	indicescomputed.insert(x);
	depthfirstvisited.erase(x);
	return indicestoreturn;
}

void computetransitions()
{
	for(usi i = 1; i <= k; i++)
		// if i is present in indicescomputed, it is taken \
		   care of already, otherwise, \
		   individualcomputetransitions(i) needs to be evoked.
		if(indicescomputed.find(i) == indicescomputed.end())
			individualcomputetransitions(i);
	
	//TODO: optimize or find a way to eliminate the following loops.
	for(usi j1 = 2; j1 <= k; j1++)
		for(usi i1 = 1; i1 < j1; i1++)
			if(exchange[MAP(i1, j1)])
				for(usi j2 = j1 + 1; j2 <= k; j2++)
					exchange.set(MAP(j1, j2), 
						exchange[MAP(i1, j2)] ||
						exchange[MAP(j1, j2)]);
}

void smallestpermutation()
{
	// for each i starting from 1, find the smallest value \
	   that can be reached from i. Once found, swap the \
	   current value at i in permutation[] with that value.
	for(usi i = 1; i < sizepermutation - 1; i++) // the last value will \
													be automatically \
													adjusted.
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
	sizeexchange = k * k;
	
	for(i = 1; i < sizepermutation; i++)
		scanf(FORMATusi, &permutation[i]);
	
	i = j = 1;
	while(c = getchar())
	{
		if(!(c == 'N' || c == 'Y'))
			continue;
		
		if(c == 'N')
			exchange.set(MAP(i, j), false);
		else if(c == 'Y')
			exchange.set(MAP(i, j), true);
		
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
