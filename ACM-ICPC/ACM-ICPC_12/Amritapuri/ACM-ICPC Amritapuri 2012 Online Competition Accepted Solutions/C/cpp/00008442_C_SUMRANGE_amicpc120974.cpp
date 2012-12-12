#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
bool cmp(int a,int b)
{

    return a<b;
}

int floorsearch(int arr[], int low, int high, int x)
{

    if(low>high)
    return -1;
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
  if(arr[mid] == x)
    return mid;

  /* If x is greater than arr[mid], then either arr[mid + 1]
    is ceiling of x or ceiling lies in arr[mid+1...high] */
  else if(arr[mid] > x)
  {
    if(mid - 1 >= low && x >= arr[mid-1])
      return mid-1;

    else
      return floorsearch(arr, low, mid-1, x);
  }

  /* If x is smaller than arr[mid], then either arr[mid]
     is ceiling of x or ceiling lies in arr[mid-1...high] */
  else
  {
    if(mid + 1 <= high && x < arr[mid+1])
      return mid;
    else
      return floorsearch(arr, mid,high, x);
  }
}

int ceilSearch(int arr[], int low, int high, int x)
{
    if(low>high)
    return -1;
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
  if(arr[mid] == x)
    return mid;

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


int main()
{
    int t,i,j,a[1010],l,h,n,p,q,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&l,&h);
        for(i=0;i<n;i++)
        scanf("%d",a+i);

        sort(a,a+n,cmp);
        ans=0;
        for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
//printf("%d %d\n",i,j);
            p=ceilSearch(a,j+1,n-1,l-(a[i]+a[j]));
            q=floorsearch(a,j+1,n-1,h-(a[i]+a[j]));
            if(p!=-1 && q!=-1)
            ans+=(q-p+1);
            //printf("%d %d\n",p,q);
        }
        printf("%d\n",ans);
    }

    return 0;
}
