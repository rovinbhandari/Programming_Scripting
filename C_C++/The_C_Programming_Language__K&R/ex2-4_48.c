#include <stdio.h>
#include <string.h>

#define	NOOFCHARS	256
#define	TRUE	1
#define	LENMAX	1000

typedef	unsigned short int Bool;

// below is the version from the book
void squeeze1(char s[] /* this syntax explicitly informs that a mutable string is required */, char c)
{
	int i, j;
	char x;

	for(i = j = 0; x = *(s + i); i++)
		if(x != c)
			*(s + j++) = x;
	
	*(s + j) = '\0';
}

// the actual answer to the exercise starts from here
void createhash(Bool h[] /* this syntax explicitly informs that a Bool array is required */, char* s)
{
	int i, j;
	char c;

	for(i = j = 0; c = *(s + i); i++)
		if(!*(h + c))
			*(h + c) = TRUE;
}	

void squeeze2(char s1[] /* mutable string only */, char* s2 /* mutable or immutable string would do */)
{
	// create a binary hash out of (unique) characters from s2
	Bool binaryhash[NOOFCHARS] = {0};
	createhash(binaryhash, s2);

	// in a single iteration on the length of the source string, copy all the characters which are not present in the binary hash back into the source string.
	int i, j;
	char x;
	for(i = j = 0; x = *(s1 + i); i++)
		if(!*(binaryhash + x))
			*(s1 + j++) = x;
	*(s1 + j) = '\0';
}

int main(void)
{
	char s1[LENMAX];
	char s2[LENMAX];

	printf("Enter the source string (the string from which characters are to be deleted)\n");
	fgets(s1, LENMAX, stdin);

	printf("Enter the string of characters that are to be deleted from the source string\n");
	fgets(s2, LENMAX, stdin);

	squeeze2(s1, s2);
	printf("After deletion, the source string becomes whatever is in the double quotes:\n\"%s\"\n", s1);
	
	return 0;
}

