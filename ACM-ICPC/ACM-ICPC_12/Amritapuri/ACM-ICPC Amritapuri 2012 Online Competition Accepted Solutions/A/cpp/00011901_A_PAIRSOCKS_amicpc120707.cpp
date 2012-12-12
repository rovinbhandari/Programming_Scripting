#include<iostream>
using namespace std;
int ans[1000]; 
void sock(char s[],int m)
{
    int r=0,g=0,b=0,w=0;
    int j=0;
    while(s[j]!='\0')
    {
        switch(s[j])
        {
        case 'G' : g++;
                break;
        case 'R' : r++;
                break;
        case 'B' : b++;
                break;
        case 'W' : w++;
                break;
        default :break;
        }
        j++;
    }                    
    if(r%2==0&&g%2==0&&b%2==0&&w%2==0)
    ans[m]=1;
    else
    ans[m]=0;
}
 main()
{
    int T;
    cin>>T;
    char s[50];
    if(T>0&&T<=1000)
    {
        for(int i=0;i<T;i++)
        {
            cin>>s;
	    sock(s,i);
        }
	for(int i=0;i<T;i++)
        {
	    if(ans[i]==1)
            cout<<"YES\n";
	else
	cout<<"NO\n";
        }
	 
    }
}
