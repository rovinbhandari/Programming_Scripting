using namespace std;
#include<iostream>
#include<cstring>

int main(){
	char p[50];
	int com[4]={0,0,0,0};
	int t,i,j,length;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>p;
		length=strlen(p);
		for(j=0;j<length;j++)
		{
			if(p[j]=='R'){
				com[0]++;
			}
			else if(p[j]=='G'){
				com[1]++;
			}
			else if(p[j]=='B'){
				com[2]++;
			}
			else if(p[j]=='W')
			{
				com[3]++;
			}
		}
		if(com[0]%2==0 && com[1]%2==0 && com[2]%2==0 && com[3]%2==0)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
		
		com[0]=0;
		com[1]=0;
		com[2]=0;
		com[3]=0;
	}
}
