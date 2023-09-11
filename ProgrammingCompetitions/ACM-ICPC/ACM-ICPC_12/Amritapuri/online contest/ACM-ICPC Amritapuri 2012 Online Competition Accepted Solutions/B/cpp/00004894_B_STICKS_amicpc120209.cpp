#include <stdio.h>
#include <math.h>
int main(){
    int t;
    scanf("%d",&t);
    int i,j,a,b,ctr,k;
    int st[50000],bol[50000],bob[50000],boh[50000];
    double max,ctr2;;
    for (i=0;i<t;i++)
    {
        ctr=0;
        max=0;
        scanf("%d %d",&a,&b);   
        for(j=0;j<a;j++)
        {
            scanf("%d",&st[j]);                
        } 
        for(j=0;j<b;j++)
        {
            scanf("%d %d %d",&bol[j],&bob[j],&boh[j]);
            ctr2=sqrt(pow(bol[j],2)+pow(bob[j],2)+pow(boh[j],2)); 
            if (max<ctr2)
               max=ctr2;
        }
        for(j=0;j<a;j++)
        {
               if(st[j]<=max)
               {
                  ctr++;        
               }                
        }

        printf("%d\n",ctr);
    }
    return 0;   
}
