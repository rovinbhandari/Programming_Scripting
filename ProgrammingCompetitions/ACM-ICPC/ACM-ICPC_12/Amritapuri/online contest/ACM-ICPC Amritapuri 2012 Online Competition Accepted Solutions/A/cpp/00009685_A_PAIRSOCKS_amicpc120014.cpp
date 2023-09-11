#include<string>
#include<iostream>
using namespace std;
int main(){
	int n;
	char c;
	string w;
	int size;
	cin>>n;
	bool ans[4];
	bool an=1;
	
	
	for(int y=0;y<n;y++){
	cin >>w;
	an=1;
	size=w.size();

	for (int e=0;e<4;e++){
	    ans[e]=0;
	    }
	
	for (int z=0;z<size;z++){
		c=w[z];
		(c=='R')?ans[0]=!ans[0]:(c=='G')?ans[1]=!ans[1]:(c=='W')?ans[2]=!ans[2]:ans[3]=!ans[3];
		}
		
		for (int e=0;e<4;e++){
		if (ans[e]){
		an=0;
		break;
		}
		}
		
		(an)?(cout<<"YES\n"):(cout<<"NO\n");
		}
		
		return 0;
		}

