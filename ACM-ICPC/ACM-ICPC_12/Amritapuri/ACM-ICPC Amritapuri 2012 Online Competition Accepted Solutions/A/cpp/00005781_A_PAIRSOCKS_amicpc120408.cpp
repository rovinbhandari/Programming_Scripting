#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(){
        long long int t;
        char c;
        scanf("%lld\n",&t);
        int a[4],r[t];
        a[0]=0;
        a[1]=0;
        a[2]=0;
        a[3]=0;
        for(long long int i=0;i<t;i++)
        {
                scanf("%c",&c);
                while(c!=' '&&c!='\t'&&c!='\n')
                {
                        if(c=='R'||c=='r')
                                a[0]++;
                        else if(c=='G'||c=='g')
                                a[1]++;
                        else if(c=='B'||c=='b')
                                a[2]++;
                        else
                                a[3]++;
                        scanf("%c",&c);
                }
                if((a[0]%2==0)&&(a[1]%2==0)&&(a[2]%2==0)&&(a[3]%2==0))
                      r[i]=true;
                else
                        r[i]=false; 
                a[0]=0;
                a[1]=0;
                a[2]=0;
                a[3]=0; 
                        
         }
         
         for(long long int i=0;i<t;i++)
          {
                if(r[i]==0)
                        cout<<"NO"<<endl;
                else
                         cout<<"YES"<<endl;
}


return 0;
}
