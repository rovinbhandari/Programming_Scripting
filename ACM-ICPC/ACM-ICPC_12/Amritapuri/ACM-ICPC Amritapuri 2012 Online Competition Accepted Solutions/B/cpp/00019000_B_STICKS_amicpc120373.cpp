#include<iostream>
#include<stdio.h>
#include<map>
#include<math.h>
#include<string.h>

using namespace std;

int main()
{  string str,s,abc;
    int t;
    cin>>t;
    while(t--)
    {
       int n,m;
       cin>>n>>m;
       long long int countd4=0,saved4,countd4e=0;
       double *st=new double[n];
       for(int i=0;i<n;i++)
       {
           cin>>st[i];
           //mymap[st[i]]++;          
       }
       double *l=new double[m];
       double *b=new double [m];
       double *h=new double[m];
       long double maxd4=0,root,roots;
       for(int i=0;i<m;i++)
       {
           cin>>l[i]>>b[i]>>h[i];
           root=l[i]*l[i];
           root=root+b[i]*b[i];
           root=root+h[i]*h[i];
           roots=sqrtl(root);
           if(maxd4<roots)
           maxd4=roots;
           
       }
       for(int i=0;i<n;i++)
       {
           
           if(ceil(maxd4)>st[i])
           {
           
           countd4++;
           }
           else if(ceil(maxd4)==st[i])
           
           {
        
                if(ceil(maxd4)==floor(maxd4)) countd4e++;}
      }
      
      if(countd4e>2)
      countd4e=2;
      long long int count=countd4+countd4e;
      cout<<count<<"\n";
      getline(cin,str);
      }
      return 0;
}
