#include<iostream>
#include<string.h>
using namespace std;
int main()
{     int t;
      cin>>t;
      while(t--)
      {         char arr[100],r='R',b='B',g='G',w='W';
                int ctrr=0,ctrb=0,ctrg=0,ctrw=0;
                cin>>arr;
                int l=strlen(arr);
                for(int i=0;i<l;i++)
                {       if(arr[i]==r) ctrr++;
                        else if(arr[i]==b) ctrb++;
                        else if(arr[i]==g) ctrg++;
                        else if(arr[i]==w) ctrw++;
                }
                if(!(ctrr%2) && !(ctrb%2) && !(ctrg%2) && !(ctrw%2))
                             cout<<"YES\n";
                else
                             cout<<"NO\n";
      }
      return 0;
}
      
