```
BFS(G(V,E): graph, start: vertex in V, finish: vertex in V)
1.  foreach u in V
2.    visited[u] <- False
3.    dist[u] <- INF
4.  Q <- празна опашка
5.  Q.push(start)
6.  dist[start] = 0
7.  while Q не е празна
8.    v <- Q.pop()
9.    foreach w in Adj(v)
10.     if !visited[w]
11.       visited[w] <- True
12.       dist[w] <- dist[v] + 1
13.       Q.push(w)
14.  return dist[finish]
```
