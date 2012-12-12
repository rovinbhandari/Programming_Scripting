#include<iostream>
using namespace std;
int main(){
	static int a[4],b[1001];
	int i=0;
	char str[51];
	int N;
	cin>>N;

	for(int w=0;w<N+1;w++){
		cin.getline(str,51);
			for(int k=0;str[k];k++){
				if(str[k]=='R')
					a[0]=!a[0];
				else if(str[k]=='G')
					a[1]=!a[1];
				else if(str[k]=='B')
					a[2]=!a[2];
				else 
					a[3]=!a[3];
			 }
				b[i++]=a[0]||a[1]||a[2]||a[3];
				a[0]=a[1]=a[2]=a[3]=0;
				
		}
	for(int q=1;q<i;q++)
		if(b[q])
			cout<<"NO"<<endl;
		else 
			cout<<"YES"<<endl;
			

	return 0;
}

