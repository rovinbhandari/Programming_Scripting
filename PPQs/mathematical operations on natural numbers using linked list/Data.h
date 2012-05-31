#ifndef DATA_H
#define DATA_H

typedef unsigned short int Digit;

typedef struct data
	{
		// struct members
		Digit digit;
	}
	Data;

// function declarations for converting to and from Data.
struct data* inttodata(int);
Digit datatoint(struct data*);

#endif

