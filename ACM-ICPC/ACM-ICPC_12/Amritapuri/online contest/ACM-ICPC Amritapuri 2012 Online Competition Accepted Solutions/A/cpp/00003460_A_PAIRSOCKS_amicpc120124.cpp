#include <iostream>

using namespace std;

int main()
{
	int testcases;/*max=1000*/
	char str[50];
	char ch;
	int i, j;
	int pairs[26];
	
	cin>>testcases;/*Get test-casea*/

	for(i=0; i<testcases; i++)
		{
			cin>>str;

			for(int k=0;k<26;k++)/*Reset pairs*/
				pairs[k]=0;

			j=0;
			while(str[j]!='\0')
				{
					pairs[str[j]-'A']++;
					j++;
				}
			if((pairs['R'-'A']%2)||(pairs['G'-'A']%2)||(pairs['B'-'A']%2)||(pairs['W'-'A']%2))
				cout<<"NO"<<endl;
			else
				cout<<"YES"<<endl;
		}
	return 0;
}
