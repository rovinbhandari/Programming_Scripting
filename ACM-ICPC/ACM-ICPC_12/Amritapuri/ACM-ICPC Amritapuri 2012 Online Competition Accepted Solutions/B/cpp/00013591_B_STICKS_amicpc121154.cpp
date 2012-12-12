#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
/*
void swap_num(int &a,int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void sort_array(int a[],int length){
	int j;
	for(int i=length-2;i>=0;i--){
		j=i;
		while(j < (length-1) && a[j] > a[j+1]){
			swap_num(a[j],a[j+1]);
			j++;
		}
	}
}
*/
int max_length(int a[],int length){
	int max_length=0;
	for(int i=0;i<length;i++){
		if(a[i] > max_length)
			max_length=a[i];
	}
	return max_length;
}
int main(){
	int i,t,length,max_len;
	int n,m,counter;
	int *max_fit,*l;
	int a,b,c;
	cin>>t;
	while(t--){
		counter=0;
		scanf("\n%d %d\n",&n,&m);
		l=new int[n];
		max_fit=new int[m];		
		for(i=0;i<n;i++){
			scanf("%d\n",&l[i]);
		}		
		for(i=0;i<m;i++){
			scanf("%d %d %d\n",&a,&b,&c);
			max_fit[i]=sqrt(pow(a,2)+pow(b,2)+pow(c,2));
		}
		scanf("\n");
		max_len=max_length(max_fit,m);
		for(i=0;i<n;i++){
			if( max_len >= l[i] ){
				counter++;
			}
		}
		cout<<counter<<"\n";
		delete[] l;
		delete[] max_fit;
	}
}
