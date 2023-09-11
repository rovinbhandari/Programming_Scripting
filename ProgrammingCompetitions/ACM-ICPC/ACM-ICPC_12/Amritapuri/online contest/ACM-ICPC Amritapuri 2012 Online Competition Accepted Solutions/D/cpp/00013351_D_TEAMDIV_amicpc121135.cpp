/*
 * Author : Karthik Abinav
 */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>
#include <climits>
#include <cassert>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

/*All global definitions */
#define INF 1000000000
#define MAX 500
#define mod 1000000007

#define for_inc(start,end,increment)for(i=start;i<end;i+=increment)
#define for_dec(start,end,decrement)for(i=start;i>end;i-=decrement)

#define inp_d(n)scanf("%d",&n)
#define inp_ld(n)scanf("%ld",&n)
#define inp_lld(n)scanf("%lld",&n)
#define inp_s(n)scanf("%s",n)
#define inp_c(n)scanf("%c",&n)

#define out_d(n)printf("%d",n)
#define out_ld(n)printf("%ld",n)
#define out_lld(n)printf("%lld",n)
#define out_s(n)printf("%s",n)
#define out_c(n)printf("%c",n)
#define out_nl()printf("\n");

#define v_size(A) ((int)(A.size()))
#define set(A,x) memset(A,x,sizeof(A));  
#define pb push_back
#define mp make_pair

#define ll long long
#define ld long

using namespace std;

/*Structure for composite sorting*/
struct struct_name
{
    long int mem1;
    long int mem2;
    
    bool operator()(const struct_name &p1,const struct_name &p2)
    {
        return p1.mem1<p2.mem2;
    
    }

}struct_variable;


/* Fast IO */
class FastInput {
public:
    FastInput() {
        m_dataOffset = 0;
        m_dataSize = 0;
        m_v = 0x80000000;
    }
	
    uint32_t ReadNext() {
        if (m_dataOffset == m_dataSize) {
            int r = read(0, m_buffer, sizeof(m_buffer));
            if (r <= 0) return m_v;
            m_dataOffset = 0;
            m_dataSize = 0;
            int i = 0;
            if (m_buffer[0] < '0') {
                if (m_v != 0x80000000) {
                    m_data[m_dataSize++] = m_v;
                    m_v = 0x80000000;
                }
                for (; (i < r) && (m_buffer[i] < '0'); ++i);
            }
            for (; i < r;) {
                if (m_buffer[i] >= '0') {
                    m_v = m_v * 10 + m_buffer[i] - 48;
                    ++i;
                } else {
                    m_data[m_dataSize++] = m_v;
                    m_v = 0x80000000;
                    for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
                }
            }
        }
        return m_data[m_dataOffset++];
    }
	
public:
    uint8_t m_buffer[32768];
    uint32_t m_data[16384];
    size_t m_dataOffset, m_dataSize;
    uint32_t m_v;
};
 


/* End of fast IO*/


/* Calculate nCr */
long long int f[MAX], finv[MAX];

long long int p(long long int x, long long int y){
  int r;
  if(y==0)
    return 1;
  if(y%2)
    return (((long long unsigned)x*p(x, y-1))%mod);
  r=p(x, y/2);
  return (((long long unsigned)r*r)%mod);
}
 
/* Call precalculate once in main before using the nCr function 
 * set MAX in the macro definition to define upper limit of n 
 */
void precalculate() {
  int i;
  f[0]=1;
  for(i=1; i<MAX; i++)
    f[i]=(((long long unsigned)i*f[i-1])%mod);
  i--;
  finv[i]=p(f[i],mod-2);
  for(i--; i>=0; i--)
    finv[i]=(((long long unsigned)(i+1)*finv[i+1])%mod);
}
 
long long int ncr(long int n, long int r){
  if(n<r)
    return 0;
  return ((((f[n]*finv[r])%mod)*finv[n-r])%mod);
}


vector<int> graph[20005];
bool visited[20005];
int colors[20005];

ll pow(int comp)
{
    if(comp == 0)
        return 1;
    else if(comp == 1)
        return 2;
    else if(comp%2 == 0)
    {
        ll r = pow(comp/2);
        return (r*r)%mod;


    }
    else
    {
        ll r =pow(comp/2);
        return ((r*r)%mod*2)%mod;


    }



}



struct node
{
    int v;
    int col;    

};

void reset()
{
    int i;
    for(i=0;i<=20000;i++)
    {
        graph[i].clear();
        visited[i] = false;
        colors[i] = 0;
    }



}

int main()
{
    
    int t;
    inp_d(t);

    while(t--)
    {
        int n;
        inp_d(n);
        
        reset();
        int i,j;
        for(i=0;i<n;i++)
        {
            int k;
            inp_d(k);
            while(k--)
            {
                int riv;
                inp_d(riv);
                graph[i].push_back(riv);
                graph[riv].push_back(i);

            }

        }
       // cout<<"hi";
        
        int lv=0;
        int comp = 0;
        bool brk = false;
        while(lv<n)
        {
            queue<node> bfs;
            node temp;
            temp.v =lv;
            //cout<<lv<<endl;
            temp.col = 1;
            visited[lv] = true;
            colors[lv] = 1;
            bfs.push(temp);
            while(!bfs.empty() && !brk)
            {
                node top = bfs.front();
                bfs.pop();
                //cout<<top.v<<endl;
                int rr;
                for(rr=0;rr<graph[top.v].size();rr++)
                {
                    if(!visited[graph[top.v][rr]])
                    {
                        visited[graph[top.v][rr]] = true;
                        
                        node tt;
                        tt.v = graph[top.v][rr];
                        if(top.col == 1)
                            tt.col = 2;
                        else
                            tt.col = 1;
                        
                        bfs.push(tt);
                        colors[tt.v] = tt.col;
                    }
                    else
                    {
                        //cout<<colors[top.v]<<" "<<colors[graph[top.v][rr]]<<endl;
                        if(colors[top.v]==colors[graph[top.v][rr]])
                        {
                            //cout<<"hi"<<endl;
                            brk = true;
                            break;
                        }

                    }


                }
                

            }
            if(!brk)
            {
                comp++;

            }
            else
            {
                cout<<0<<endl;
                break;
            }
            int h;
            for(h=lv;h<n;h++)
            {
                if(!visited[h])break;

            }
            lv = h;
            //cout<<lv<<endl;
        }
        if(!brk)
            cout<<(pow(comp)%mod)<<endl;
            //cout<<mod<<endl;
            //cout<<comp<<endl;
    }




return 0;
}

