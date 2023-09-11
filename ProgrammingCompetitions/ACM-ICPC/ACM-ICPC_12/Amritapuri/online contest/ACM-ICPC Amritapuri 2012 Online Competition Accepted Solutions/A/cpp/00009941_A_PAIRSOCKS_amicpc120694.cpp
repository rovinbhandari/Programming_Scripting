#include<iostream>
using namespace std;
int main()
{
    int n=0;
    int len;
    int r=0,g=0,b=0,w=0;
    char str[50];
    cin>>n;
    for(int i=0;i<n;i++)
    {
		r=g=b=w=0;
            cin>>str;
                     for(int j=0;str[j]!='\0';j++)
                     {
                             switch(str[j])
                             {
                                           case 'R':r++;
                                                        break;
                                           case 'G':g++;
                                                        break;
                                           case 'B':b++;
                                                        break;
                                           case 'W':w++;
                                                        break;
                                                                                              
                             }
                     }
                     if(r%2==0&&g%2==0&&b%2==0&&w%2==0)
                     {
                           cout<<"YES\n";
                     }
                     else
                     cout<<"NO\n";
   			                    
            
    }
    return 0;
}
    
                                
