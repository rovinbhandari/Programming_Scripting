#include<cstdio>
#include<iostream>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>

#define MAX 100000

using namespace std;

long long int arr[MAX];


int main()
{

    int T;
    scanf("%d",&T);
    while(T--)
    {

        int N,L,H,lo,hi,mid,j,idx=0,idx1;
        long long int temp;
        long long int ans=0;
        scanf("%d %d %d",&N,&L,&H);
        for(int i=0;i<N;i++)scanf("%lld",&arr[i]);
        sort(arr,arr+N);
        long long int count=0;
        for(int i=0;i<N;i++)
        {
            for(j=i+1;j<N-1;j++)
            {
                temp=arr[i]+arr[j];

                lo=j+1;hi=N-1;
                idx=idx1=0;
                while(lo<=hi)
                {
                    mid=(hi+lo)/2;

                        if(   ((temp+arr[mid])<=H)  ){
                            if((temp+arr[mid])>=L)
                            idx=mid;lo=mid+1;}
                        //else if(temp+arr[mid]<L)lo=mid+1;
                        else if(temp+arr[mid]>H)hi=mid-1;
                }
                lo=j+1;hi=N-1;
                while(lo<=hi)
                {
                    mid=(hi+lo)/2;

                        if(  ((temp+arr[mid])>=L) ){
                            if(((temp+arr[mid])<=H))
                            idx1=mid;hi=mid-1;}
                        else if(temp+arr[mid]<L)lo=mid+1;
                }


                //printf("idx: %d %d %d\n",j,idx,idx1);
                if(idx && idx1)count+=((idx-idx1+1));


            }

        }
     printf("%lld\n",count);


    }
    return 0;
}
