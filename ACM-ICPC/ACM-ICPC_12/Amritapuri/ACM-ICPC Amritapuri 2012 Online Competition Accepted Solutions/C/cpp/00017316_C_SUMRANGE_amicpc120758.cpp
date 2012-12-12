#include <iostream> 
#include <algorithm> 
#include <vector> 
#include <cstdio> 
#include <string> 
#include <bitset> 
#include <cmath> 
#include <list> 
#include <cstdlib> 
#include <map> 
#include <cstring> 
#include <set> 
#include <stack> 
#include <sstream> 
#include <queue> 
#include <deque> 
#include <ctime> 

using namespace std; 

#define debug(x) cout<<#x<<" = "<<x<<"\n" 
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++) 
#define PI 3.1415926535897932385 
#define INF (1<<29) 
#define EPS (1e-7) 
#define pb push_back 
#define sz size() 
#define ln length() 
#define mp make_pair 
#define all(a) a.begin(),a.end() 
#define fill(ar,val) memset(ar,val,sizeof ar) 
#define sqr(x) ((x)*(x)) 
#define min(a,b) ((a)<(b)?(a):(b)) 
#define max(a,b) ((a)>(b)?(a):(b)) 
#define FORE(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++) 

int ceilSearch(int arr[], int low, int high, int x)
{
  int mid;    
 
  /* If x is smaller than or equal to the first element,
    then return the first element */
  if(x <= arr[low])
    return low; 
 
  /* If x is greater than the last element, then return -1 */
  if(x > arr[high])
    return -1;  
 
  /* get the index of middle element of arr[low..high]*/
  mid = (low + high)/2;  /* low + (high - low)/2 */
 
  /* If x is same as middle element, then return mid */
  if(arr[mid] == x) {
              while ( arr[mid-1] == x && mid >= low ) mid--;
    return mid;
  }
     
  /* If x is greater than arr[mid], then either arr[mid + 1]
    is ceiling of x or ceiling lies in arr[mid+1...high] */ 
  else if(arr[mid] < x)
  {
    if(mid + 1 <= high && x <= arr[mid+1])
      return mid + 1;
    else
      return ceilSearch(arr, mid+1, high, x);
  }
 
  /* If x is smaller than arr[mid], then either arr[mid] 
     is ceiling of x or ceiling lies in arr[mid-1...high] */   
  else
  {
    if(mid - 1 >= low && x > arr[mid-1])
      return mid;
    else    
      return ceilSearch(arr, low, mid - 1, x);
  }
}
int FloorSearch(int arr[], int low, int high, int x)
{
  int mid;    
 
  /* If x is smaller than or equal to the first element,
    then return the first element */
  if(x >= arr[high])
    return high; 
 
  /* If x is greater than the last element, then return -1 */
  if(x < arr[low])
    return -1;  
 
  /* get the index of middle element of arr[low..high]*/
  mid = (low + high)/2;  /* low + (high - low)/2 */
 
  /* If x is same as middle element, then return mid */
  if(arr[mid] == x) {
              while ( arr[mid+1] == x ) mid++;
    return mid;
    }
     
  /* If x is greater than arr[mid], then either arr[mid + 1]
    is ceiling of x or ceiling lies in arr[mid+1...high] */ 
  else if(arr[mid] < x)
  {
       if(mid + 1 <= high && x < arr[mid+1])
      return mid;
    else    
      return FloorSearch(arr, mid+1, high, x);
       
       
  }
  
  /* If x is smaller than arr[mid], then either arr[mid] 
     is ceiling of x or ceiling lies in arr[mid-1...high] */   
  else
  {
      if(mid - 1 >= low && x >= arr[mid-1])
      return mid - 1;
    else
      return FloorSearch(arr, low, mid-1, x);
      
    
  }
}


int main()
{
     int n,t,L,H;
     scanf("%d",&t);
     int A[1024];
     while ( t-- ) {
          scanf("%d %d %d",&n,&L,&H);
          
          REP( i,n ) {
               scanf("%d",&A[i]);
          }
          
         // REP(i,n) { cout << A[i] << "   ";}
         // cout << endl;
          sort( A,A+n);
          
          int ans = 0;
          
          for ( int i = 0; i < n-2; i++ ) {
              for ( int j = i+1; j < n-1; j++ ) {
                  int sum_now = A[i] + A[j];
                  //debug(A[i]);
                  //debug(A[j]);
                  //debug(sum_now);
                  int sml = L - sum_now;
                  int gt = H - sum_now; 
                  int index2 = ceilSearch(A,j+1,n-1,sml);
                  int index1 = FloorSearch( A, j+1,n-1,gt);
                  
                  //cout << "Ceil of " << sml << " is :  " <<index2<< endl;
                  //cout << "Floor of " << gt << " is :  " <<index1<< endl;
                  //index2 = ( index2 == -1 ) ? n-1:index2;
                  //index1 = ( index1 == -1 ) ? j+1:index1;
                  
                  //debug(index1);
                  //debug(index2);
                  if ( index1 != -1 && index2 != -1 )
                  ans += index1 - index2 +1;
                  //debug(ans);
              }
          }
          cout << ans << endl;
          //debug(ans);
     }
     return 0;
}
