#include <cstdio>
#include <cstdlib>

long inp[1000];
long sort_inp[1000];
int len;
using namespace std;


void merge(int,int,int);


void merge_sort(int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merge(low,mid,high);
    }
}


void merge(int low,int mid,int high)
{
    int h,i,j,k;
    long b[1000];
    h=low;
    i=low;
    j=mid+1;

    while((h<=mid)&&(j<=high))
    {
        if(sort_inp[h]<=sort_inp[j]){
            b[i]=sort_inp[h];
            h++;
        }
        else{
            b[i]=sort_inp[j];
            j++;
        }
        i++;
    }
    if(h>mid){
        for(k=j;k<=high;k++){
            b[i]=sort_inp[k];
            i++;
        }
    }
    else{
        for(k=h;k<=mid;k++){
            b[i]=sort_inp[k];
            i++;
        }
    }
    for(k=low;k<=high;k++){
        sort_inp[k]=b[k];
    } 
}


int main()
{
    int casen,i,n,k,j;
    long l,h,in,count,sum;
    int up_lim3;
    scanf("%d\n", &casen);
    while(casen){
        scanf("%d %ld %ld\n",&n,&l,&h);
        len=0;
        for(i=0;i<n;++i){
            scanf("%ld",&in);
            if(in < h){
                inp[len] = in;
                sort_inp[len] = in;
                len++;
            }
        }
        if(len == 0){
            printf("0\n");
        }
        else{
            count = 0;
            merge_sort(0,len-1);
            /*for(i=0;i<len;i++){
                printf("%ld ",sort_inp[i]);
            }
            printf("\n");
            for(i=0;i<len;i++){
                printf("%ld ",inp[i]);
            }
            printf("\n");
            for(i=0;i<len;i++){
                printf("%d ",track_index[i]);
            }
            printf("\n");*/
            for(i=0;i<len;++i){
                for(j=i+1;j<len;j++){
                    up_lim3 = len;
                    for(k=j+1;k<up_lim3;k++){
                        sum = sort_inp[i] + sort_inp[j] + sort_inp[k];
                        if(sum>=l && sum<=h){
                            count++;
                        }
                        else if(sum>h){
                            up_lim3 = k;
                            break;
                        }
                    }
                }
            }
            printf("%ld\n",count);
        }
        casen--;
    }
    return 0;
}
