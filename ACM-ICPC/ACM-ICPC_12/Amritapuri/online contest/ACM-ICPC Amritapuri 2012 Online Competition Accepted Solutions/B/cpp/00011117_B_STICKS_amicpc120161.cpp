#include<iostream>
#include<cstdlib>
#include <cstdio>
#include<cmath>
using namespace std;
int *TMP;
int bin_sea(int a[], int n, int find);
void merge(int a[], int st1, int st2, int end);
void split(int a[], int start, int end)
{
	 int mid=(start+end)/2;
	 if(start<end){
		   split(a, start,mid);
		   split(a, mid+1,end);
		   merge(a,start,mid+1,end);
		   }
		   }
void merge(int a[], int st1, int st2, int end)
{

   int len=end-st1+1;
   TMP=new int[len];
   int tmp_cnt=0,i=st1,j=st2;

	 while((i<=(st2-1))&&(j<=end))
	 {

		if(a[i]>a[j])
			 TMP[tmp_cnt++]=a[j++];
		 else
			  TMP[tmp_cnt++]=a[i++];

			  }

			  while(i<=st2-1)
			  TMP[tmp_cnt++]=a[i++];
			  while(j<=end)
			  TMP[tmp_cnt++]=a[j++];
			  j=st1;
				 // cout<<TMP[2];
		  for(int i=0; i<len; i++,j++)
		  a[j]=TMP[i];
		  delete TMP;

	 }

int bin_sea(int a[], int n, int &from, int find){
 //	int start=0, mid, end=n-1;
/*	if(a[end]<find) {
		printf("return: %d \n", mid+1);
        return end+1;
    }
	while (start <= end) {
		mid = start + (end-start)/2;
		if (a[mid] == find) {
			break;
		} else if(a[mid] >find) {
			end = mid-1;
		} else {
			start = mid+1;
		}
	}
//	printf("mid: %d\n", mid);
   	if(a[mid] == find) {
   	//	printf("return: %d \n", mid+1);
        return mid+1;
    }
    else if(start != mid) {
        return mid+1;
     ///   printf("return: %d \n", mid+1);
    } else {
        return mid;
        //printf("return: %d \n", mid);
    }
    */
    int cnt=0;
    for(; from<n; from++)
    {
        if(a[from]<=find)
        cnt++;
        else
        break;
        }
        return cnt;
}

int sticks[50000];
long long int sqr;
int main()
{
	int t,start;
	int n,m;
	long long int t1,t2,t3;
	long long int sum;
	scanf("%d", &t);
	while(t--)
	{
		 scanf("%d %d", &n, &m);
		 start=0;
		 for(int i=0; i<n; i++)
		 scanf("%d", &sticks[i]);
		 split(sticks,0,n-1);
		 sum=0;
	//	 for(int i=0; i<n; i++)
	//	 cout<<sticks[i]<<" ";
		 for(int i=0; i<m; i++)
		 {
			  scanf("%lld %lld %lld",&t1,&t2,&t3);
			  sqr=sqrt( t1*t1 + t2*t2 + t3*t3);
			//  cout<<"search:"<<sqr<<endl;
		  //    cout<<"yea\n";
                if(start==n)
                break;
			  sum+=bin_sea(sticks, n, start, sqr);
		//	  cout<<sum<<"\n";
			  }
			  printf("%lld\n",sum);
			  }
			  return 0;
			  }

