```
countComps(G(V, E): Graph)
1.  components <- 0
2.  foreach u in V
3.    if color[u] == White
4.      DFSVisit(G, u)
5.      components <- components + 1
6.  return components

DFSVisit(G(V,E): graph, v: vertex from V)
1. color[v] <- Gray
2. foreach u in Adj(v)
3.   if color[u] = White
4.     DFSVisit(G,u)
5. color[v] <- Black
```
