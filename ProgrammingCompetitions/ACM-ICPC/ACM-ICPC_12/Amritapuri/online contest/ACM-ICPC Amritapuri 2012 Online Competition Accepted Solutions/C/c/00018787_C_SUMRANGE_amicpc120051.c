#include<stdio.h>
struct l{
		long int data;
		long int p;
		}a[1000];
void ins(struct l *f,int n)
{ 
   long int i,j,key,key1;
    for(i=1;i<=(n-1);i++)
    {
        key1=f[i].p;
        key=(f[i].data);
        j=i-1;
        while(1)
        {
            if(j>=0)
            {
                if((f[j].data)>key)
                {
                    f[j+1].p=f[j].p;
		f[j+1].data=f[j].data;
                    j=j-1;
                }
                else
                    break;
            }
           else
                break;
        }   
        f[j+1].p=key1;
	f[j+1].data=key;          
    }
}
void ins1(struct l a[],int N)
	{
	long int t;
	long int i,j,last=N-1,f;
	for(i=0;i<N-1;i++)
		{
			f=0;
		for(j=0;j<last;j++)
				{
				if(a[j].data>a[j+1].data)
					{
					t=a[j].data;
					a[j].data=a[j+1].data;
					a[j+1].data=t;
					t=a[j].p;
					a[j].p=a[j+1].p;
					a[j+1].p=t;
					f=1;
					}
				}
			if(f==0)
			break;
		}
	}
int main()
{
long int i,j,k,T,N,L,H,s;
long int count=0,hg;
scanf("%ld",&T);
//printf("%ld\n",T);
	for(;T>0;T--)
		{
		hg=0;
		fflush(stdin);
		scanf("%ld %ld %ld",&N,&L,&H);
	//	printf("%ld %ld %ld\n",N,L,H);
			for(i=0;i<N;i++)
				{
				scanf("%ld",&(a[i].data));
				//printf("%ld",a[i].data);
				a[i].p=i;
				}
			
		ins(a,N);
		//for(i=0;i<N;i++)
		//		{
				//printf("%ld %ld\n",(a[i].data),a[i].p);
				//printf("%ld",a[i].data);
				//a[i].p=i;
		//		}
		hg=a[N-1].data;
		count=0;
		for(i=0;i<N-2;i++)
			{
			if(a[i].data>=H)
			break;
			for(j=i+1;j<N-1;j++)
				{
				if(i==j)
					continue;
				if(a[i].data+a[j].data>=H)
				break;
//				if((a[i].data+a[j].data+hg)<L)
//				break;
				for(k=j+1;k<N;k++)
					{
					if(k==j || k==i)
						continue;
					if((a[i].data+a[j].data+a[k].data)>H)// || (a[i].data+a[j].data+a[k].data)<L)
						{
							break;
						}
//					if((a[i].p<a[j].p && a[j].p<a[k].p))//||(a[j].p<a[k].p && a[k].p<a[i].p)||(a[k].p<a[i].p && a[i].p<a[j].p))
						{
						s=(a[i].data+a[j].data+a[k].data);
						if(s<=H && s>=L)
							count++;
						}
					}
				}
			}
			printf("%ld\n",count);
		}
		return 0;
}
