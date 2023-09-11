#include<iostream>
#include<cstdio>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;

int find_three(int arr[], int c, int l,int h)
{
   int i, j, e, s, k;
   int count =0;
   //Sorting the input array
   sort(arr,arr+c);
   //for(int i=0;i<c;i++)
   //cout<<"  "<<arr[i];
   c--;
   while(arr[c]>h)
   c--;
   int sum=0;
   for (int i = 0; i<=c-2;i++)
   {   //s=h-arr[i]; // the sum of two elements should be this value
      sum=arr[i]+arr[i+1]+arr[i+2];
      if(sum>h)
      break;
      for(j=i+1;j<=c-1;j++)
       {  
          for(k=j+1;k<=c;k++)
          {   sum=arr[i]+arr[j]+arr[k];
              if(sum>=l &&sum<=h)
              {  //cout<<"\n"<<arr[i]<<"  "<<arr[j]<<"  "<<arr[k]<<"\n" ;//return true;
                 count++;
              }
              if(sum>h)
              break;
          }
       }
   }
   
      return  count;
}


int main()
{   int t;
    scanf("%d",&t);
    while(t--)
    {  
              int n,l,h;
              scanf("%d%d%d",&n,&l,&h);
              int arr[n];
              for(int i=0;i<n;i++)
              scanf("%d",&arr[i]);
              int ans=find_three(arr,n,l,h);
              cout<<ans<<"\n";
    }
}
