#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define lli long long int
#define uli unsigned long int
#define ulli unsigned long long int
#define PI 3.14159265358979
#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define printl printf("\n");
#define coutl cout<<"\n";

#define mod 3

ulli i,j,k,dif;
#define foi(k,n)   for(i=k; i<n; i=i++)
#define rfoi(n,k)   for( i=n; i>=k; i=i--)
#define foj(k,n)   for( j=k; j<n; j++)
#define rfoj(n,k)   for( j=n; j>=k; j--)

#define foid(k,n,diff)   for( i=k; i<n; i=i+diff)
#define rfoid(n,k,diff)   for( i=n; i>=k; i=i-diff)

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int main(){
    lli arr[1001], T,n,l,h, count, index , power,base,  curr,prev,  temp,temp1,temp2,  sum,ans, p,q;
    //freopen("input.txt","r",stdin);
    scanf("%lld",&T);
    while(T--){
        count=0;
        vector<int> num;
        scanf("%lld %lld %lld",&n,&l,&h);
       // printf("nlh = %lld %lld %lld\n",n,l,h);

        for(int i = 0; i < n; ++i)
        {
            cin>>temp;
            num.push_back(temp);
        }

        sort(num.begin(), num.end(), myobject);

        for(int i = 0; i < n; ++i) {
            int j = i + 1;
            int k = n-1 ;
            while (j < k) {
                int sum = num[i] + num[j] + num[k];
                if(sum>=l && sum<=h) {
                    //printf("%lld\n",sum);

                    count++;
                    index = j;
                    j++;
                    sum = num[i] + num[j] + num[k];
                    while (  sum>=l  && sum<=h  && j<k){
                        //printf("%lld\n",sum);
                        count++;
                        j++;
                        sum = num[i] + num[j] + num[k];
                    }

                    j=index;
                    index=k;
                    k--;
                    sum = num[i] + num[j] + num[k];
                    while (  sum>=l  && sum<=h  && j<k){
                        //printf("%lld\n",sum);
                        count++;
                        k--;
                        sum = num[i] + num[j] + num[k];
                    }
                    k=index;

                    j++;
                    k--;
                }
                else if(sum > h) {
                    k--;
                }
                else { // sum < l
                    j++;
                }
            }
        }
        printf("%lld\n",count);
    }



return 0;
}
