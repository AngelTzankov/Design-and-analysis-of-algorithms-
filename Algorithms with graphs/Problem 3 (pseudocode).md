For the sake of simplicity the function returns the length of the shortest cycle instead of the cycle itself
```
shortestCycle(G(V, E): Graph)
1.  shortestCycleLen <- INF
2.  foreach u in V
3.    curCycleLen <- shortestCycleThroughVertex(G, u)
4.    if(curCycleLen < shortestCycleLen)
5.        shortestCycleLen <- curCycleLen
6.  return shortestCycleLen



BFS(G(V,E): graph, v: vertex from V)
1.  foreach u in V
2.    visited[u] <- False
3.    dist[u] <- INF
4.  Q <- празна опашка
5.  Q.push(v)
6.  while(Q не е празна) 
7.    curV <- Q.pop()
8.    foreach w in adj(curV)
9.      if !visited[w]
10.       visited[w] <- True
11.       dist[w] <- dist[curV] + 1
12.       Q.push(w)
13.     else 
14.       return dist[w] + dist[curV] + 1
15. return INF
```
