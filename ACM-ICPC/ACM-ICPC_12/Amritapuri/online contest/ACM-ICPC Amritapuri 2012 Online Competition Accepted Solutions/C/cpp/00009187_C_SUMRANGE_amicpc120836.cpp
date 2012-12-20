#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int my_arr[1001];
int size;

int search_less(int pair,int L,int first,int last)
{
    if(first>last)
        return -1;
    else
    {
        int middle=(first+last)/2;

        if(my_arr[middle]>= L-pair && middle==0)
            return middle;
        else if(my_arr[middle]>= L-pair && my_arr[middle-1]< L-pair)
            return middle;
        else if(my_arr[middle]>= L-pair)
        {
            int res= search_less(pair,L,first,middle-1);
            if(res==-1)
                return middle;
            else
                return res;
        }
        else
            return search_less(pair,L,middle+1,last);
    }
}

int search_more(int pair,int H,int first,int last)
{
    if(first>last)
        return -1;
    else
    {
        int middle=(first+last)/2;

        if(my_arr[middle]<= H-pair && middle==size)
            return middle;
        else if(my_arr[middle]<= H-pair && my_arr[middle+1]> H-pair)
            return middle;
        else if(my_arr[middle]<= H-pair)
        {
            int res= search_more(pair,H,middle+1,last);
            if(res==-1)
                return middle;
            else
                return res;
        }
        else
            return search_more(pair,H,first,middle-1);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    int N,L,H;
    int ptr;
    int i,j,k;
    int pair;
    int start,end;
    long long int ans;

    while(T-->0)
    {
        scanf("%d %d %d",&N,&L,&H);
        ptr=0;
        size=N-1;

        while(N-->0)
        {
            scanf("%d",&j);
            my_arr[ptr++]=j;
        }
        ans=0;
        //printf("here2");

        sort(my_arr,my_arr+ptr);
        //printf("here3");

        for(i=0;i<ptr-1;i++)
        {
            for(j=i+1;j<ptr;j++)
            {
                pair=my_arr[i]+my_arr[j];
                start=search_less(pair,L,0,ptr-1);
                end=search_more(pair,H,0,ptr-1);
                if(start==-1 || end==-1);
                else
                {
                    ans+=end-start+1;
                    if(i<=end && i>=start)
                        ans--;
                    if(j<=end && j>=start)
                        ans--;
                }
            }
        }
        ans=ans/3;
        printf("%d\n",ans);

        //printf("here1");
    }

    return 0;
}
