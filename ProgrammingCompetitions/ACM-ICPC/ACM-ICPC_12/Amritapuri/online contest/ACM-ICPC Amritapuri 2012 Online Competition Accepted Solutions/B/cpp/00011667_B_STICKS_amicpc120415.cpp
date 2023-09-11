#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
              long long int m,n;
               scanf("%lld%lld",&m,&n);
               long long int a[n][3];
               long long int l[m];
               long long int max1 = -1;
               for(int i = 0;i < m;i++) scanf("%lld",&l[i]);
               for(int i = 0;i < n;i++ ) {
                       for (int j = 0;j < 3;j++) {
                           scanf("%lld",&a[i][j]);
                           if(max1 < a[i][j])max1=a[i][j];
                       }
               //        sort(a[i],a[i]+3);
               }
               //int d[n];
               long long int max3 = -1;
               for(int i = 0;i < n;i++){
                       int l = (int)sqrt(a[i][0]*a[i][0]+a[i][1]*a[i][1]+a[i][2]*a[i][2]);
                       if(max3 < l)max3=l;
    
               }
             //  sort(d,d+n);
               long long int d1[n][6];
               long long int max2 = -1;
               for(int i = 0;i < n;i++){
                       d1[i][0] = (int)sqrt(a[i][0]*a[i][0]+a[i][1]*a[i][1]);
                       if(d1[i][0] > max2)max2=d1[i][0];
                       d1[i][1] = (int)sqrt(a[i][1]*a[i][1]+a[i][2]*a[i][2]);
                       if(d1[i][1] > max2)max2=d1[i][1];
                       d1[i][2] = (int)sqrt(a[i][0]*a[i][0]+a[i][2]*a[i][2]);
                       if(d1[i][2] > max2)max2=d1[i][2];
                      // d1[i][3] = d1[i][0];
                       //d1[i][4] = d1[i][1];
                       //d1[i][5] = d1[i][2];
                     //  sort(d1[i],d1[i]+6);
               }
               
               long long int count=0;
               long long int count1=0;
               long long int count2 = 0;
               for(int i = 0;i < m;i++) {
                       if(max1 >= l[i]){count++;goto p;}
                       if(max2 > l[i]){count++;goto p;}
                       else if(max2 == l[i]&&count2==0){count2=0;count++;goto p;}
                       
                       if(max3 > l[i]){count++;goto p;}
                       else if(max3 == l[i]&&count1==0){count++;goto p;}
                       
                       p:{}
               }
               printf("%lld\n", count);
}
    return 0;
}
    
