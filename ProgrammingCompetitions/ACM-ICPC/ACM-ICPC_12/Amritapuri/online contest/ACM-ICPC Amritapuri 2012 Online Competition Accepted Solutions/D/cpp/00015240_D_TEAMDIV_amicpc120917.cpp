#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define NOCOLOR 0
#define RED 1
#define BLUE 2

vector<int> adjlist[20002];

int marked[20002];

int bfs(int start)
{
    int v, len, i, color = RED;
    queue<int> q;
    q.push(start);
    marked[start] = RED;
    while (!q.empty())
    {
        v = q.front();
        q.pop();

        if (marked[v] == RED)
            color = BLUE;
        else
            color = RED;

        len = adjlist[v].size();
        for (i = 0; i < len; i++)
        {
            if (marked[adjlist[v][i]] == NOCOLOR)
            {
                marked[adjlist[v][i]] = color;
                q.push(adjlist[v][i]);
            }
            else if ((color == BLUE && marked[adjlist[v][i]] == RED) || (color == RED && marked[adjlist[v][i]] == BLUE))
            {
                return 0;
            }
        }
    }
    return 1;
}

long long bigmod(long long b,long long p,long long m) {
    long long k;
    if (p == 0)
        return 1;
    else if (p%2 == 0)
    {
        k = bigmod(b,p/2,m);
        return  k * k % m; // square(x) = x * x
    }
    else
        return ((b % m) * bigmod(b,p-1,m)) % m;
}


int main()
{
    int T, N, i, nn, respow, res, e;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        for (i = 0; i < N; i++)
        {
            adjlist[i].clear();
        }
        for (i = 0; i < N; i++)
        {
            scanf("%d", &nn);
            marked[i] = NOCOLOR;
            while (nn--)
            {
                scanf("%d", &e);
                adjlist[i].push_back(e);
                adjlist[e].push_back(i);
            }
        }
        respow = 0;
        for (i = 0; i < N; i++)
        {
            if (marked[i] == NOCOLOR)
            {
                res = bfs(i);
                if (res)
                    respow++;
                else
                {
                    printf("0\n");
                    break;
                }
            }
        }
        if (respow)
            printf("%lld\n", bigmod(2, respow, 1000000007));
    }

    return 0;
}