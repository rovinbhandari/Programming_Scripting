// uses Adjacency Matrix (AM) implemented as a 1D array.
// only integer weights are allowed for the time being.
// vertex id is unsigned integer.

#define DBG 1						// Debug
#define INFINITY	2000000001		// 2 * 10^9 + 1

typedef unsigned int ui;
typedef unsigned short int usi;

void FWinitAM(ui n);	// can be as large as 10^3.
void FWpopulateAM(ui u, ui v, int w);	// w can be as large as 10^9
void FWassigntoAM(int* source);	// source is an n * n 1D array. \
								   does not alter the source.
void FWcomputeAPSPL();	// APSPL = All-Pair Shortest Path-Lengths.
int FWqueryshortestpath(ui u, ui v);
void FWprintAM();

