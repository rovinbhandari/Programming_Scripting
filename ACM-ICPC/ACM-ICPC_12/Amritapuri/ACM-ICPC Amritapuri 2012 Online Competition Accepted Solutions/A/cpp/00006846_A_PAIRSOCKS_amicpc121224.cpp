          
#include<iostream>
using namespace std;
int main()
{
       int countr,countg,countb,countw;
       int i,j,T;
       char c[50];
       cin>>T;
       int ans[T];
       for(i=0;i<T;i++)
       {
       for(j=0;j<50;j++)
                        c[j]='\0';
       countr=countb=countw=countg=0;
                       cin>>c;
                       for(j=0;j<50;j++)
                       {
                                        if(c[j]=='R')
                                                     countr++;
                                         if(c[j]=='G')
                                                      countg++;
                                         if(c[j]=='B')
                                                      countb++;
                                          if(c[j]=='W')
                                                       countw++;
                                                       }
                               if((countr%2==0)&&(countg%2==0)&&(countb%2==0)&&(countw%2==0))
                                    ans[i]=1;
                                    else
                                    ans[i]=0;
}
for(i=0;i<T;i++)
{
                if(ans[i]==1)
                cout<<"YES"<<endl;
                if(ans[i]==0)
                cout<<"NO"<<endl;
                }
return 0;
}                                          
                       
