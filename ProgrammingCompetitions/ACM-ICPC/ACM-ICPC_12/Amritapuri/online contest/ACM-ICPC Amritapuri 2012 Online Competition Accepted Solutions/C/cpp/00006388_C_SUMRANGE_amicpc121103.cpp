using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
# define MAX 10000001
# define MOD 10007int main(){

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define F first
#define S second

#define VI vector<int>


int main(){

int ar[10000];
int t, n, h,l;

cin>>t;

while(t--){

//co/ut<<"loop \n";


scanf("%d%d%d",&n, &l, &h);
string line;
getline(cin,line);
getline(cin,line);
stringstream scin(line);
//cout<<"string is =  "<<line;

FOR(i,0,n)
{
  //  scanf("%d",&ar[i]);
    scin>>ar[i];
}

int ans=0;

sort(ar,ar+n);


FOR(i,0,n)
{
FOR(j,i+1,n)
{

if((ar[i]+ar[j])>h)
break;

FOR(k,j+1,n)
{

if( (ar[i]+ar[j]+ar[k]) <=h)
{ if( (ar[i]+ar[j]+ar[k]) >=l)
  ans++;



}
else
break;

}



//cout<<"loop pp\n";
}


//cout<<"loop sdfdv \n";
}

//co/ut<<"loop end \n";

printf("%d\n",ans);


/*
FOR(i,0,n)
{
int p=i+1,q=n-1;

while(p<=q)//check error
{

if(((ar[i]+ar[p]+ar[q])<=h) && (ar[i]+ar[p]+ar[q])>= l)
{ans++;

}
else if((ar[i]+ar[p]+ar[q])>h)
q--;

else if((ar[i]+ar[p]+ar[q])<l)
p++;


}


}*/

}







return 0;
}
