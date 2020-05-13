#include <iostream>
#include <vector>
using namespace std;

enum Colour
{
    WHITE,
    GRAY,
    BLACK
};

struct adjList
{
    vector<int> neighbours;
};

adjList graph[1000];
Colour visited[1000];

void init(int n)
{
    for(int i=0;i<n;++i)
    {
        visited[i] = WHITE;
    }
}

bool checkForCycle(int v)
{
    visited[v] = GRAY;
    for(int i=0;i<graph[v].neighbours.size();++i)
    {
        int neighbour = graph[v].neighbours[i];
        if(visited[neighbour] == WHITE)
        {
            if(checkForCycle(neighbour))
                return true;
        }
        else if(visited[neighbour] == GRAY)
        {
            return true;
        }
    }
    visited[v] = BLACK;
    return false;
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
    for(int i=0;i<n;++i)
    {
        if(!visited[i])
        {
            if(checkForCycle(i))
            {
                cout<<"There is a cycle in the graph"<<endl;
                return 0;
            }
        }
    }
    cout<<"There is no cycle in the graph"<<endl;
}
