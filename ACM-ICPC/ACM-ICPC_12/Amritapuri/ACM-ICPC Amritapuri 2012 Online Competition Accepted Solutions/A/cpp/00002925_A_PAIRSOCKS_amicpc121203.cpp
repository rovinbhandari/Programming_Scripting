#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

#define	gi(a)		scanf("%d",&a)
#define	Int(a)		int a;gi(a);
#define Pair		pair <int,int>
#define mp		make_pair
#define ll		long long
#define INF		2147483647
#define clear(a,b)	memset(a,b,sizeof(a))
#define dbg(x) cerr<<#x<<" ="<<(x)<<endl

template <class T>
inline void ri(T &i){
	bool minus=false;
	char c;
	for(c=getchar();(c<'0'||c>'9')&&(c!='-');
		      c=getchar());
	if(c=='-')
		      {minus=true;c='0';}
	for(i=0;c>='0'&&c<='9';c=getchar())
		      i=(i<<3)+(i<<1)+(c-48);
	if(minus)i=(~i)+1;
}

int main(){
	char str[100];
	Int(t);
	while(t--){
		cin>>str;
		int r,g,b,w,i;
		r=g=b=w=0;
		int l=strlen(str);
		for(i=0;i<l;i++){
			if(str[i]=='R')	r++;
			if(str[i]=='G')	g++;
			if(str[i]=='B')	b++;
			if(str[i]=='W')	w++;
		}
		if(!(r%2) && !(g%2) && !(b%2) && !(w%2))	cout<<"YES"<<endl;
		else	cout<<"NO"<<endl;
	}
	return 0;
}
