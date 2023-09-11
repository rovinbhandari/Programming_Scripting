using namespace std;

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define INF 1<<30
#define LL long long
#define pb push_back

int main()
{
    int t=0;
    
    int l,val;
    string s;
    scanf("%d",&t);
    while(t--)
    {
             cin>>s;
             int arr[4]={0};
             l=s.length();
             val=0;
             for(int i=0;i<l;i++) 
             {
                  switch(s[i])
                  {
                              case 'R' : arr[0]++;break;
                              case 'B' : arr[1]++;break;
                              case 'W': arr[2]++;break;
                              case 'G': arr[3]++;break;
                  } 
             }
             
             for(int i=0;i<4;i++)
             {
                     if(arr[i]%2!=0)
                     {
                       val=1;break;
                     }
             }
             if(val==0)
                  printf("YES\n");
             else
                  printf("NO\n");
    }
return 0;
}
