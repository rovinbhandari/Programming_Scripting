#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;
struct st{
	long int a, b, c, sqrmax, max;
	bool operator<(st o) const {
		return sqrmax < o.sqrmax;
	}
};
/*struct st2{
	int p, q, key;
	bool operator<(st2 o2) const{
		return p < o2.p;
	}
};
*/
int main()
{
	int t;
	cin>>t;
	while(t--) {
		int n, m, i, j, k, h;
		cin>>n>>m;
		int s[n];
		st box[m];
//		st2 box2[m];
/*		int b[100050] = {0};
		int c[100050] = {0};
		int sqrmax[100050] = {0};
		int max[100050] = {0};
*/		for(i = 0; i < n; ++i) {
			cin>>s[i];
		}
		
		for(i = 0; i < m; ++i) {
			cin>>box[i].a>>box[i].b>>box[i].c;
			box[i].sqrmax = sqrt(box[i].a*box[i].a + box[i].b*box[i].b + box[i].c*box[i].c);
			
			if(box[i].a >= box[i].b && box[i].a >= box[i].c)
				box[i].max = box[i].a;
			else if(box[i].b >= box[i].a && box[i].b >= box[i].c)
			        box[i].max = box[i].b;
			else 
			        box[i].max = box[i].c;
		}
		sort(box, box+m);
		k = 0;
		for(i = 0; i < n; ++i) {
			if(s[i] <= box[m-1].sqrmax)	++k;
		}
		cout<<k<<endl;
	}
	return 0;
}
			
