#include<iostream>
//#include<conio.h>
#include<stdio.h>
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
       //c[i]=brr[l];
       l++;
      }
    else
      {
       b[i]=arr[j];
      // c[i]=brr[j];
       j++;
       }
    i++;
   }
   

 if(l>q)
   {
    for(k=j;k<=r;k++)
       {

        b[i]=arr[k];
        //c[i]=brr[k];
        i++;
       }

   }
 else
   {
    for(k=l;k<=q;k++)
       {

        b[i]=arr[k];
       // c[i]=brr[k];
        i++;
       }

   }
 for(k=p;k<=r;k++)
    {

     arr[k]=b[k];
     //brr[k]=c[k];
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
int p,n,l,h,t,s,c,i,j,k;
scanf("%d",&t);
for(i=0;i<t;i++)
{
c=0;
scanf("%d%d%d",&n,&l,&h);
int arr[n];
for(j=0;j<n;j++){
scanf("%d",&arr[j]);
//brr[j]=j;
}
mergesort(arr,0,n-1);
for(j=0;j<n;j++)
{
for(k=j+1;k<n;k++)
{
for(p=k+1;p<n;p++)
{
//if(brr[j]<brr[k] && brr[k]<brr[p])
if(arr[j]+arr[k]+arr[p]<=h && arr[j]+arr[k]+arr[p]>=l)
{
  //                        if(brr[j]<brr[k] && brr[k]<brr[p])
                          c++;                                             
}
else if(arr[j]+arr[k]+arr[p]>h)
     break;                  
}     
}           
}
printf("%d\n",c);
}
//system("pause");
return 0;
}
