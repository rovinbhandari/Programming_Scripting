

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int t,n,m;
	int l,b,h,count=0;
	int i,j;
	double sl[50000],bl,bll;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n>>m;
		for(j=0;j<n;j++){
			cin>>sl[j];
		}
		cin>>l>>b>>h;
		bl=sqrt((double)((b*b)+(h*h)));
		bl=sqrt((double)(l*l)+(bl*bl));
		for(j=1;j<m;j++){
			cin>>l>>b>>h;
				bll=sqrt((double)((b*b)+(h*h)));
				bll=sqrt((double)(l*l)+(bll*bll));
				if(bll>bl){
					bl=bll;
				}
		}
		for(j=0;j<n;j++){
			if(sl[j]<=bl){
				count++;
			}
		}
		
		cout<<count<<endl;
		count=0;
			
	}
	return 0;
}

