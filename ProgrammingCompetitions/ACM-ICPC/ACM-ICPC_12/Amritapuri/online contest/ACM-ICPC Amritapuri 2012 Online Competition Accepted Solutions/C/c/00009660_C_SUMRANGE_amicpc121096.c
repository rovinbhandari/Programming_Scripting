#include<stdio.h>
void merge(int left,int mid,int right,int* a)
{
    
    int n = right-left+1;
    int temp[n];
    int i,j=mid+1,k=0;
    i = left;
    while(i<=mid && j<=right)
    {
        if( a[i] < a[j] )
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
        
    }
    while(i<=mid)
        temp[k++] = a[i++];
    while(j<=right)
        temp[k++] = a[j++];
     k = 0;
    for (i = left; i <= right; i++)
       a[i]=  temp[k++];
    
}

void mergesort(int* a,int left,int right)
{
    if(left<right)
    {
    int mid = (left+right)/2;
    mergesort(a,left,mid);
    mergesort(a,mid+1,right);
    merge(left,mid,right,a);
    }
}

int main(){
    int T, N, L, H, i,j,k, count, size;
    int A[1500], z[1500];
    scanf("%d",&T);
    while(T-->0){
        scanf("%d %d %d",&N,&L,&H);
        for(i=0;i<N;i++){
            scanf("%d",&A[i]);
        }
        mergesort(A,0,N-1);
        count=0;
        for(i=0;i<N;i++){
            size=0;
            if(A[i]>=H) break;
            
            for(j=i+1;j<N;j++){
                if(A[j]+A[i]>=H)  break;
                
                for(k=j+1;k<N;k++){
                        if(A[k]+A[j]+A[i]>=L)
                            break;                        
                    }
                    for(;k<N;k++){
                        if(A[k]+A[j]+A[i]>H)
                            break;
                        size++;
                    }
                   
                
            }
            count = count + size;
           
        }
        printf("%d\n",count);
    }
    return 0;
}