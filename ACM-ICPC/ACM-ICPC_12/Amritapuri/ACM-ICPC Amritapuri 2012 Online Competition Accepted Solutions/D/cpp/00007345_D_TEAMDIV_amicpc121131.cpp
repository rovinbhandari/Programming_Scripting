#include<iostream>
#include<queue>
#include<list>
using namespace std;

class Node
{
    public:
        int id;
        list<int> neighbours;
        bool seen;
        int team;
};


int main()
{
    long long big = 1000000007;
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        Node graph[n];
        for (int i = 0; i < n; i++)
        {
            graph[i].id = i;
            graph[i].seen = false;
        }
        for (int i = 0; i < n; i++)
        {
            int noOfRivals;
            cin>>noOfRivals;
            for (int j = 0; j < noOfRivals; j++)
            {
                int rival;
                cin>>rival;
                graph[i].neighbours.push_back(rival);
                graph[rival].neighbours.push_back(i);
            }
        }
        long long possible = 1;
        bool inconsistent = false;
        for (int i = 0; i < n; i++)
        {
            if (graph[i].seen)
            {
                continue;
            }
            queue<int> bfsQueue;
            bfsQueue.push(i);
            graph[i].team = 0;
            graph[i].seen = true;
            while (!bfsQueue.empty())
            {
                int node = bfsQueue.front();
                bfsQueue.pop();
                int toAssign = 1 - graph[node].team;
                list<int>::iterator it;
                for (it = graph[node].neighbours.begin(); it != graph[node].neighbours.end(); it++)
                {
                    if (graph[*it].seen && graph[*it].team != toAssign)
                    {
                        inconsistent = true;
                        break;
                    }
                    else if (!graph[*it].seen)
                    {
                        graph[*it].seen = true;
                        graph[*it].team = toAssign;
                        bfsQueue.push(*it);
                    }
                }
                if (inconsistent)
                {
                    break;
                }
            }
            if (inconsistent)
            {
                possible = 0;
                break;
            }
            possible *= 2;
            possible %= big;
        }
        cout<<possible<<endl;
    }
    return 0;
}
