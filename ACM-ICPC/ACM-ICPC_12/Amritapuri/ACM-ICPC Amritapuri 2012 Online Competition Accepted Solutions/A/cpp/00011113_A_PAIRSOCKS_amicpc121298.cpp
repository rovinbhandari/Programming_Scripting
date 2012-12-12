#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>

using namespace std;

// important macros
#define incfor(i,a,b) for(i=(int)a;i<b;i++)
#define decfor(i,a,b) for(i=(int)a;i>=(int)b;i--)
#define SCAN(x) scanf("%d",&x)
#define SCANS(x) scanf("%s",x)
int main()
{
    int t;
    SCAN(t);
    while(t--)
    {


    char str1[50];
    int i,j;


    //for(int i=0;i<len;i++)
    vector<char>str;
    SCANS(str1);
     int len=strlen(str1);
     //sort(str1,str1+len);
     incfor(i,0,len)
     {
         str.push_back(str1[i]);

     }
     int flag=0;

    for(i=0;i<len;i++)
     {

     j=count(str.begin(),str.end(),str1[i]);
     if(j%2!=0)
     {
         //if(t!=0)
         printf("NO\n");
         //else
         //printf("NO");

     break;
     }
     else
     {

     flag++;
     }
    // cout<<str1[i]<<" "<<j<<endl;
     //i=i+j;
     /*else
     continue
     if(j%2==0)
     printf("YES");
     }*/
    }
    if(flag==len )
    printf("YES\n");
  //  if(flag==len && t==0)
    //printf("YES");



}
return 0;
}
