#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 

#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#define LL long long
using namespace std; 



/*
int bin_search(int a[],int s,int g,int n)
{
    int l=g,i;
    int h=n-1;
     int mid,c=0;
     
     while(l<=h)
     {
        mid=(l+h)/2;
        //printf("%d\n",mid);
        if(s>=a[mid])
        l=mid+1;
        else
        {
        i=mid;
        while(s<a[i])
        {c++;
        i--;
        }
        c+=(n-1-mid);
        break;
        }
     }
     
     return c;
}*/
LL a[1005];

void q_sort(LL numbers[], LL left, LL right)
{
  LL pivot, l_hold, r_hold;
 
  l_hold = left;
  r_hold = right;
  pivot = numbers[left];
  while (left < right)
  {
    while ((numbers[right] >= pivot) && (left < right))
      right--;
    if (left != right)
    {
      numbers[left] = numbers[right];
      left++;
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++;
    if (left != right)
    {
      numbers[right] = numbers[left];
      right--;
    }
  }
  numbers[left] = pivot;
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot)
    q_sort(numbers, left, pivot-1);
  if (right > pivot)
    q_sort(numbers, pivot+1, right);
}
int n;
  int f(int L)
  {
      int i,j;
      int s,k,g;
      LL c=0;
      int flag=0;
              for(i=0;i<n;i++)
              {
                 for(k=n-1,j=i+1;j<n;j++)
                 {
               
                 while((a[i]+a[j]+a[k])>L )					
				 {k--;}
				
                 g=(k-j);
                 if(k<=j)
                { 
                 break;}
                 else
                 c+=(LL)g;
                 
                 }
                
              }
              
     return c;
              
     }
              
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
              int i,j;
              scanf("%d",&n);
              int L,H;
              scanf("%d %d",&L,&H);
            
            
              for(i=0;i<n;i++)
              scanf("%d",&a[i]);
                
               
             q_sort(a,0,n-1);
             
              
              a[n]=5000000;
              LL x=f(L-1);
              LL y=f(H);
              
          //  cout<<x<<" "<<y<<endl;
              printf("%lld\n",y-x);
    }
  //  getch();
    return 0;
}
              
              
              

