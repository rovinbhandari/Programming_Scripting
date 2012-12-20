#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//#include <math.h>
//#include <cmath>

int main(int argc, char *argv[])
{
  int t;
  long int n,m,a,b,c,*l,i,x,cnt,j,maxx;
  scanf("%d",&t);
  while(t--)
  {
            scanf("%ld %ld",&n,&m);
            l= (long int*) malloc(sizeof(long int)*n);
           // l[1]= (long long int*) malloc(sizeof(long long int)*n);
          /*  a= (long long int*) malloc(sizeof(long long int)*m);
            b= (long long int*) malloc(sizeof(long long int)*m);
            c= (long long int*) malloc(sizeof(long long int)*m);
            */
            for(i=0;i<n;i++)
            {
                            scanf("%ld",&l[i]);
                            //l[1][i]=0;
            }
            cnt=0;
            maxx=0;
            for(i=0;i<m;i++)
            {
            scanf("%ld %ld %ld",&a,&b,&c);
            x= a*a + b*b + c*c;
            if(x>maxx)
                      maxx=x;
            }
            for(j=0;j<n;j++)
            {
                            if(l[j]*l[j]<=maxx)
                            {
                                       cnt++;
                            }
            }
            printf("%ld\n",cnt);
  }
  //system("PAUSE");	
  return 0;
}
