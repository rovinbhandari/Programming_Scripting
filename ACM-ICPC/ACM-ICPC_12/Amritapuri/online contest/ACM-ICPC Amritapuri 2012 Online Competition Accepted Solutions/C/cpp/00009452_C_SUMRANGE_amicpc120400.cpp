#include<stdio.h>
#include<algorithm>
using namespace std;

int scan(){
    int t=0;
    char c;
    c=getchar_unlocked();
    while(c<'0' || c>'9')
        c=getchar_unlocked();
    while(c>='0' && c<='9'){
        t=(t<<3)+(t<<1)+(c-'0');
        c=getchar_unlocked();
    }
    return(t);
}

int main()
{
    int i,j,k,n,t,l,h,a[1000],count,p,q,w;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        //scanf("%d %d %d",&n,&l,&h);
        n=scan();
        l=scan();
        h=scan();
        for(i=0;i<n;i++)
            a[i]=scan();

		sort(a,a+n);
		w=n;
		p=n;
		q=n;
        for(i=0;i<q-2;i++)
        {
          if(a[i]>=h)
            {
            	    break;
            
            }
            for(j=i+1;j<w-1;j++)
            {
                if(a[j]>=h || a[i]+a[j]>=h)
                {
                   break;
				}
                 
                for(k=j+1;k<p;k++)
                {
                    if((a[i]+a[j]+a[k])>=l && (a[i]+a[j]+a[k])<=h)
                        count++;
                    if((a[i]+a[j]+a[k])>h)
                    	{
                    	break;}
                    
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
