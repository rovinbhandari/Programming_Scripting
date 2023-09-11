#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define LL  long long
#define MOD 1000000007
bool ans=0;
bool arr[20000][20000];
int arr1[20000],bugs;
long long int cnt=0;
int mult( LL a, LL b){
    LL temp = 1,ans = 1;
    while(b>0){
               //cout<<(b&temp)<<endl;
        if(b & temp){
            ans = (ans * a) % MOD;
            b = b - temp;
        }
        temp = temp << 1;
        a = (a * a) % MOD;
    }
    return ans % MOD;
}
void traverse(int i){
	if(arr1[i]==0){
		arr1[i]=1;
		cnt++;
    }
	int j;
	for(j=0;j<bugs;j++){
		if(arr[i][j]==1){
			if(arr1[i]==arr1[j])
				ans=1;
			else if(arr1[j]!=0){
			}
			else{
				arr1[j]=-arr1[i];
				traverse(j);
			}
		}
	}
}
int main()
{
	int test,sce,inte,i,j,m,k;
	scanf("%d",&test);
	for(sce=1;sce<=test;sce++){
                               cnt=0;
		ans=0;
		scanf("%d",&bugs);
		for(i=0;i<bugs;i++){
			arr1[i]=0;
			for(j=0;j<bugs;j++){
			arr[i][j]=0;
			}
		}
		for(i=0;i<bugs;i++){
			scanf("%d",&m);
			for(j=0;j<m;j++){
                             scanf("%d",&k);
			                 arr[i][k]=1;
			                 arr[k][i]=1;
         }
		}
		for(i=0;i<bugs;i++){
			traverse(i);
		}
		if(ans==1){
			printf("0\n");
        }
		else
			printf("%d\n",mult(2,cnt));
	}
	return 0;
}
