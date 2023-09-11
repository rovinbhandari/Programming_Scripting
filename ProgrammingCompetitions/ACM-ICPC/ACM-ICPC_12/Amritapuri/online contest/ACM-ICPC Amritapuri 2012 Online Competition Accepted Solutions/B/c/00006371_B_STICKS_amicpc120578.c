#include<stdio.h>


int main()
{    float p;
    long int count[15]={0},x=0,max=0,t1=0,i,t,k,j;long int m,n,s[60000],l[60000],b[60000],r[60000];
    scanf("%ld",&t);k=0;t1=t;
    while(t--)
    {x=0;max=0;
    scanf("%ld%ld",&m,&n);
    for(i=0;i<m;i++)
      scanf("%ld",&s[i]);
    
    for(i=0;i<n;i++)
      {
       scanf("%ld%ld%ld",&l[i],&b[i],&r[i]);
       x=l[i]*l[i]+b[i]*b[i]+r[i]*r[i];
       if(x>max)
        max=x;
        }
        
    for(i=0;i<m;i++)
      {
      if(max>=(s[i]*s[i]))
         count[k]++;
         }
         k++;
printf("%ld",count[k-1]);
printf("\n");
}
//for(i=0;i<t1;i++)
//printf("%ld",count[i]);
return 0;
}          
        
    
          
       
