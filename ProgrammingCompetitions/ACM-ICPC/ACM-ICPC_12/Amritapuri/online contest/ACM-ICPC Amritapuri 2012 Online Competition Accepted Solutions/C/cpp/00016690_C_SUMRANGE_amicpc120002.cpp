#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;
int temp1[1001];
int temp[1001][1001];
void mergesort(int idx, int left,int right);
void merge(int idx, int left,int right,int mid);
void mergesort(int idx, int left,int right)
{
     
    if(left<right)
    {
                  int mid=(left+right)/2;
                  mergesort(idx,left,mid);
                  mergesort(idx, mid+1,right);
                  merge(idx,left,mid,right);    
                  }
                  }
void merge(int idx, int left,int mid,int right)
{
     int m,k;
     int j=mid+1;
    int i=left;
    j=mid+1;
    k=left;
    while((i<=mid) && (j<=right))
    {
                   if(temp[idx][i]<=temp[idx][j])
                   {temp1[k++]=temp[idx][i++];}
                   else
                   {temp1[k++]=temp[idx][j++];}
                   }
    while(i<=mid)
    temp1[k++]=temp[idx][i++];
    while(j<=right)
    temp1[k++]=temp[idx][j++];
    for(m=left;m<=right;m++)
    temp[idx][m]=temp1[m]; 
}
#define clr(a) memset(a,0,sizeof(a))
#define set(a) memset(a,-1,sizeof(a))
#define R(a) freopen(a,"r",stdin)

template <class T> T gcd(T a, T b) { return b==0 ? a : gcd(b,a%b) ; }
template <class T> T maxm(T a, T b) { return a > b ? a : b ; }
template <class T> T minm(T a, T b) { return a < b ? a : b ; }
template <class T> T abs(T a) { return a > 0 ? a : (-1)*a ; }
template <class T> T sq(T a) { return a * a ; }

int bs(int num,int index,int last)
{
    int beg,end,mid;
    beg=index;
    int index1=index+1;
    end=last;
    mid=(beg+end)/2;
    while(beg<end)
    {
                  if(temp[index1][mid]<num) beg=mid+1;
                  else if(temp[index1][mid]>num) end=mid-1;
                  else  return mid;
                                    mid=(beg+end)/2;
    }
    //mid=(beg+end)/2;
    return mid;
//    return (beg+end)/2;
}
int tmp[1000009];
int h1[1000009];
int main()
{
    int t,cnt,n,m,max,i,a[1001],j,l,h,a1[1001],n1,n2;
    scanf("%d",&t);
    while(t--)
    {
             /* scanf("%d",&n1);
              for(i=0;i<n1;++i)
              scanf("%d",&a1[i]);
              while(1)
              {
                      scanf("%d",&n2);
                      int idx1=bs(n2,0,n1-1);
                      printf("%d %d\n",idx1,a1[idx1]);
                      }
                      
              continue;*/
              cnt=0;
              scanf("%d%d%d",&n,&l,&h);
              for(i=0;i<n;++i)
              {
                              scanf("%d",&a[i]);
                              }
              for(i=1;i<n;++i)
              {
                              for(j=i;j<n;++j)
                              {
                                         temp[i][j]=a[j];
                                         }     
                                         }
              
              for(i=0;i<n;++i)
              {
                              mergesort(i,i,n-1);
                          //    printf("hi\n");
                              }
    /*          for(i=1;i<n;++i)
              {
                              for(j=i;j<n;++j)
                              printf("%d ",temp[i][j]);
                              printf("\n");
                              }*/
                              cnt=0;
                              clr(tmp);
                              clr(h1);
              for(i=0;i<n;++i)
              {
                              for(j=i+1;j<n;++j)
                              {
                                                tmp[cnt]=a[i]+a[j];
                                                h1[cnt++]=j;
                                                }
                                                }
            //  for(i=0;i<cnt;++i)
              //printf("%d ",tmp[i]);
              int ind1, ind2;
             // printf("\n");
          //    printf("%d\n",cnt);
              long long count1=0;
//              printf("hello\n");
int fl=0;
              for(i=0;i<cnt;++i)
              {                                
                                               if(h1[i]==n-1)
                                               continue;
                                               if(l-tmp[i]<=0)
                                               {fl=1;ind1=h1[i]+1;}
//                                               if(tmp[i]>l)
  //                                             l=tmp[i];  
                                                 if(fl!=1)                     
                                                 {                        
                                ind1=bs(l-tmp[i],h1[i],n-1);
                  //              printf("%d %d low\n",temp[h1[i]+1][ind1],l-tmp[i]);
                                    if(temp[h1[i]+1][ind1]<(l-tmp[i]))
                                     ind1=ind1+1;
                                     }
//                                     if(fl==1)
                                     fl=0;
                           //     printf("fkbgkd\n");
                           if(h<=tmp[i])
                           continue;
//                           if(h-tmp[i]
                                ind2=bs(h-tmp[i],h1[i],n-1);
                                if(temp[h1[i]+1][ind2]>(h-tmp[i]))
                                ind2--;
                //                                                printf("%d %d high\n",temp[h1[i]+1][ind2],h-tmp[i]);
//                                if(temp[i][ind2]<h)
  //                              if(
                             //                                   printf("fkbgkd\n");
              //               printf("%d %d\n",ind1,ind2);
                                count1+=ind2-ind1+1;
                                }    
              printf("%lld\n",count1);                
}
return 0;
}
