#include<stdio.h>
#define MAX 100005
#define MAX4 1000005


#define MINIM 0
#define MAXIM 1
int countmax[MAX4]={0};

void initialize(int,int ,int ,int [],int [],int,int);
int query(int,int,int,int [],int [],int,int,int);


void initialize(int node,int l,int r,int count[MAX4],int a[MAX],int N,int mode)
{
    if(l==r)
    count[node]=l;
    else
    {
        initialize(2*node,l,(l+r)/2,count,a,N,mode);

        initialize(2*node+1,((l+r)/2)+1,r,count,a,N,mode);
        if(!mode)
        {
            if(a[count[2*node]]<=a[count[2*node+1]])
        count[node]=count[2*node];
        else
        count[node]=count[2*node+1];
        }
        else
        {
        if(a[count[2*node]]>=a[count[2*node+1]])
        count[node]=count[2*node];
        else
        count[node]=count[2*node+1];

        }
    }
}
int query(int node,int l,int r,int count[MAX4],int a[MAX],int i,int j,int mode)
{
    int p1,p2;
    if(i>r||j<l)
    return -1;
    if(i<=l&&j>=r)
    return count[node];

    p1=query(2*node,l,(l+r)/2,count,a,i,j,mode);

    p2=query(2*node+1,((l+r)/2)+1,r,count,a,i,j,mode);
    if(p1==-1)
    return p2;
    if(p2==-1)
    return p1;
    if(!mode)
    {
        if(a[p1]<=a[p2])
    return p1;
    else
    return p2;
    }
    else
    {
    if(a[p1]>=a[p2])
    return p1;
    else
    return p2;

    }

}

int main()
{
    char a[MAX];
        int one[MAX];
        int zero[MAX];
        int d[MAX];
    int t,count,i,n,c1,c0,q,f,l;
    scanf("%d",&t);
    while(t--)
    {

        c1=0;
        c0=0;
        count=0;
        scanf("%d",&n);
        scanf("%s",a);
        for(i=n-1;i>=0;i--)
        {
            if(a[i]=='1')
                c1++;
                one[i]=c1;

        }
        for(i=0;i<n;i++)
        {   countmax[i]=0;
            if(a[i]=='0')
                c0++;
                zero[i]=c0;
                d[i]=c0+one[i];
        }
      initialize(1,0,n-1,countmax,d,n,MAXIM);
       scanf("%d",&q);
       while(q--)
       {
           scanf("%d%d",&f,&l);
           f=f-1;
           l=l-1;
            int ma=query(1,0,n-1,countmax,d,f,l,MAXIM);
             int z=0,x=0;
             if(f!=0)
             z=zero[f-1];
             if(l!=n-1)
             x=one[l+1];
             ma=d[ma]-z-x;
               printf("%d\n",ma);

       }
    }
    return 0;
}
