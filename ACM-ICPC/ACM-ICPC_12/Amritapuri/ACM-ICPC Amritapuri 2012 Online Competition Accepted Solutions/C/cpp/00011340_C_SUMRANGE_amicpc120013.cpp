
#include<iostream>
#include<algorithm>
using namespace std;
int a[1005];
int N;
int binSearch1(int val,int i,int j){
	 int pos;
		pos=(i+j)/2;
		if(a[pos]==val) {while(a[pos]==val && pos>=0){pos--;} return pos+1;}
		
		if(i==j)
			return i;
		else if(a[pos]>val)
			return binSearch1(val,i,pos);
		else
			return binSearch1(val,pos+1,j);
}
int binSearch2(int val,int i,int j){
	 int pos;
		pos=(i+j)/2;
		if(a[pos]==val) {while(a[pos]==val && pos<N){pos++;} return pos-1;}
		
		if(i==j)
			return i-1;
		else if(a[pos]>val)
			return binSearch2(val,i,pos);
		else
			return binSearch2(val,pos+1,j);
}
		
int main(){
	int T;
	int L,H;
	char s[100];
	cin>>T;
	int flag;
	while(T-->0){
		cin>>N>>L>>H;
		for(int i=0;i<N;i++){
			cin>>a[i];
		}
		int sum=0;
		sort(a,a+N);
		for(int i=0;i<N-2;i++){
			if(a[i]>H) break;
			for(int j=i+1;j<N-1;j++){
				if(a[i]+a[j]>H) break;
				int pass1=L-a[i]-a[j];
				int pass2=H-a[i]-a[j];
				int a=binSearch1(pass1,j+1,N);
				if(a==N) continue;
				int b=binSearch2(pass2,j+1,N);
				if(b==j) continue;
    sum+=(b-a+1);
			}
		}
		cout<<sum<<endl;
			
			
				
	}
}
