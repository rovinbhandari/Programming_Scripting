#include <cstdio>
#include <list>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
    const long M = 1000000007;
    int color[20001];
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        list<int> graph[20001];
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
        {
            int k;
            scanf("%d", &k);
            while(k--)
            {
                int temp;
                scanf("%d", &temp);
                graph[i].push_back(temp);
                graph[temp].push_back(i);
            }
        }

        int num_ways = 1;
        memset(color, 0, sizeof(color));

        for(int i = 0; i < n; i++)
        {
            if(color[i] == 0)
            {
                color[i] = 1;
                num_ways = (num_ways << 1) % M;
                queue<int> bfsq;
                bfsq.push(i);

                while(!bfsq.empty())
                {
                    int par = bfsq.front();
                    bfsq.pop();

                    for(list<int>::iterator it = graph[par].begin();
                        it != graph[par].end(); it++)
                    {

                        if(color[*it] == 0)
                        {
                            color[*it] = -color[par];
                            bfsq.push(*it);
                        }

                        else if(color[par] != -color[*it])
                        {
                            num_ways = 0;
                            break;
                        }
                    }
                }
            }
        }

        printf("%d\n", num_ways);
    }

    return 0;
}
