#include <stdio.h>
int main()
{
int p = 10;
int q = p++ + ++p;
printf("p= %d ,q= %d",p,q);
}
