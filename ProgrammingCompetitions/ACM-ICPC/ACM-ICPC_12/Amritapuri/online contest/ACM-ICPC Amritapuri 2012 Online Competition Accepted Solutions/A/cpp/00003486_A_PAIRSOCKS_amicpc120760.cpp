#include<iostream>
#include<math.h>
#include<string>

using namespace std;

int main(){
	int i=0;
	int j=0;
	int k=0;
	string mystring;
	int mystrings;
	int a[4];
	cin>>j;
	while(k<j){
		cin>>mystring;
		mystrings=mystring.size();	
		a[0]=0;
		a[1]=0;
		a[2]=0;
		a[3]=0;
		i=0;
		while (i<mystrings){
			if (mystring[i]=='R') a[0]++;
			if (mystring[i]=='G') a[1]++;
			if (mystring[i]=='B') a[2]++;
			if (mystring[i]=='W') a[3]++;
			i++;
		}
		if ((a[0]%2==0) && (a[1]%2==0) && (a[2]%2==0) && (a[3]%2==0)){
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	k++;
	}
}
			
				
