#include <stdio.h>
#include <stdlib.h>

typedef unsigned short int	Bool;
#define TRUE			1
#define FALSE			0

#define DEBUG	TRUE

#define ER(m, x)	do						\
			{						\
				if(DEBUG)				\
					fprintf(stderr,			\
						"DBGER: "		\
						#x			\
						" => "			\
						#m			\
						"\n");			\
			}						\
			while(0)

#define ERX(m, x)	do						\
			{						\
				if(DEBUG)				\
					fprintf(stderr,			\
						"DBGERX: "		\
						#x			\
						" => "			\
						#m			\
						"\n");			\
				exit(x);				\
			}						\
			while(0)

#define SIZEGRID	9		// 9x9 grid

typedef unsigned short int	GridElem;

void readgrid(GridElem [SIZEGRID][SIZEGRID], FILE*);
Bool evaluategrid(GridElem [SIZEGRID][SIZEGRID]);
void printgrid(GridElem [SIZEGRID][SIZEGRID]);

