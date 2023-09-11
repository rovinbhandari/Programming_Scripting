
#include <iostream>
#include<string.h>
using namespace std;
int main()
{
	int T; 
	cin>>T;
	
     if((T<=0) || (T>1000))
	return 0;

        char str[T][50];
 	int i,j,r=0,w=0,b=0,g=0;

	

for(i=0;i<T;i++)
{
cin>>str[i];
r=0;w=0;b=0;g=0;

if(strlen(str[i])%2!=0)
	cout<<"NO\n";
else
{
for(j=0;str[i][j]!='\0';j++)
{
if(str[i][j]=='R')
	r++;
else if(str[i][j]=='W')
	w++;
else if(str[i][j]=='G')
	g++;
else if(str[i][j]=='B')
	b++;
else
	return 0;
}


  if((r%2==0) && (w%2==0) && (g%2==0) && (b%2==0))
  cout<<"YES\n";
  else
  cout<<"NO\n";

}
}
}

