#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
//int b[53002];
int a[52000];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        int n,m,i,j,k;
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%d ",&a[i]);
        int count=0;
        int x,y,z;
        //memset(b,0,sizeof(b));
        int mx=-1;
        for(i=0;i<m;i++) {
            scanf("%d %d %d",&x,&y,&z);
/*            if(!b[x])b[x]=1;
            if(!b[y])b[y]=1;
            if(!b[z])b[z]=1;*/
            mx=max(mx,x);
            mx=max(mx,y);
            mx=max(mx,z);
            int p,q,r,s;
            double dig;
            p=(int)sqrt((double)y*y+(double)z*z);
            q=(int)sqrt((double)x*x+(double)z*z);
            dig=(double)sqrt((double)y*y+(double)x*x);
            r=(int)dig;
        /*if(!b[p])b[p]=1;
            if(!b[q])b[q]=1;
            if(!b[r])b[r]=1;*/
            mx=max(mx,p);
            mx=max(mx,q);
            mx=max(mx,r);
            s=(int)sqrt((double)dig*dig+(double)z*z);
            mx=max(mx,s);
            //if(!b[s])b[s]=1;
        }
        for(i=0;i<n;i++)
            if(a[i]<=mx)count++;
        printf("%d\n",count);
    }
    return 0;
}
