#include<cstdio>
#include<cmath>
int main(){

    int t,n,m;
    long long int sticks[60000];
    long long int sum = 0 ; 
    char dummy;
    long long int a,b,c;
    int count = 0 ;
    long long int current_max;
    scanf("%d",&t);
    for(int i = 0 ; i < t ; i++){
	scanf("%d%d",&n,&m);
	for(int j = 0 ; j < n; j++)
	    scanf("%lld",&sticks[j]);
	count = 0 ; 
	current_max = 0 ; 
	for(int j =0; j< m; j++){
		scanf("%lld%lld%lld",&a,&b,&c);
		sum = a*a+ b*b + c*c;
		if(sum>current_max)
		    current_max = sum;
		}		
		for(int k = 0 ; k < n; k++){
		    if(sticks[k]*sticks[k] <=current_max && sticks[k] >= 0){
			count++;
			sticks[k] = -1;
		    }
		}
	scanf("%c",&dummy);
	printf("%d\n",count);

    }


    return 0;
}
