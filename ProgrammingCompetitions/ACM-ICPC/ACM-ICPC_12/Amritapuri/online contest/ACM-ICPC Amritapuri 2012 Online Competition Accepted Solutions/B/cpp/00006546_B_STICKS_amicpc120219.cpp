#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{     int t;
      cin>>t;
      while(t--)
      {         int n,m;
                cin>>n>>m;
                int L[n],box[m][4],maxlen=0,ctr=0;
                for(int i=0;i<n;i++)
                        cin>>L[i];
                for(int i=0;i<m;i++)
                {       for(int j=0;j<3;j++)
                               cin>>box[i][j];
                        double diag=sqrt(pow(box[i][0],2)+pow(box[i][1],2)+pow(box[i][2],2));
                        if(diag>maxlen)
                                       maxlen=(int)diag;
                }
                for(int i=0;i<n;i++)
                                if(L[i]<=maxlen)
                                                ctr++;
                cout<<ctr<<"\n";       
      }
      return 0;
}
      
