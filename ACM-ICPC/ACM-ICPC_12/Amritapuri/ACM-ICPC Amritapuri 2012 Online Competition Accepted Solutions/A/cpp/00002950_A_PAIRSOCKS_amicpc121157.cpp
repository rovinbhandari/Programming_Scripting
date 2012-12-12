#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
using namespace std;
 
//STL toolpack 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define for_range(i, first, last) for (typeof(first) i = (first); i != (last); ++i) 

//control extenders
#define DEBUG
#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back


//string split function(very usefull)
#include <sstream>
vector<string> split(string s) {
	stringstream A(s);
	vector<string> res;
	string t;
	while (A>>t) res.push_back(t);
	return res;
}
//usage:
//vector<string> fragments = split(input);

//gcd
int gcd(int a, int b) { return (a==0?b:gcd(b%a,a)); }



int main(){

    string s;
	int t;
	scanf("%d",&t);
    while(t--)
    {
        cin >> s;
        int red=0,blue=0,green=0,white=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='R')
                red++;
            if(s[i]=='G')
                green++;
            if(s[i]=='B')
                blue++;
            else
                white++;

        }
        int count=0;
        if(red%2==0)
            count++;
        if(green%2==0)
            count++;
        if(blue%2==0)
            count++;
        if(white%2==0)
            count++;

        if(count==4)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

	return 0;
}
