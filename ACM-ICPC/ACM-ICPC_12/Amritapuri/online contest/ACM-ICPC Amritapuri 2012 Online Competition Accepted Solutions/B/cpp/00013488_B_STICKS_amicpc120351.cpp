#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
      int t;
    cin>>t;
    while(t--)
    {
        long long n,m,count=0,r,i,j,k;
        cin>>n>>m;
        long long a[n],b[m][3],v[m];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            }
        sort(a,a+n);
        
        for(i=0;i<m;i++)
        for(j=0;j<3;j++)
        cin>>b[i][j];
        
        for(i=0;i<m;i++){
        r=b[i][0]*b[i][0]+b[i][1]*b[i][1]+b[i][2]*b[i][2];
        v[i]=(long long)sqrt(r);
}
        sort(v,v+m);
        j=0;
        for(i=0;i<n;i++)
                if(a[i]<=v[m-1])
                {
                    count++;
                    }
                /*else{
                     for(k=j;k<m;k++)
                     {
                             if(a[i]<=v[k])
                             {
                                 count++;
                                 j=k;
                                 }
                             }
                             }*/
        cout<<count<<endl;
        }
       //system("pause");
        return 0;
        }
