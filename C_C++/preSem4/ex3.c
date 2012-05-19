#include<stdio.h>
struct poly
{
        int exp,coeff;
}temp[10],t[10],final[10];

int main()
{
        int i, k, d1, d2, z, x, y, a[10];
        printf("\n\t\t\tPROGRAM TO ADD POLYNOMIALS USING LINKED LIST \n");
	printf("\n\nPOLYNOMIAL-1\n\tEnter the degree : ");
	scanf("%d", &d1);
	printf("\n\tnow enter the coefficients : \n");
        for(i = d1, k = 0; i >= 0; i--, k++)
        {
                temp[k].exp = i;
                scanf("%d", &temp[k].coeff);
        }
        printf("\n\nPOLYNOMIAL-2\n\tEnter the degree : \n");
        scanf("%d", &d2);
	printf("\n\tnow enter the coefficients : \n");
        for(i = d2, k = 0; i >= 0; i--, k++)
        {
                t[k].exp = i;
                scanf("%d", &t[k].coeff);
        }
	z = 0;
	x = 0, y=0;
        while(d2 >= 0 || d1 >= 0)
        {
                if(temp[z].exp > t[x].exp)
                {
                        final[y].exp = temp[z].exp;
                        a[y] = temp[z].coeff;
                        final[y].coeff = temp[z].coeff;
                        d1--;
                        z++;
			y++;
                }
                else if(temp[z].exp < t[x].exp)
                {
                        a[y]=t[x].coeff;
                        final[y].exp = t[x].exp;
 			final[y].coeff = t[x].coeff;
                        d2--;
                        x++;
			y++;
                }

                if(temp[z].exp == t[x].exp)
                {
                        a[y] = temp[z].coeff+t[x].coeff;
                        final[y].exp=temp[z].exp;
                        final[y].coeff=temp[z].coeff+t[x].coeff;
                        d1--;
			d2--;
                        z++;
			y++;
			x++;
		 }
        }
        printf("\nThe Resultant polynomial has Degree : %d\n",y);
        y--;
	printf("%d", y);
	printf("\n\n\tThe coefficients of the Result polynomial in increasing power of x are :\n");
	for( ; y >= 0; y--)
        {
                printf("\t%d \n",a[y]);
                //printf("%d ",final[y].coeff);
        }
}

