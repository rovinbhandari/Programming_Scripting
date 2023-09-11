#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<stack>
#define cin(n) scanf("%d",&n)
#define pb push_back
#define push push_back
#define pop pop_back
#define mp make_pair

using namespace std;

const int max_n = 100000;

struct str
{
       int zo,zz,oo;
       str(){zo=zz=oo=0;}
       str(int a,int b,int c){zz=a;zo=b;oo=c;}
       int mx(){return max(max(oo,zz),zo);}
};
char arr[100001];

int beg[4*max_n+1], end[4*max_n+1]; str seg[4*max_n];

void make_seg(int pos, int start, int finish)			
{
	beg[pos] = start;
	end[pos] = finish;
	seg[pos] = str();									
	
	if(start == finish)
		return;
	
	int mid = (start + finish)/2;
	make_seg(2*pos, start, mid);
	make_seg(2*pos+1, mid+1, finish);
}
str query(int pos, int start, int finish)
{
	if(start <= beg[pos] && finish >= end[pos])
		return seg[pos];
	
	int left = 2*pos, right = left+1;

	if(finish <= end[left])
		return query(left, start, finish);
	
	if(start >= beg[right])
		return query(right, start, finish);
	
	str x = query(left, start, finish);
	str y = query(right, start, finish);
   return str(x.zz+y.zz,max(x.zo+y.oo,max(x.zz+y.zo,x.zz+y.oo)),x.oo+y.oo); 
}

void update(int pos, int idx, char num)		
{
	if(beg[pos] == end[pos])			
	{	
		seg[pos] = str(num=='0',0,num=='1');
		return;
	}
	
	if(idx >= beg[2*pos + 1])
		update(2*pos + 1, idx, num);
	else 
		update(2*pos, idx, num);
	str x=seg[2*pos];
	str y=seg[2*pos+1];
	seg[pos] = str(x.zz+y.zz,max(x.zo+y.oo,max(x.zz+y.zo,x.zz+y.oo)),x.oo+y.oo); 
}

int main()
{
    int t,n,q,a,b;
    cin>>t;
    for(;t>0;t--)
    {
             cin>>n;
             scanf("%s",arr);
             make_seg(1, 1, n);
             for(int i=1;i<=n;i++)
             {
                     update(1,i,arr[i-1]);
             }
             cin>>q;
             for(;q>0;q--)
             {
                          cin(a);cin(b);
                          cout<<query(1,a,b).mx()<<endl;
             }   
    }
    return 0;
}
