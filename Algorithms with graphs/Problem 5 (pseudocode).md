multiplyMatrix(L: n x n matrix, W: n x n matrix)
1.  let L` be a new n x n matrix
2.  for i <- 1 to n
3.    for j <- 1 to n
4.      L`[i][j] <- INF
5.      for k <- 1 to n
6.        L`[i][j] = min(L`[i][j], L[i][k]*W[k][j])
7.  return L`

GetPoweredMatrix(W: n x n matrix, k: integer)
1.  if k == 1 
2.    return W
3.  L <- getPoweredMatrix(W, k-1)
4.  if k mod 2 == 1
5.    return multipyMatrix(multipyMatrix(L, L), W)
6.  return multipyMatrix(L, L)
