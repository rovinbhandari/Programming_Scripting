//program B:Sticks
#include <iostream>
#include<math.h>
using namespace std;

int main()
{
	int T; 
	cin>>T;
	if(T<1 || T>10)
	 return 0;
	for(int kase = 1; kase <= T; kase++)
	{
		long N;
		cin>>N;
		if(N<1 || N>50000)
		 return 0;
                long M;
		cin>>M;
		if(M<1 || M>50000)
		 return 0;
                long L[N];
		long A[M],B[M],C[M];
                double chk[M],mchk;
		int cnt=0,i;
		for(i=0; i<N; i++){
		 cin>>L[i];
		 if(L[i]<1 || L[i]>100000)
		  return 0;
		}
		for(i=0;i<M; i++){
		 cin>>A[i]>>B[i]>>C[i];
		 if((A[i]<1 || A[i]>30000)&&(B[i]<1 || B[i]>30000)&&(C[i]<1 || C[i]>30000))
		  return 0;
		 chk[i]=sqrt((A[i]*A[i])+(B[i]*B[i])+(C[i]*C[i]));
		}
                mchk=chk[0];
		for(i=0;i<M;i++)
 		 if(chk[i]>mchk)
   		   mchk=chk[i];
		for(i=0; i<N; i++)
                {
		  if(L[i]<=mchk)
		    cnt++;
		 }
		cout<<cnt<<endl;
	}
	return 0;
}

