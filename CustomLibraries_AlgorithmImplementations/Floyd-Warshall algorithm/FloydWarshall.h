// uses Adjacency Matrix (AM) implemented as a 1D array.
// only integer weights are allowed for the time being.
// vertex id is unsigned integer.

//TODO: this implementation can cater for only one graph at a time. \
		figure out how to make it compute for multiple graphs at a \
		time. \
		the main problem is the _apspl_, _n_ and isinittoINFINITY.

#include <stdio.h>

#define DBG 1						// Debug
#define INFINITY	2000000001		// 2 * 10^9 + 1

typedef unsigned int ui;
typedef unsigned short int usi;

typedef enum _boolean
		{
			FALSE,
			TRUE
		}
						boolean;

void FWinitAM(ui n);	// can be as large as 10^3.
void FWpopulateAM(ui u, ui v, int w);	// w can be as large as 10^9
void FWassigntoAM(int* source);	// source is an n * n 1D array. \
								   does not alter the source.
void FWcomputeAPSPL();	// APSPL = All-Pair Shortest Path-Lengths.
boolean FWqueryshortestpath(ui u, ui v, int* w);	// returns whether \
													   u->v isNOTinfinity\
													   or not. weight \
													   of u->v is set \
													   in w.
void FWprintAM(FILE* outputfilestream);

