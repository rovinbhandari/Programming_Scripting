#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXLENin	1000
#define MAXwords	500

typedef unsigned short int Bool;
#define False	0
#define True	1

int lenwords[MAXwords], iterwords;
char in[MAXLENin];

int w, h, f;
int nwords, nspaces, nrows, rows, ncols, cols;

void setrowscols(void)
{
	rows = nrows = h / f;
	cols = ncols = w / f;
}

Bool fits(void)
{
	if(iterwords == nwords - 1)
		return True;
	
	cols -= lenwords[iterwords];
	if(cols < 0)
		return False;
	else if(cols == 0)
	{
		rows--;
		if(rows < 0 && iterwords < nwords - 1)
			return False;
		
		cols = ncols;
		return fits();
	}
	else
	{
		int a;
	}


}

int main(void)
{
	int t, i, j, lenin;
	scanf("%d", &t);
	getchar();	// for removing the '\n' which comes along the ENTER of scanf

	char c;

	for(i = 1; i <= t; i++)
	{
		scanf("%d %d %[^\n]", &w, &h, in);
		
		printf("%s\n", in);

/*
		lenin = strlen(in);

		memset(lenwords, 0, MAXwords * sizeof(int));

		for(j = 0; j < lenin; j++)
		{
			c = in[j];
			if(c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
				lenwords[nwords]++;
			else if(c == ' ')
				nwords++;
		}
		nspaces = nwords - 1;

		f = (int) sqrt((w * h) / (float) lenin);
		setrowscols();

		if(((int) sqrt((w * h) / (float) (lenin - nspaces))) < 1)
		{
			printf("Case #%d: 0\n", i);
			continue;
		}

		iterwords = 0;

		while(!fits())
		{
			f--;
			setrowscols();
		}

		printf("Case #%d: %d\n", i, f);
*/

	}

	return 0;
}

