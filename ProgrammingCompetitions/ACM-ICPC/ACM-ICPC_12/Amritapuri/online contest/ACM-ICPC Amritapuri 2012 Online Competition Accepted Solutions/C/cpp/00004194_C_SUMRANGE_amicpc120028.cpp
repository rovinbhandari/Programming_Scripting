#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        int n,l,h,i,j,k;
        scanf("%d%d%d",&n,&l,&h);
        int a[n];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int count=0;
        for(i=0;i<n;i++) {
            for(j=i+1;j<n;j++) {
                k=j+1;
                while(k<n && a[i]+a[j]+a[k] <=h) {
                    int x=a[i]+a[j]+a[k];
                    if(x>=l && x<=h)
                        count++;
                    k++;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
