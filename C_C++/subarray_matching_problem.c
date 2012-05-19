/* Problem statement: Given two arrays A1 and A2, where, |A1| > |A2|,
 * find the indices in A1 where A2 occurs.
 *
 * Algorithm used: a hash function, a scan-and-check function and an iteration over A1
 * is used. Iteratively, a window of length |A2| is chosen in A1 and checked for 
 * a possible match by comparing the hashes hash(A1) and hash(A2). If matched,
 * then the possible chance of false alarm is checked using the scan-and-check
 * function which iterates over A2 and over |A2| elements of A1 starting from
 * the index of possible match. If matches, then the index of match in A1 is
 * printed, else, the iteration continues.
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int Bool;
enum BOOLEAN {False, True};

int hash(int*, int);
Bool scancheck(int*, int*, int);

int main(void)
{
	int* a1;	// pointer to first array, A1
	int* a2;	// pointer to second array, A2
	int l1, l2, i1, i2;	// lx is the length of array ax \
				ix is an iterator for array ax
	i1 = i2 = -1;

	// input a1
	scanf("%d", &l1);
	a1 = (int*) malloc(l1 * sizeof(int));
	while(++i1 < l1)
		scanf("%d", a1 + i1);
	
	// input a2
	scanf("%d", &l2);
	if(l2 > l1)
	{
		fprintf(stderr, "The second array cannot be longer than the first.\n");
		exit(1);
	}
	a2 = (int*) malloc(l2 * sizeof(int));
	while(++i2 < l2)
		scanf("%d", a2 + i2);
	
	// iterate over a1, checking for any possible matches \
	false alarms are ignored by scancheck()
	int h1, h2, nmatches = 0;
	h2 = hash(a2, l2);
	for(i1 = 0; i1 < l1 - l2 + 1; i1++)
		if(	(h1 = (i1 == 0) ? hash(a1, l2) : (h1 - *(a1 + i1 - 1) + *(a1 + i1 + l2 - 1)))	// fast hashing
			==
			h2
			&&
			scancheck(a1 + i1, a2, l2)		// detecting false alarms
		  )	
		{
			printf("MATCH AT: %d\n", i1);
			nmatches++;
		}
	if(!nmatches)
		printf("NO MATCHES\n");
	
	return 0;
}

int hash(int* a, int l)		// sum with overflow allowed;
{				// can be changed, but ^ fast hashing has to be changed accordingly.
	int h = 0;
	while(l--)
		h += *(a + l);
	return h;
}

Bool scancheck(int* a1, int* a2, int l2)
{
	int i = -1;
	while(++i < l2)
		if(*(a1 + i) != *(a2 + i))
			return False;
	return True;
}

