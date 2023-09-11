#include<iostream>
#include<string>
using namespace std;

int main()
{
          int N, testCases,j,k;
          string c;
          cin>>testCases;
          for(int i = 0; i<testCases; i++)
          {
                  cin>>c;
                  int color[4] = { 0 };
                  N = c.length();
                  if(N%2 != 0)
                  {
                         cout<<"NO"<<endl;       
                  } 
                  else
                  {
                        for(j=0, k=N-1; j<N/2 && k>=N/2; j++, k--)
                        {
                                 if(c[j]=='R')
                                 {
                                              color[0]++;             
                                 }
                                 else if(c[j]=='G')
                                 {
                                      color[1]++;
                                 }
                                 else if(c[j]=='B')
                                 {
                                    color[2]++;
                                 }
                                 else if(c[j]=='W')
                                 {
                                    color[3]++;
                                 }
                                 
                                 //k
                                 if(c[k]=='R')
                                 {
                                              color[0]++;             
                                 }
                                 else if(c[k]=='G')
                                 {
                                      color[1]++;
                                 }
                                 else if(c[k]=='B')
                                 {
                                    color[2]++;
                                 }
                                 else if(c[k]=='W')
                                 {
                                    color[3]++;
                                 }  
                        }
                        if(color[0]%2==0 && color[1]%2==0 && color[2]%2==0 && color[3]%2==0)
                        {
                                cout<<"YES"<<endl;
                        }
                        else
                        {
                            cout<<"NO"<<endl;
                        }  
                  }       
          }
          return 0;  
}
