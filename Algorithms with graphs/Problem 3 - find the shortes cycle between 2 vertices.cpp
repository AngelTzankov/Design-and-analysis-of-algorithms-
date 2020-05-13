#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct adjList
{
    vector<int> neighbours;
};

adjList graph[1000];
bool visited[1000];
int p[1000];

void init(int n)
{
    for(int i=0;i<n;++i)
    {
        visited[i] = false;
        p[i] = i;
    }
}

void shortestCycle(int v, vector<int> &path)
{
    visited[v] = 1;
    queue<int> q;
    q.push(v);
    while(!q.empty())
    {
        int curVertex = q.front();
        visited[curVertex] = true;
        for(int i=0;i<graph[curVertex].neighbours.size();++i)
        {
            int curVertexChild = graph[curVertex].neighbours[i];
            if(!visited[curVertexChild])
            {
                visited[curVertexChild] = true;
                p[curVertexChild] = curVertex;
                q.push(curVertexChild);
            }
            else
            {
                int cycleVertex = curVertex;
                while(cycleVertex != v)
                {
                    path.push_back(cycleVertex);
                    cycleVertex = p[cycleVertex];
                }
                path.push_back(v);
                for(int j=0;j<path.size()/2;++j)
                {
                    swap(path[j], path[path.size()-j-1]);
                }
                cycleVertex = curVertexChild;
                while(p[cycleVertex] != v)
                {
                    path.push_back(cycleVertex);
                    cycleVertex = p[cycleVertex];
                }
                return ;
            }
        }
        q.pop();
    }
}

int main()
{
    /// n is the number of vertices in the graph
    /// m is the number of edges in the graph
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int from, to;
        cin>>from>>to;
        graph[from].neighbours.push_back(to);
    }
    int componentsCnt = 0;
    vector<int> curCyclePath, bestCyclePath;
    shortestCycle(0, bestCyclePath);
    for(int i=0;i<n;++i)
    {
        init(n);
        shortestCycle(i, curCyclePath);
        if(curCyclePath.size() < bestCyclePath.size() && curCyclePath.size() != 0 || bestCyclePath.size() == 0)
        {
            bestCyclePath = curCyclePath;
        }
        curCyclePath.clear();
    }
    for(int i=0;i<bestCyclePath.size();++i)
    {
        cout<<bestCyclePath[i]<<" ";
    }
    cout<<endl;
}
/*
10 8
0 2
0 1
2 4
3 4
5 7
7 9
6 8
9 5
*/
