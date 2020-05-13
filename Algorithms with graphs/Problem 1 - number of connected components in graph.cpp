#include <iostream>
#include <vector>
using namespace std;

struct adjList
{
    vector<int> neighbours;
};

adjList graph[1000];
bool visited[1000];

void dfs(int v)
{
    visited[v] = 1;
    for(int i=0;i<graph[v].neighbours.size();++i)
    {
        int neighbour = graph[v].neighbours[i];
        if(!visited[neighbour])
            dfs(neighbour);
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
        graph[to].neighbours.push_back(from);
    }
    int componentsCnt = 0;
    for(int i=0;i<n;++i)
    {
        if(!visited[i])
        {
            dfs(i);
            componentsCnt++;
        }
    }
    cout<<componentsCnt<<endl;
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