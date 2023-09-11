#include<stdio.h>
#include<cmath>
int main()
{
long long int cases,i,j,k,a,b,c,m,n,temp,max,count;
scanf("%lld",&cases);

for(i=0;i<cases;i++)
{
 scanf("%lld %lld",&m,&n);

 long long int arlen[m];
 //long long int arbox[n];

for(j=0;j<m;j++)
 {scanf("%lld",&temp);
  arlen[j]=temp;
 }

   max=0;
 for(j=0;j<n;j++)
 {
   scanf("%lld %lld %lld",&a,&b,&c);

    if(max<(a*a+b*b+c*c))
     max=a*a+b*b+c*c;
}
  count=0;
//   printf("&&&&%lld",max);
  max=(int)sqrt(max);
 // printf("******%lld",max);


  for(j=0;j<m;j++)
  {
    if(max>=arlen[j])
       count++;

  }

 printf("%lld\n",count);

}

return 0;
}

