```
topSort(G(V,E): graph)
1.  foreach u in V
2.    color[u] <- Whit
3.  order = empty stack
4.  foreach u in V
5.    if color[u] = White
6.      DFSVisit(G,v)
7.  return order

DFSVisit(G(V,E): graph, v: vertex from V, order: stack)
1.  color[v] <- Gray
2.  foreach u in Adj(v)
3.    if color[u] = White
4.      DFSVisit(G,u)
5.  color[v] <- Black
6.  order.push(v)
```
