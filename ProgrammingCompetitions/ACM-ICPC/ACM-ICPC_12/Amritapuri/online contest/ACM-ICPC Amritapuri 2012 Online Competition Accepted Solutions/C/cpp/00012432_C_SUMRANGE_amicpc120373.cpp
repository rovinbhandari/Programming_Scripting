#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int *arr;
// int unique(int *a, int n);
int main()
{ int cases,i,j,kk,n,l,h,count=0,k;
    cin>>cases;
  //scanf("%d",&cases);
    while(cases--)
    { count=0;
        cin>>n>>l>>h;
        //scanf("%d%d%d",&n,&l,&h);
        if(n<3)
        { cout<<"0\n";
       // printf("0\n");
        continue;}
        arr=new int[n];
        for(i=0;i<n;i++)
        {
          cin>>arr[i];
       //  scanf("%d",&arr[i]);
        }
        sort(arr+0,arr+n);
   //     kk=unique(arr,n);
   //     cout<<kk;
   if(n>=3)
     for(i=0;i<n-2;i++)
     {
       for(j=i+1;j<n-1;j++)
       {
         for(k=j+1;k<n;k++)
         {
           if((arr[i]+arr[j]+arr[k]<=h)&&(arr[i]+arr[j]+arr[k]>=l))
           count++;
           if(arr[i]+arr[j]+arr[k]>h) break;
         }
       }
     }
 //  printf("%d\n",count);
 cout<<count<<"\n";
     
        
    }
   // getch();
    return 0;
}
        
