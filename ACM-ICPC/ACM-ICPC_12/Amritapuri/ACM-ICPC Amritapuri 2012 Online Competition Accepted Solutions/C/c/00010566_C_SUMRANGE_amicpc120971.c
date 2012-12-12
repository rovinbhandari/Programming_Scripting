#include<stdio.h>
long int arr[1000];

int partition(int p, int r)
{
    int x=arr[r],i,j=p-1,temp; // j=p-1 imp
    for(i=p;i<r;i++)
    {
                    if(arr[i]<x)
                    {
                      j++;
                      temp=arr[i];
                      arr[i]=arr[j];
                      arr[j]=temp;
                    }
    }
    temp=arr[j+1];
    arr[j+1]=arr[r];
    arr[r]=temp;
    return j+1;
}
void QuickSort(int p, int r)
{
     int q;
     if(p<r)
     {
            q=partition(p,r);
            QuickSort(p,q-1);
            QuickSort(q+1,r);//q-1 q+1 imp
     }
}

int main()
{
      int number,i,j,k,val,test,count=0,result[100],a,p,r,flag=0;
      long int l,h;
      scanf("%d",&test);
      for(a=0;a<test;a++)
      {
      count=0;
      scanf("%d",&number);
      scanf("%ld",&l);
      scanf("%ld",&h);
      for(i=0;i<number;i++)
                           scanf("%ld",&arr[i]);
      //sort
      p=0;
      r=number-1;
      QuickSort(p,r);
      for(i=0;i<number-2;i++){
                            if(arr[i]+arr[i+1]+arr[i+2]>h)
                                                          break;
            for(j=i+1;j<number-1;j++){
                                      if(arr[i]+arr[j]+arr[j+1]>h)
                                                           break;
                  for(k=j+1;k<number;k++)
                  {
                                       val=arr[i]+arr[j]+arr[k];
                                       if(val>=l && val<=h)
                                       {
                                                 count++;
                                                 }
                                       if(val>h)
                                       {
                                                 break;
                                       }
                                                
                                                 }
                             }
                             }
      result[a]=count;
      }
     for(a=0;a<test;a++)
                         printf("%d\n",result[a]);
     return 0;
}                        
      
