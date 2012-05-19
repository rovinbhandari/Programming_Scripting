#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void newfile()
{
	FILE *fp;
	char name[50], a[100];
	int k;
	printf("\nEnter the filename :\t");
	scanf("%s", name);
	fp = fopen(name, "w");
	printf("\nEnter the number of lines to be entered :\t");
	scanf("%d", &k);
	printf("\nEnter lines :\n");
	//fpurge(stdin);
	//fpurge(stdout);
	while(k >= 0)
	{
		fgets(a, 100, stdin);
		fprintf(fp, "%s", a);
		k--;
	}
	fclose(fp);
}
void displayfile()
{
	FILE *fp;
	char name[50], a;
	printf("\nEnter the filename :\t");
	scanf("%s", name);
	fp = fopen(name, "r");
	if(fp == NULL)
		printf("\nError retrieving file\n");
	else
	{
		while(!feof(fp))
		{
			fscanf(fp, "%c", &a);
			printf("%c", a);
		}
	}
	fclose(fp);
}
void findline()
{
	FILE *fp;
	char name[50], a[100];
	int k, line = 1 - 1;
	printf("Enter the filename :\t");
	scanf("%s", name);
	fp = fopen(name, "r");
	if(fp == NULL)
		printf("\nError retrieving file\n");
	else
	{
		printf("\nEnter the line number to display (first line entered = line no. 1) :\t");
		scanf("%d", &k);
		while(fgets(a, sizeof(a), fp) != NULL)
		{
			if(a[strlen(a) - 1] == '\n')
				a[strlen(a) - 1] = '\0';
			if(line == k)
				printf("\n%s", a);
			line++;
		}
	}
	fclose(fp);
}
void insertlines()
{
	FILE *fp1, *fp2;
	char name[50], a[100], text[100];
	int k, line, n;
	printf("\nEnter the filename :\t");
	scanf("%s", name);
	printf("\nEnter the number of lines to be inserted :\t");
	scanf("%d", &n);
	while(n > 0)
	{
		fp1 = fopen(name, "r");
		if(fp1 == NULL)
			printf("\nError retrieving file\n");
		else
		{
			fp2 = fopen("abc.txt", "w");
			line = 1;
			printf("\nEnter the position at which line is to be inserted (first line entered = line no. 1) :\t");
			scanf("%d", &k);
			printf("\nEnter the line :\n");
			scanf("%s", text);
			while(fgets(a, sizeof(a), fp1) != NULL )
			{
				if(a[strlen(a) - 1] == '\n')
					a[strlen(a) - 1] = '\0';
				fprintf(fp2, "%s\n", a);
				if(line == k)
					fprintf(fp2, "%s\n", text);
				line++;
			}
		}
		fclose(fp1);
		fclose(fp2);
		remove(name);
		rename("abc.txt", name);
		n--;
	}
}
void deletelines()
{
	FILE *fp1, *fp2;
	char name[50], a[100];
	int k, line, n;
	printf("\nEnter the filename :\t");
	scanf("%s", name);
	printf("\nEnter the number of lines to be deleted :\t");
	scanf("%d", &n);
	while(n > 0)
	{
		fp1 = fopen(name, "r");
		if(fp1 == NULL)
			printf("\nError retrieving file\n");
		else
		{
			fp2 = fopen("abc.txt", "w");
			line = 1;
			printf("\nEnter the position of line which is to be deleted (first line entered = line no. 1) :\t");
			scanf("%d", &k);
			while(fgets(a, sizeof(a), fp1) != NULL )
			{
				//printf("\n\t\t\t\tY\n");
				if(a[strlen(a) - 1] == '\n')
					a[strlen(a) - 1] = '\0';
				fprintf(fp2, "%s\n", a);
				if(line == k)
				{
					fgets(a, sizeof(a), fp1);
					printf("\nLine deleted!\n");
				}
				line++;
			}
		}
		fclose(fp1);
		fclose(fp2);
		remove(name);
		rename("abc.txt", name);
		n--;
	}
}
int main()
{
	printf("\n\n\t\t\tFILE   OPERATIONS\n\n"); 
	int a, b;
	do
	{
		printf("\nEnter your choice :\n\n\t#1# Enter text to a new file\n\t#2# Display text of a file\n\t#3# Find and display a line of a file\n\t#4# Insert n lines to a file\n\t#5# Delete n lines from a file\n\t#6# Exit\n");
		scanf("%d", &a);
		if(a == 1)
			newfile();
		else if(a == 2)
			displayfile();
		else if(a == 3)
			findline();
		else if(a == 4)
			insertlines();
		else if(a == 5)
			deletelines();
		else if(a == 6)
			return(0);
		else
		{
			printf("\nIncorrect Choice. Exiting...\n\n");
			return(0);
		}
		printf("\nDo another operation?\n\t#1# Yes\n\t#2# No\n");
		scanf("%d", &b);
	} while(b == 1);
	return(0);
}
