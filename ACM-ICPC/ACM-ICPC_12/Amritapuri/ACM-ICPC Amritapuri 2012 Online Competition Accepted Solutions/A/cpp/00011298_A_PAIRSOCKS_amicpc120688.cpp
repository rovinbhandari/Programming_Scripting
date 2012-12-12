#include<iostream>
#include<string.h>
using namespace std;
int main()
{
int t;
cin>>t;
char a[1000][50];
int res[1000];

int len=0;
for(int i=0;i<t;i++)
        {
        int r=0,g=0,b=0,w=0;
        cin>>a[i];
        //cout<<a[i]<<endl;
        for(int j=0;j<strlen(a[i]);j++)
                {
                 //cout<<a[i][j]<<endl;
                if(a[i][j]=='R')
{
r++;//cout<<r<<endl;
}
                else if(a[i][j]=='G')
{ g++;//cout<<g<<endl;
}
                else if(a[i][j]=='B'){ b++;//cout<<b<<endl;
}
                else if(a[i][j]=='W'){ w++;//cout<<w<<endl;
}
                else break;
                }

        len=strlen(a[i]);
       //cout<<len<<endl;
	if(len==0) 
        {
	//strcpy(res[i],"NO");
	res[i]=0;
	}
else if(len%2==1) 
{
//strcpy(res[i],"NO");
res[i]=0;
}
	else if(r%2==1 || w%2==1 || b%2==1 || g%2==1) 
        {
	res[i]=0;
	//cout<<"testingL:"<<res[i];
	}
      else 
       res[i]=1;
		//cout<<"testing yes::"<<res[i];}
		
       }
for(int i=0;i<t;i++) 
	{
	if(res[i]==1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	}
       return 0;
                                    }                                                
