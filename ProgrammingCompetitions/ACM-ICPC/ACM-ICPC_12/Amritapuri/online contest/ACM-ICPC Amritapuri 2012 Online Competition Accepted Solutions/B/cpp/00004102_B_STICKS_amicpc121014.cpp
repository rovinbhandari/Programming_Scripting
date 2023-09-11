#include<cstdio>
#include<cmath>

using namespace std;

int main()
{   
    int t,i,f;
    long m,n,c;
    double mx;
    scanf ("%d",&t);
    while(t--)
    {
             scanf("%ld",&n);
             scanf("%ld",&m);  
             c=0,f=0;
             long a[n],l[m],b[m],h[m];
             double diag[m];  
             for (i=0;i<n;++i)
                scanf("%ld",&a[i]);
             scanf("%ld",&l[0]);
             scanf("%ld",&b[0]);
             scanf("%ld",&h[0]);
             diag[0]=sqrt(l[0]*l[0]+b[0]*b[0]+h[0]*h[0]);
             mx=diag[0];
             for (i=1;i<m;++i)
             {
                 scanf("%ld",&l[i]);
                 scanf("%ld",&b[i]);
                 scanf("%ld",&h[i]);
                 diag[i]=sqrt(l[i]*l[i]+b[i]*b[i]+h[i]*h[i]);
                 if (diag[i]>mx)
                    mx=diag[i];
             }
             for (i=0;i<n;++i)
             {
                 if (a[i]<mx)
                    c++;
                 else if (a[i]==mx && f==0)
                 {
                      c++;
                      f=1;     
                 }            
             }
             printf("%ld\n",c);
             getchar();  
             
                  
    }  
    return 0;
}
