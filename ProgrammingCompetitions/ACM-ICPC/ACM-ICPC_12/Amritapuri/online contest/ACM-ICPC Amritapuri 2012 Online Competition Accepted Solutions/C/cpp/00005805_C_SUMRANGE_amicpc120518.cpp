#include<stdio.h>
#include<algorithm>

using namespace std;

int inp[1005];
int n, l, h;

int coun(int val, int i)
{
int j, out, k;
j=n-1;
out = 0;
while(i<j)
{
if( ((val + inp[i] + inp[j]) <= h) && ((val + inp[i] + inp[j]) >= l) )
{
++out;
//printf("i: %d, a\n", i);
for(k = j-1; (k>i) && ((val + inp[i] + inp[k]) >= l); --k)
{
//printf("i: %d, b\n", k);
++out;
}
++i;
}
else if((val + inp[i] + inp[j]) > h)
{
--j;
}
else if((val + inp[i] + inp[j]) < l)
{
++i;
}
}
return out;
}

int main()
{
int t, i, out;
scanf("%d", &t);
while(t--)
{
scanf("%d %d %d", &n, &l, &h);
for(i=0; i<n; ++i)
{
scanf("%d", &inp[i]);
}
sort(inp, inp+n);
out = 0;
for(i=0; i<n; ++i)
{
out += coun(inp[i], i+1);
//printf("%d %d\n", i, out);
}
printf("%d\n", out);
}
return 0;
}