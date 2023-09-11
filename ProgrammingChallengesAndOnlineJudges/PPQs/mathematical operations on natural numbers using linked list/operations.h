#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <LinkedList.h>

LinkedList* intnumbertolinkedlist(int);
int linkedlisttointnumber(LinkedList*);

LinkedList* stringnumbertolinkedlist(char*);
char* linkedlisttostringnumber(LinkedList*);

LinkedList* add(LinkedList*, LinkedList*);
LinkedList* subtract(LinkedList*, LinkedList*);
LinkedList* multiply(LinkedList*, LinkedList*);

#endif

