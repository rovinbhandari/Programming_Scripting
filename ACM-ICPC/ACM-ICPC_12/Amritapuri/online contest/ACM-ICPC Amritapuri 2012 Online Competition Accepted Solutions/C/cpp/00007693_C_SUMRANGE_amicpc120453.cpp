#include<stdio.h>
#include<stdlib.h>

int main()
{
     int cases;
     scanf("%d",&cases);
     int counts[cases],c=cases,i;
     while(cases>0)
     {
                   --cases;
                   int n,l,h,i;
                   scanf("%d",&n);
                   scanf("%d",&l);
                   scanf("%d",&h);
                   int a[n],j,temp,mark,k=0,flag,eflag=0,count=0;
                   for(i=0;i<n;i++)
                   {
                                   scanf("%d",&temp);
                                   mark=i;
                                   for(j=0;j<i;j++)
                                   {
                                                   if(temp<a[j])
                                                   {
                                                                mark=j;
                                                                break;
                                                                }
                                   }
                                   for(j=i;j>mark;j--)
                                                      a[j]=a[j-1];
                                   a[mark]=temp;
                                   }
                   for(i=0;i<n-2;i++)
                   {
                                     j=i+1;
                                     flag=0;
                                     k=j+1;
                                     if(a[i]+a[j]+a[k]>h)
                                          eflag=1;
                                     while((a[j]+a[i]+a[k]<=h)&&(j<n))
                                     {
                                                            if(a[i]+a[j]>=h)
                                                            {
                                                                            eflag=1;
                                                                            break;
                                                            }
                                                            while((a[i]+a[j]+a[k]<=h)&&(k<n))
                                                            {
                                                                                    if(a[i]+a[j]+a[k]>=l)
                                                                                                        ++count;
                                                                                    ++k;
                                                            }
                                                            ++j;
                                                            k=j+1;
                                     }
                                     if(eflag==1)
                                                 break;
                                     }
                       counts[c-cases-1]=count;
                   }
     for(i=0;i<c;i++)
                     printf("%d\n",counts[i]);
     }
                   
                                                                
                   
