#include<iostream>
#include<cstdio>
using namespace std;


char arr[100005];
int t1[300005];
int qt0[300005];
int qt1[300005];
int t0[300005];
int val[300005];

int maximum(int a,int b,int c,int d,int e)
{
    if(a>=b)
    {
        if(a>=c) 
        {
            if(a>=d)
            {
                if(a>=e)
                {
                    return a;        
                }        
                else
                {
                    return e;    
                }
            }         
            else if(d>=e)
            {
                return d;     
            }
            else
            {
                return e;    
            }
        }
        else if(c>=d)
        {
            if(c>=e)
            {
                 return c;        
            }     
            else
            {
                return e;    
            }
        }
        else if(d>=e)
        {
            return d;     
        }       
        else
        {
            return e;    
        }
    }   
    else if(b>=c)
    {
        if(b>=d)
        {
            if(b>=e)
            {
                return b;        
            }    
            else
            {
                return e;    
            }
        }
        else if(d>=e)
        {
            return d;     
        }
        else
        {
            return e;    
        }
    }
    else if(c>=d)
    {
        if(c>=e)
        {
            return c;        
        }     
        else
        {
            return e;    
        }
    }
    else if(d>=e)
    {
        return d;     
    }
    else
    {
        return e;    
    }
}

void build(int node,int s,int e)
{
    if(s==e)
    {
        if(arr[s]=='0')
        {
            t0[node]=1;    
            t1[node]=0;
        }         
        else if(arr[s]=='1')
        {
            t0[node]=0;    
            t1[node]=1;    
        }
        val[node]=1; 
    }     
    
    else
    {
        build(node*2,s,(s+e)/2);
        build(1+node*2,((s+e)/2)+1,e);
        t0[node]=t0[node*2]+t0[1+node*2];
        t1[node]=t1[node*2]+t1[1+node*2];
        val[node]=maximum(t0[node*2]+t1[1+node*2],t0[node*2]+val[1+node*2],t0[node*2]+t0[1+node*2],val[node*2]+t1[1+node*2],t1[node*2]+t1[1+node*2]);
    }
    
    return;
}

int query(int node,int s,int e,int x,int y)
{
    int val1,val2;
    if((x<s && y<s) || (x>e && y>e))
    {
        qt0[node]=0;
        qt1[node]=0;    
        return 0;        
    }    
    else if(x<=s && y>=e)
    {
        qt0[node]=t0[node];
        qt1[node]=t1[node];
        return val[node];
    }
    else
    {
        val1=query(node*2,s,(s+e)/2,x,y);
        val2=query(1+node*2,((s+e)/2)+1,e,x,y);
        if(val1!=0 && val2!=0)
        {
            qt0[node]=qt0[node*2]+qt0[1+node*2];
            qt1[node]=qt1[node*2]+qt1[1+node*2];
            return maximum(qt0[node*2]+qt1[1+node*2],qt0[node*2]+val2,qt0[node*2]+qt0[1+node*2],val1+qt1[1+node*2],qt1[node*2]+qt1[1+node*2]);
        }
        else
        {
            qt0[node]=qt0[node*2]+qt0[1+node*2];
            qt1[node]=qt1[node*2]+qt1[1+node*2];
            return val1+val2;
        }
    }
}

int main()
{
    int t,i,j,q,mi,n,x,y;
    
    scanf("%d",&t);
    while(t--)
    {   
        scanf("%d",&n);
        getchar();
        for(i=0;i<n;i++)
        {
            scanf("%c",&arr[i]);                
        }
        scanf("%d",&q); 
         
        build(1,0,n-1);
        
        for(i=0;i<q;i++)
        {
            scanf("%d %d",&x,&y);
            mi=query(1,0,n-1,x-1,y-1);
            printf("%d\n",mi);                
        }
        
    }
    return 0;
    //system("pause");
}

