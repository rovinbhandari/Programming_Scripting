#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;



int main()
{ int t;
 int maxl; // to save maximum length
int m,n,i,j,k,count,h=0;
float dd,df,max,d;
int l[50000];
int a[50000],b[50000],c[50000];

scanf("%d",&t);
int p[t];
while(h<t)
{ count=0;
  maxl=0;
  max=0.0;
scanf("%d %d",&n,&m);
for(i=0;i<n;i++)
{scanf("%d",&l[i]);
} 
for(i=0;i<m;i++)
{ scanf("%d %d %d",&a[i],&b[i],&c[i]);

    if(a[i]>maxl)
    maxl=a[i];
    if(b[i]>maxl)
    maxl=b[i];
    if(c[i]>maxl)
    maxl=c[i];
    


d=pow(a[i],2)+ pow(b[i],2);

dd=d + pow(c[i],2); 
df=sqrt(dd); 
if(df > max)
max=df; } 


if(maxl>max)
{ max=maxl;
            }


for(i=0;i<n;i++)
{ if(l[i]<=max)
count++;
}
p[h]=count; 

h++;
cin.ignore(256, '\n');
}

h=0;
while(h<t)
{ 
printf("%d",p[h]);
printf("\n");

h++;
}




return 0;}
