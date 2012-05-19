#include <sudokusolver.h>

GridElem grid[SIZEGRID][SIZEGRID];

int main(int argc, char* argv[])
{
	if(argc < 2)
		ERX("Incorrect Usage", 1);
	
	const char* mode = "r";
	FILE* f = fopen((const char*) argv[1], mode);
	if(!f)
		ERX("Error Opening File", 4);
	readgrid(grid, f);
	fclose(f);

/*
	if(!evaluategrid(grid))
		ERX("Could Not be Solved", 3);
*/	

	printgrid(grid);

	return 0;
}

