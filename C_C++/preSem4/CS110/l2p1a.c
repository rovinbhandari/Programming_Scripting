#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
        long double sinx, x;
        unsigned long fac, i, n, N;
        n = 1;
        sinx = 0.0;
        printf("\n\n\tEnter the value of x in radians to calculate its sine : ");
        scanf("%LG", &x);
        if(x == 0.0)
        {
                printf("\n\n\tThe value of sin(0.0) is : 0.0");
                exit(1);
        }
        printf("\n\n\tEnter the value of the number of terms to compute\n\tin the expansinon of sin(x) : ");
        scanf("%lu", &N);
        if(N <= 0)
        {
                printf("\n\n\tPlease enter a natural number");
                exit(1);
        }
        while(n <= N)
        {
                i = 2;
                fac = 1;
                while(i <= (2 * n - 1))
                {
                        fac *= i;
                        i++;
                }
                printf("\n%lu.\t%LG * %LG / %LG", n, ((long double) pow(-1, (n + 1))), ((long double) pow(((double) x), (2 * n - 1))), ((long double) fac));
                sinx += ((long double) (pow(-1, (n + 1))) * ((long double) pow(((double) x), (2 * n - 1))) / ((long double) fac));
                n++;
        }
        printf("\n\n\tsin(%LG) (computed till %lu terms) = %LG\n\n", x, N, sinx);
}
