/*
The first line contains the number of test cases T. T test cases follow.
For each test case, the first line contains integers N and M on the first line. The next N lines contain the lengths of each stick, and the M lines after that contain the dimensions of each box denoted by 3 space-separated integers.
There is a blank line after each test case.
*/

#include<iostream>
#include "math.h"
using namespace std;
#define TOLERANCE 0.0001

double myabs(const double x){
  if (x > 0.0)
    return x;
  return -x;
}

double mysqrt(const double x){
  double assumption = 1.0;
  if (x < 0.0)
    return 0.0;  
  while (myabs(assumption * assumption - x) > TOLERANCE){
    assumption = 0.5 * (assumption + x / assumption);
  }
  return assumption;
}

int main(){
	int T,n,m,i,count;
	double max,x;
	cin>>T;
	while(T>0){
		max=0,count=0;
		cin>>n>>m;
		long long int L[n], a,b,c;
		for(i=0;i<n;i++){
			cin>>L[i];
		}
		for(i=0;i<m;i++){
			cin>>a>>b>>c;
			//cout<<(double)(a*a + b*b + c*c)<<endl;
			x = sqrt((double)(a*a + b*b + c*c));
			//cout<<x<<endl;
			if(x>max){max=x;}
		}
		//cout<<max<<endl;
		for(i=0;i<n;i++){
			if(L[i]<=max){count++;}
		}
		cout<<count<<endl;
		T--;
	}
	return 0;
}

		
