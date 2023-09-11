#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

int main()
{
    int t,k;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
        long int n,m,i,j,new_count;
        scanf("%ld %ld",&n,&m);
        long int l[n];
        long int dim[m];
        long int a,b,c;
        for(i=0;i<n;i++)
        {
            scanf("%ld",&l[i]);
        }
       // printf("c");
        for(i=0;i<m;i++)
        {
            scanf("%ld %ld %ld",&a,&b,&c);
            dim[i]=(long int)sqrt( (a*a) + (b*b) + (c*c));
        }
        sort(l,l+n);
        sort(dim,dim+m);
       new_count=0;




        for(i=n-1;i>=0;i--)
        {
            if(l[i]<=dim[m-1])
            {
                new_count+=i+1;
                break;
            }



        }

        printf("%ld\n",new_count);
    }


return 0;
}
