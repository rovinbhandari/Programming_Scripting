#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
     int t,N,M;
     vector<long long int> sticks;
     long long int l,b,h;
     long long int temp;
     int size;
     long long int largestBox;
     int res;
     scanf("%d",&t);
     sticks.reserve(50000);

     while(t--) {
	  sticks.clear();
	  largestBox = 0L;

	  scanf ("%d %d",&N,&M);
	  
	  for (int i=0;i<N;i++) {
	       scanf ("%lld",&temp);
	       sticks.push_back(temp);
	  }

	  for (int i=0;i<M;i++) {
	       scanf ("%lld %lld %lld",&l,&b,&h);
	       
	       if (((l*l)+(b*b)+(h*h)) > largestBox)
		    largestBox = (l*l)+(b*b)+(h*h);
	  }

	  size = sticks.size();
	  res = 0;
	  for (int i=0;i<size;i++) {
	       if ((sticks[i]*sticks[i]) <= largestBox)
		    res++;
	  }

	  printf ("%d\n",res);
     }
     
     return 0;
}
