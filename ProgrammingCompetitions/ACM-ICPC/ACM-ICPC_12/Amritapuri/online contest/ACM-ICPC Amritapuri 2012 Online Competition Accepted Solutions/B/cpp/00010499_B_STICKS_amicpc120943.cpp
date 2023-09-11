
#include <iostream>
#include <cstdlib>
#include<math.h>
using namespace std;

int compare (const void *elem1, const void *elem2)
{
return *(int*)elem1 - *(int*)elem2;
}

int main()
{
int n,m,t;
char ch;
cin>>t;
while(t>0)
{

int count=0;
cin>>n>>m;
int l[n];
int a[m],b[m],c[m];
int diagonal[m];
for(int i=0;i<n;i++)
{
cin>>l[i];

}

for(int i=0;i<m;i++)
{
cin>>a[i]>>b[i]>>c[i];
diagonal[i]=sqrt(pow(a[i],2)+pow(b[i],2)+pow(c[i],2));
}



qsort(l, n, sizeof(int), compare);
qsort(diagonal, m, sizeof(int), compare);
/*for(int i=0;i<m;i++)
{
cout<<l[i]<<endl;
}*/

for(int i=n-1;i>=0;i--)
{
//int flag=0;

for(int j=m-1;j>=0;j--)
{
if(l[i]>diagonal[j])
{
break;
}
else
{
count++;
//flag=1;
break;
}

}
}
cout<<count<<endl;

//cin>>ch;



t--;
}
return 0;
}


