#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;
int main()
{
	int n,i=0,count[4],l,j=0,flag;
	
	char str[51];
	cin>>n;	
	i = 0;
	while(i<n)
	{
	        memset(str,' ',51);
	        j=0;
	        while(j<4)
	        {
	                count[j] = 0;
	                j++;
	        }
                cin>>str;
                l = strlen(str);
                j=0;
                while(j<l)
                {
                        if(str[j] == 'R')
                        {
                                count[0]++;  
                                
                        }
                        if(str[j] == 'G')
                        {
                                count[1]++;       
                        }
                        if(str[j] == 'B')
                        {
                                count[2]++;       
                        }
                        if(str[j] == 'W')
                        {
                                count[3]++;       
                        }
                        j++;
                }
                j=0;
                flag = 0;
                while(j<4)
                {
                        if(count[j] % 2 != 0)
                        {
                                flag = 1;
                                cout<<"NO"<<endl;
                                break;
                        }
                        j++;
                }
                if(flag == 0)
                {
                        cout<<"YES"<<endl;
                }
		i++;
	}


	return 0;
}
