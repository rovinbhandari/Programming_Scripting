#include<stdio.h> 
#include "add.h"
main()
{
     int a,b,c;
     a=10;
     b=23;
     c=add(a,b);
     printf("%d",c);
     c=substract(a,b);
     printf("%d",c);
}

