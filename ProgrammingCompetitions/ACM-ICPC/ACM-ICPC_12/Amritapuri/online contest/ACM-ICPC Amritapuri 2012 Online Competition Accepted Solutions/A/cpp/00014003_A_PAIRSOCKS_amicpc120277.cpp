#include<iostream>

using namespace std;
int main()
{
    int n,i,ans[1001],t;
    int flag;
    char c[100];
    int p[4];
    cin>>n;
    if((n>=1)&&(n<=1000))
    {

    for(i=1;i<=n;i++)
            {
            for(t=0;t<4;t++)
                     p[t]=0;

            flag=1;
                         cin>>c;
                         int k=0;
                         while(c[k]!='\0')
                         {
                         if(c[k]=='G')
                           {
                                      p[0]++;
                                      
                                      if(p[0]==2)
                                                 p[0]=0;
                         }
                                        
                         else if(c[k]=='R')
                           {
                                      p[1]++;
                                      if(p[1]==2)
                                                 p[1]=0;
                         }
                         else if(c[k]=='B')
                           {
                                      p[2]++;
                                      if(p[2]==2)
                                                 p[2]=0;
                         }
                         else if(c[k]=='W')
                           {
                                      p[3]++;
                                      if(p[3]==2)
                                                 p[3]=0;
                         }
                         k++;
                         }

          
    for(int j=0;j<4;j++)
    {       
            if(p[j]==1)
                   {
                                      flag=0;

                               ans[i]=0;
                                break;
                                                 
                               }
    }
    if(flag==1)
               ans[i]=1;
}
 for(i=1;i<=n;i++)
 
 { 

                     if(ans[i]==1)
                               cout<<"YES"<<endl;
                  else
                               cout<<"NO"<<endl;
}
}

    return 0;
}



    
    
