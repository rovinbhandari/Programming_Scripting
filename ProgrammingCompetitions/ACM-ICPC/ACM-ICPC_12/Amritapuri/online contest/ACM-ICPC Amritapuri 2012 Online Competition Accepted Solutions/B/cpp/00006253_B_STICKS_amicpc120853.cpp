#include<stdio.h>

void quickSort(long long int arr[],long long int left, long long int right);

int main()
{
    int t;
    long long int n,m,l[50000],a[50000],b[50000],c[50000],i,diag[50000],j,max;
    
    scanf("%d",&t);
    
    while(t--)
    {
              scanf("%lld%lld",&n,&m);
         
              for(i=0;i<n;i++)
               {
                 scanf("%lld",&l[i]);
                 l[i]*=l[i];
               }
               quickSort(l,0,n-1);
               max=0;
              for(i=0;i<m;i++)
               {
                scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
                diag[i]= a[i]*a[i] + b[i]*b[i] + c[i]*c[i];
                if(diag[i]>diag[max])
                 max=i;
                }
               
              
              while(1)
              {
                      if(n==0)
                      {printf("0\n");break;}
                      if(l[n-1]<=diag[max])
                      {
                         printf("%lld\n",n);break;
                         }
                       else
                         n--;
                         
             }    
                      
                       
              
     }

              
              return 0;
              }                 
                               
               
void quickSort(long long int arr[],long long int left, long long int right)
 {
      long long int i = left, j = right;
      long long int tmp;
      long long int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}
