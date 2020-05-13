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

void shortestPath(int start, int finish)
{
    visited[start] = 1;
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int curVertex = q.front();
        if(finish == curVertex)
        {
            ///print the path here. Its backwards but the graph is undirected so its not a problem.
            ///if you want it from start to finish instead from finish to start, the easiest solution
            ///is to swap them in the beginning of the function :)
            while(curVertex != start)
            {
                cout<<curVertex<<" ";
                curVertex = p[curVertex];
            }
            cout<<start<<endl;
            return;
        }
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
        }
        q.pop();
    }
    cout<<"There is no path between the two vertices"<<endl;
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
    int start, finish;
    cin>>start>>finish;
    shortestPath(start, finish);
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
0 4
*/
