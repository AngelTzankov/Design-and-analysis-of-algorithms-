```
isCyclic(G(V, E): Graph)
1.  foreach u in V
2.    if color[u] == White
3.      if(DFSCheck(G, u))
4.        return true
5.  return false

DFSCheck(G(V,E): graph, v: vertex from V)
1. color[v] <- Gray
2. foreach u in Adj(v)
3.   if color[u] = White
4.     if(DFSCheck(G,u))
5.       return true
6.   elif color[u] == Gray
7.     return true
8. color[v] <- Black
9. return false
```
