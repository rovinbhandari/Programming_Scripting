/* 
 * File:   main.c
 * Author: tknandu
 *
 * Created on 4 November, 2012, 11:04 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

void merge(long long int *array,long int left,long int mid,long int right)
{
    long long int tempArray[right-left+1];
    long int pos=0,lpos=left,rpos=mid+1;
    while(lpos<=mid && rpos<=right)
    {
        if(array[lpos] < array[rpos])
            tempArray[pos++]=array[lpos++];
        else
            tempArray[pos++]=array[rpos++]; 
    }
    while(lpos<=mid)
        tempArray[pos++]=array[lpos++];
    while(rpos<=right)
        tempArray[pos++]=array[rpos++];
    
    long int counter;
    for(counter=0;counter<pos;counter++)
        array[left+counter]=tempArray[counter];
}

void mergesort(long long int *array,long int left,long int right)
{
    long int mid=(left+right)/2;
    if(left<right)
    {
        mergesort(array,left,mid);
        mergesort(array,mid+1,right);
        merge(array,left,mid,right);
    }
}


int main(int argc, char** argv) {

    long int t,n,l,h,s2;
    long int i,j,k;
    long int x,y,no;
    
scanf("%ld",&t);

while(t>0)
{
    no=0;
    
    scanf("%ld %ld %ld",&n,&l,&h);
    
    long long int a[n];
    
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    
    mergesort(a,0,n-1);
    
    
    for(i=0;i<n-2;i++)
    {
        if( 3*a[i]<=h)
        {
        for(j=i+1;j<n-1;j++)
        {
            s2=a[i]+a[j];
            x=l-s2;
            y=h-s2;
            if( s2+a[j]<=h)
            {
            for(k=j+1;k<n;k++)
            {
                if(x<=a[k]&&y>=a[k])
                {
                    no++;
                }
            }
            }
            else 
                break;
        }
        }
        else
            break;
    }
    
    printf("%ld\n",no);
    

    t--;
}

    return (EXIT_SUCCESS);
}

