#include<iostream>
using namespace std;

int main()
{
	/* code */
	int NUM=50001;
	int T;
	long long int N, M;
	long long int L[NUM], A[NUM], B[NUM], C[NUM];
	cin>>T;
	while(T!=0) {
		cin>>N>>M;
		long long int n=N, m=M;
		long long int i=0;
		long long int count=0;
		long long int max=0, temp=0;
		while(n!=0) {
			cin>>L[i];
			//cout<<"n: "<<n<<endl;
			i++;
			n--;
		}
		i=0;
		while(m!=0) {
			cin>>A[i]>>B[i]>>C[i];
			temp = A[i]*A[i] + B[i]*B[i] + C[i]*C[i];
			//cout<<"m: "<<m<<endl;
			if(max<temp) {max = temp;}
			i++;
			m--;
		}
		for(i=0; i<N; i++) {
			if((L[i]*L[i])<=max) {count++;}
		}
		cout<<count<<endl;
		T--;
	}
	return 0;
}