#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    char socks[1000];
    int r=0;
    int b=0;
    int g=0;
    int w=0;
    int flag=0;
    int no_test_cases;
    cin>>no_test_cases;
    int * solnarr=(int *)malloc((no_test_cases)*sizeof(int));
    int k=0;
    while(k<no_test_cases)
    {
             cin>>socks;
             for(int i=0;socks[i]!='\0'&& flag==0;i++)
             { 
                                          switch(socks[i])
                                          {
                                                          case 'R':
                                                          case 'r': r++;
                                                                    break;
                                                          case 'B':
                                                          case 'b': b++;
                                                                    break;
                                                          case 'G':
                                                          case 'g': g++;
                                                                    break;
                                                          case 'W':
                                                          case 'w': w++;
                                                                    break;
                                                          default:  flag=1;
                                                                    break;
                                                                    
                                          }
             }
             if(r%2==0 && b%2==0 && g%2==0 && w%2==0 && flag==0)
             {
                       
                       solnarr[k]=1;
             }
             else
                       solnarr[k]=0;
                
             k++;;   
             r=b=g=w=0;  
    }  
      for(k=0;k<no_test_cases;k++)
      {
                                  if(solnarr[k]==0)
                                                   cout<<"NO"<<endl;
                                  else
                                                   cout<<"YES"<<endl;
                                  } 
                                             
 return 0;                                         
}
