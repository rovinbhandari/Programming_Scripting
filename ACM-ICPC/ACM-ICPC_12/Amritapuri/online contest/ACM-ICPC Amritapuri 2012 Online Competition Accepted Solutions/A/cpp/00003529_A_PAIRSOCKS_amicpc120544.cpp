#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
   int n;
   cin>>n;
   while(n--)
   {
             string ar;
             ar.c_str();
             int count[4];
             unsigned int i;
             count[0]=count[1]=count[2]=count[3]=0;
             cin>>ar;
             for(i=0;i<ar.length();i++)
             {
                                       if(ar[i]=='B')
                                       count[0]++;
                                       if(ar[i]=='G')
                                       count[1]++;
                                       if(ar[i]=='R')
                                       count[2]++;
                                       if(ar[i]=='W')
                                       count[3]++;
             }
             if(count[0]%2==0&& count[1]%2==0 &&count[2]%2==0 && count[3]%2==0)
                                cout<<"YES"<<endl;
             else
                                cout<<"NO"<<endl;
}
}

 
