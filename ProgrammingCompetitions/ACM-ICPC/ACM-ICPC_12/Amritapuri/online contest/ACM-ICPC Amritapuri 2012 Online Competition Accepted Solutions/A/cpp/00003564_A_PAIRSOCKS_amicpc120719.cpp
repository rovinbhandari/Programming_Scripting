#include <iostream>
#include <cstring>

using namespace std;
bool check(char *s,int len)
{
 	 char ch;
 	 int i=3,ctr;
 	 char color[4]={'R','G','B','W'};
 	 while (i>-1)
 	 {
	  	   ctr=0;
			 for (int j=0;j<len;j++)
	  	   {
		   	   if (color[i]==s[j])
		   	   	  ctr++;
           }
           if (ctr%2)
           	  return false;
           	  i--;
			  }
			  return true;
			  }
int main()
{
 	int t,n;
 	char str[50];
	 for (cin>>t;t--;cin>>str,n=strlen(str),cout<<(check(str,n)?"YES":"NO")<<endl);
return 0;
}
