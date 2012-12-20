#include<iostream>

using namespace std;

int main()
{
    int t,q,s[1000];
    char ch[51];
    cin>>t;
    for(q=0;q<t;q++)
    {
	int i=0,r=0,g=0,b=0,w=0;s[q]=0;
        cin>>ch;
        while(ch[i]!='\0')
        {
            switch(ch[i])
            {
                case 'R' : r++; break;
                case 'G' : g++; break;
                case 'B' : b++; break;
                case 'W' : w++; break;
            }
            i++;
        }

        if(r%2 == 0 && g%2 == 0 && b%2 == 0 && w%2 == 0)
          s[q]=1;
        else
          s[q]=0;
    }
    for(q=0;q<t;q++)
    {

	if(s[q]==0)
	  cout<<"NO";
	else
	  cout<<"YES";
	          cout<<endl;
    }
    return 0;
}
