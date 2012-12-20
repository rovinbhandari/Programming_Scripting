using namespace std;

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#define INF 1<<30
#define LL long long
#define pb push_back


int main()
{
    int n,m,c,test=0;
    scanf("%d",&test);
    double len[100001],h,l,w,dia;  
    while(test--)
    {
                 
    scanf("%d%d",&n,&m);
    dia=0;
    
    for(int i=0;i<n;i++)
    scanf("%lf",&len[i]);
    
    for(int i=0;i<m;i++)
    {
            scanf("%lf%lf%lf",&h,&l,&w);
            dia=max(dia,sqrt(h*h+l*l+w*w));
    }
    
    c=0;
    
    for(int i=0;i<n;i++)
    if(len[i]<=dia)
    c++;
    printf("%d\n",c);
}
return 0;
}
    
