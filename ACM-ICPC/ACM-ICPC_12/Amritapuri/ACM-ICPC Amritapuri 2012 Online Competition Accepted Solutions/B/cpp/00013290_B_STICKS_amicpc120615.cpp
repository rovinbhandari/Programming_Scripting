#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
       int N,M;
       cin>>N>>M;
       vector<int> stick(N,0);
       //Get the sticks
       for(int i=0;i<N;i++)
       scanf("%d",&stick[i]);
       
       //Get the box dimensions
        long long l,b,h;
        
      
        
       //vector< double > box(M);//Store the maximum in each box
      
       double maxi=0,sq; 
       for(int i=0;i<M;i++)
       {
            
           cin>>l>>b>>h;
           // scanf("%d%d%d",&l,&b,&h);
            long long lbh=(l*l + b*b + h*h);
            sq=sqrt(lbh * 1.0);
            
            if (sq >maxi)
            maxi=sq;
           // cout<<l<<" "<<b<<" "<<h<<" - "<<sq<<" - "<<maxi<<endl;
            
       }
       int ret=0;
       //sort(box.begin(),box.end());
       
       //Process the Sticks to see if they fit
       for(int i=0;i<N;i++)
       {
            if(stick[i]<=maxi)
            ret++;
       }
       /*
       for(int i=0;i<N;i++)
       {
       		int flag=0;	
            for(int j=0;j<M;j++)
            {
            	if(stick[i]<=box[j])
            	{
            		flag=1;
            		break;
            	}
            }
           if(flag==1)
           ret++;

       }
       */
       cout<<ret<<endl;

    }
    return 0;
}
