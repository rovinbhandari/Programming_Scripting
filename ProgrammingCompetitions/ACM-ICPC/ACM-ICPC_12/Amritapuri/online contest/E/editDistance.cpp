#include <iostream>
#include <string>
using namespace std;
#define MAXLEN 1024

/* row indexes correspond to the text while the column indexes correspond to the pattern. */
int cost_table[MAXLEN + 1][MAXLEN + 1];
int parent[MAXLEN + 1][MAXLEN + 1];

#define MATCH 0
#define SUBS 0
#define DELETE 1
#define INSERT 2

void row_init(unsigned int i)		/* An empty text */
{
	for(int j=0; j <= i; j++)
	{	
		cost_table[0][j] = j;		/* j insertions between a 'j' length string and an empty text. */
		if (j > 0)
			parent[0][j] = INSERT;
		else
			parent[0][j] = -1;
	}	
}	

void column_init(unsigned int i)		/* An empty pattern */
{
	for(int j=0; j <= i; j++)
	{	
		cost_table[j][0] = j;		/* j deletions between a 'j' lenght text and an empty pattern */
		if (j > 0)
			parent[j][0] = DELETE;
		else
			parent[j][0] = -1;	
	}		
			
}


void goal_cell(string text, string pattern, unsigned int *i, unsigned int *j)
{
	*i = text.length();
	*j = pattern.length();
}	

void insert_out(string text, string pattern, unsigned int i, unsigned int j)
{
	
}	

void delete_out(string text, string pattern, unsigned int i, unsigned int j)
{

}

void match_out(string text, string pattern, unsigned int i, unsigned int j)
{

}


void edit_distance(string text, string pattern, unsigned int *x, unsigned int *y)
{
	/* fill the table of dynamic  programming */
	unsigned int tlen = text.length();
	unsigned int plen = pattern.length();

	row_init(plen);
	column_init(tlen);

	int opt[3];
	
	/* for filling (i,j), we need to look at (i-1,j-1) [MATCH], (i-1,j) [DELETE], (i,j-1) [INSERT] */
	/* Here we proceed row-wise and so the required entries for (i,j) are always present when needed. */
	for(int i=1; i <= tlen; i++)
	{
		for(int j=1; j <= plen; j++)
		{
		 	if (text[i-1] == pattern[j-1])
			{	
				cost_table[i][j] = cost_table[i-1][j-1];
				parent[i][j] = MATCH;
			}	
			else
			{
				opt[SUBS]   = 1 + cost_table[i-1][j-1];
				opt[DELETE] = 1 + cost_table[i-1][j];
				opt[INSERT] = 1 + cost_table[i][j-1];
				cost_table[i][j] = opt[SUBS];
				parent[i][j] = SUBS;

				for(int k=1; k <= 2; k++)
				{
					if (opt[k] < cost_table[i][j])
					{
						cost_table[i][j] = opt[k];
						parent[i][j] = k;
					}	
				}
			}
		}	
	}      	

	goal_cell(text, pattern, x, y); 	
}	


void reconstruct_path(unsigned int i, unsigned int j)
{
	
}

void printTable(unsigned int num_row, unsigned int num_column)
{
	for(int i=0; i <= num_row; i++)
	{
		for(int j=0; j <= num_column; j++)
		{
			cout << cost_table[i][j] << "\t";	
		}	
		cout << endl;
	}	
}	


int main()
{
	string text, pattern;
	cout << "enter text: ";
	getline(cin, text);
	cout << "enter pattern: ";
	getline(cin, pattern);

	unsigned int i, j;
	edit_distance(text, pattern, &i, &j);
	cout << "cost table: " << endl;
	printTable(text.length(), pattern.length());
	
	cout << "edit distance: " << cost_table[i][j] << endl;
	//reconstruct_path(i,j);
	return 0;
}	
