#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
        long double sinx, x, term;
        unsigned long fac, i, n;
        term = 0.0;
        sinx = 0.0;
        n = 1;
        printf("\n\n\tEnter the value of x in radians to calculate its sine : ");
        scanf("%LG", &x);
        if(x == 0.0)
        {
                printf("\n\n\tThe value of sin(0.0) is : 0.0");
                exit(1);
        }
        do
        {
                sinx += term;
                i = 2;
                fac = 1;
                while(i <= (2 * n - 1))
                {
                        fac *= i;
                        i++;
                }
                printf("\n%lu.\t%LG * %LG / %LG", n, ((long double) pow(-1, (n + 1))), ((long double) pow(((double) x), (2 * n - 1))), ((long double) fac));
                term = ((long double) (pow(-1, (n + 1))) * ((long double) pow(((double) x), (2 * n - 1))) / ((long double) fac));
                n++;
        }
        while(fabs(term) >= 0.000001);
        if(((unsigned long) (sinx * 1000000.0) % 10) >= 5)
        {
                sinx = ((long double) ((unsigned long) (sinx * 100000.0)) + 1) / 100000.0;
        }
        else
        {
                sinx = ((long double) ((unsigned long) (sinx * 100000.0))) / 100000.0;
        }
        printf("\n\n\tsin(%LG) (computed upto 10^-5) = %LG\n\n", x, sinx);
}
