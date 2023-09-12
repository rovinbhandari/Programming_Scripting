#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int N;
	char a='0';
	int count_r,count_g,count_b,count_w;
	scanf("%d",&N);
	a=getchar();
	for (int i = 0; i < N; ++i)
	{
		count_r=count_g=count_b=count_w=0;
		do
	 	{	
	 		a=getchar();
	 		if(a=='R') count_r++;
	 		if(a=='G') count_g++;
	 		if(a=='B') count_b++;
	 		if(a=='W') count_w++;
	 	}while (a!='\n');
	 	
	 	if((count_r%2==0) && (count_g%2==0) && (count_b%2==0) && (count_w%2==0))cout<<"YES"<<endl;
	 	else cout<<"NO"<<endl;
	}
	return 0;
}