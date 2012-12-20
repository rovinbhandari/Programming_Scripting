#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
vector<int> arr;
int lowbinarySearch( int low, int high, int L)
{
  if(high >= low)
  {
    int mid = (low + high)/2;

    if(arr[mid]>=L && (mid==low || arr[mid-1]<L) )
      return mid;
    else if(arr[mid]<L)
      return lowbinarySearch( (mid + 1), high, L);
    else if(arr[mid-1]>=L)
      return lowbinarySearch( low, (mid -1), L);
  }
  return -1;
}

int highbinarySearch( int low, int high, int H)
{
  if(high >= low)
  {
    int mid = (low + high)/2;

    if(arr[mid]<=H && (mid==high || arr[mid+1]>H) )
      return mid;
    else if(arr[mid]>H)
      return highbinarySearch(low, (mid-1), H);
    else if(arr[mid+1]<=H)
      return highbinarySearch((mid+1), high, H);
  }
  return -1;
}


int main() {
	int T,i,j,L,H,N,sum,count,low,high,lo,hi,k;
	scanf("%d",&T);
	for(i=0; i<T; i++) {
		scanf("%d%d%d",&N,&L,&H);
		arr = vector<int> (N,0);
		count=0;
		for(j=0; j<N; j++) {
			scanf("%d", &arr[j]);
		}
		sort(arr.begin(), arr.end());
		for(j=1; j<N-1; j++) {
			if(j<N/2) {
				for(k=0; k<j; k++) {
					sum=arr[j]+arr[k];
					low=lowbinarySearch(j+1, N-1,(L-sum));
					high=highbinarySearch(j+1, N-1, (H-sum));
					if(low!=-1 && high!=-1) {
						count+=(high-low+1);
					}
				}
			}
			else {
				for(k=j+1; k<N; k++) {
					sum=arr[j]+arr[k];
					low=lowbinarySearch( 0, (j-1), (L-sum));
					high=highbinarySearch( 0, (j-1), (H-sum));
					if(low!=-1 && high!=-1) {
						count+=(high-low+1);
					}
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
