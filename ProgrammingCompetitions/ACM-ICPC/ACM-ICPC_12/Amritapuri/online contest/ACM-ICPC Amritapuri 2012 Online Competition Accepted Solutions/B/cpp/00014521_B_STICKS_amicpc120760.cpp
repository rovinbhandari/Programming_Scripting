#include <iostream>
#include<cmath>

using namespace std;

int main()
{
	int T,N,M;
	cin >> T;
	for(int t=0;t<T;t++)
	{
		cin >> N >> M;
		unsigned long L[N];
		unsigned long A[M], B[M], C[M];
		double D[M];
		unsigned long count=0;
		for(int n=0;n<N;n++)
			cin >> L[n];
		
		unsigned long max=0;
		for(int m=0;m<M;m++)
		{
			cin >> A[m] >> B[m] >> C[m];

			D[m] = (A[m]*A[m]) + (B[m]*B[m]) + (C[m]*C[m]);

			D[m] = sqrt(D[m]);

			if(D[m] > max) max=D[m];
		}

		for(int i=0;i<N;i++)
		{
			if(L[i]<= max) count++;
		}

		cout << count << endl;


	}
	return 0;
}
