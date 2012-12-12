#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int n,l,h;
int t;
int arr[1001];

int main(){
        scanf("%d",&t);
        while(t--){
                scanf("%d %d %d",&n,&l,&h);
                for(int i=0;i<n;i++){
                        scanf("%d",&arr[i]);
                }
                sort(arr,arr+n);
                int count = 0;
                for(int a=0;a<n;a++){

                        int lower = n-1;
                        int higher = n-1;
                        int b = a+1;
                        bool flag = false;
                        while(b<n && !flag){
//                              cout<<lower<<" "<<higher<<endl;

                                while(lower>b && arr[b]+arr[lower]>=l-arr[a]){
                                        lower --;
                                }
                                if(lower!=n-1)lower++;

                                while(higher>b && arr[b]+arr[higher]>h-arr[a]){
                                        higher--;
                                }
                                if(lower>b && higher >b){
                                        count+= higher - lower +1;
                                }else{
                                        flag = true;
                                }
                                b++;
                        }
//                      cout<<count<<endl;
                }
                printf("%d\n",count);

        }
        return 0;
}
