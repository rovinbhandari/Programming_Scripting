// orders using seg tree.cpp : main project file.

//#include "stdafx.h"
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int t[400100];
char arr[101000];
//int ans[100100];
int nz[400100];
int no[400100];
struct nde
{
       int val;
       int nze;
       int non;
};
void build(int node,int s,int e)
{
	if(s==e)
		{
            
			t[node]=1;
			if(arr[s]=='0')
			{ nz[node]=1;}
		 else if(arr[s]=='1')
		 { no[node]=1;}
	//	  cout<<s<<" "<<e<<"         "<<arr[s]<<"       "<<t[node]<<" "<<nz[node]<<" "<<no[node]<<endl;		 
			return;
	    }
	int mid=(s+e)>>1;
	int n1=node<<1;
	build(n1,s,mid);
	build((n1)+1,mid+1,e);
//	cout<<s<<" "<<e<<"          "<<nz[node*2]<<" "<<no[node*2]<<endl;
//cout<<s<<" "<<e<<"          "<<nz[node*2+1]<<" "<<no[node*2+1]<<endl;
	t[node]=max(t[n1]+no[n1+1],t[n1+1]+nz[n1]);
	nz[node]=nz[n1]+nz[n1+1];
	no[node]=no[n1]+no[n1+1];
//	cout<<s<<" "<<e<<"         "<<t[node]<<" "<<nz[node]<<" "<<no[node]<<endl;
	
}
nde query(int node,int lr,int rr,int a,int b)
{
    nde an;
    if((b<lr)||(a>rr))
     {
                      an.val=0;
                      an.nze=0;
                      an.non=0;
                      
                       return an;
     }
      
      
    if((a<=lr)&&(b>=rr))
     {
                        an.val=t[node];
                        an.nze=nz[node];
                        an.non=no[node];
                          return an;

     }    
    else 
     {
         nde bn,cn;
         
          cn=query(node*2,lr,(lr+rr)/2,a,b);
          bn=query(node*2+1,(lr+rr)/2+1,rr,a,b);
          an.nze=cn.nze+bn.nze;
          an.non=cn.non+bn.non;
          an.val=max(cn.val+bn.non,bn.val+cn.nze);
          return an;
     }
}
        

int main()
{
	int tests;
	cin>>tests;
	while(tests--)
	{
		int num;
		cin>>num;
		memset(t,0,sizeof(t));
		memset(nz,0,sizeof(nz));
     	memset(no,0,sizeof(no));
		//memset(ans,0,sizeof(ans));
		//for(int i=0;i<num;i++)
		cin>>arr;
		build(1,0,num-1);
		int q;
		cin>>q;
		for(int i=0;i<q;i++)
		{
                int x,y;
                cin>>x>>y;
                nde aval=query(1,0,num-1,x-1,y-1);
		       cout<<aval.val<<endl;
         }
      }
}

		
