#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
void sort(int arr[],int p,int q,int r)
{
 int i,j,k,l,b[p+r+1];
 l=p;
 i=p;
 j=q+1;
 
  while((l<=q)&&(j<=r))
   {
    if(arr[l]<=arr[j])
      {
       b[i]=arr[l];
       l++;
      }
    else
      {
       b[i]=arr[j];
       j++;
       }
    i++;
   }
   

 if(l>q)
   {
    for(k=j;k<=r;k++)
       {

        b[i]=arr[k];
        i++;
       }

   }
 else
   {
    for(k=l;k<=q;k++)
       {

        b[i]=arr[k];
        i++;
       }

   }
 for(k=p;k<=r;k++)
    {

     arr[k]=b[k];
    }

}

void mergesort(int arr[],int p,int r)
{
 int q;
 if(p<r)
   {
    q=(p+r)/2;
    mergesort(arr,p,q);
    mergesort(arr,q+1,r);
    sort(arr,p,q,r);
   }
}

int main()
{
int h,t;
scanf("%d",&t);
for(h=0;h<t;h++)
{
int n,m,i;
scanf("%d%d",&n,&m);
int arr[n];
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
mergesort(arr,0,n-1);

long int x,y,z,w=0,v;

for(i=0;i<m;i++)
{
scanf("%ld%ld%ld",&x,&y,&z);
v=x*x+y*y+z*z;
w=max(v,w);
}
w=sqrt(w);i=0;
while(arr[i]<=w && i<n)i++;
printf("%d\n",i);
}
return 0;
}
