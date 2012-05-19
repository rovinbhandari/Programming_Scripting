#include<stdio.h>
#include<string.h>
void main()

            {

                            typedef union

                            {

                                    int i;

                                    char str[10];

                             }un;

                             un x,y = {100};

                 x.i =50;

                 strcpy(x.str,"union");

                 printf("%d,%s,",x.i,x.str);

                             printf("%d,%s\n",y.i,y.str);

            }
