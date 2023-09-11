#include<cstdlib>
#include<iostream>

#include<string>

using namespace std;

int main(){
  int T, cr=0,cg=0,cb=0, cw=0;
  string input;
  cin>>T;
  for(int i=0;i<T;i++){
	cin>>input;
	cr=cb=cg=cw=0;
	int length = input.length();
        if(length%2!=0)
		cout<<"NO\n";
	else{
		for(int j=0;j<length;j++){
			if(input[j]=='R') cr++;
			else if(input[j]=='B') cb++;
			else if(input[j]=='G') cg++;
			else if(input[j]=='W') cw++;
		}
		if(cr%2==0 && cb%2==0 && cg%2==0 && cw%2==0)cout<<"YES\n";
		else cout<<"NO\n";
    	}

  } 
 return 0;	

}
