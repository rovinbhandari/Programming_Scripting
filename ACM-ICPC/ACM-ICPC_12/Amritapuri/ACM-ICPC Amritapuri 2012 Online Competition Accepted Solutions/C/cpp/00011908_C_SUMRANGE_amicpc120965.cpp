#include<iostream>
using namespace std;
long x[1000];
int n;
int binsearch(int search)
{
int first = 0;
int last = n - 1;
int middle = (first+last)/2;

while( first <= last )
{
if ( x[middle] < search )
first = middle + 1; 
else if ( x[middle] == search ) 
{
return middle+1;
}
else
last = middle - 1;

middle = (first + last)/2;
}	
if(last<0)
return 0;
else
return last+1;
}
int binsearch1(int search)
{
int first = 0;
int last = n - 1;
int middle = (first+last)/2;

while( first <= last )
{
if ( x[middle] < search )
first = middle + 1; 
else if ( x[middle] == search ) 
{
return middle;
}
else
last = middle - 1;

middle = (first + last)/2;
}	
if(last<0)
return 0;
else
return last+1;
}
void quicksort(int first,int last){
int pivot,j,temp,i;
if(first<last){
pivot=first;
i=first;
j=last;
while(i<j){
while(x[i]<=x[pivot]&&i<last)
i++;
while(x[j]>x[pivot])
j--;
if(i<j){
temp=x[i];
x[i]=x[j];
x[j]=temp;
}
}
temp=x[pivot];
x[pivot]=x[j];
x[j]=temp;
quicksort(first,j-1);
quicksort(j+1,last);
}
}
int main()
{
long l, h,count=0;
int t;
cin>>t;
for(int q=0;q<t;q++)
{
cin>>n>>l>>h;

for(int i=0;i<n;i++)
{
cin>>x[i];
}
quicksort(0,n-1);
for (int i = 0; i < n-1; i++)
{
for (int j = i+1; j < n; j++)
{
int z,y;
long c=x[i]+x[j];
z=binsearch(l-c-1);
y=binsearch1(h-c+1);
if(i>=z && i<y)
count--;
if(j>=z && j<y)
count--;	
count+=y-z;
}
}
cout<<count/3<<"\n";
count=0;
}

}
