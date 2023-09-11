#include<cstdlib>
#include<iostream>
#include<cmath>
#include<stdio.h>
void result();
inline void superFastRead(int *);

 

using namespace std;


inline void superFastRead (int *a) 
{
	char c = 0;
	while(c<33)
		c = fgetc_unlocked(stdin);
	//fread_unlocked(&c, sizeof(char), 1, stdin);
	*a = 0;
	while(c>33) 
	{
		*a = *a*10 + c - '0';
		//fread_unlocked(&c, sizeof(char), 1, stdin);
		c = fgetc_unlocked(stdin);
	}
}

int main(){
  int T;
  cin>>T;
  for(int i=0;i<T;i++)
	result();

return 0;

}


void result(){
  long long int N, M, length, a,b,c ;
  
  scanf("%lld %lld",&N, &M);
  
  int stick[N];
  long long int diag=0;
  for(int i=0;i<N;i++){ 
    scanf("%lld",&length);;
    stick[i]=length;
  }
  for(int i=0;i<M;i++){ 
    scanf("%lld %lld %lld",&a, &b, &c);
    long long int temp =a*a+b*b+c*c;
    if(temp>diag) diag=temp;
  }
  int count=0;
  diag = (int)sqrt(diag);
  for(int i=0;i<N;i++){
         if(stick[i]<=diag) count++;
  }
  cout<<count<<endl;
}
