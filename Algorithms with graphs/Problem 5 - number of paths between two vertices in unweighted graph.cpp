#include <iostream>
using namespace std;

int adjMat[100][100], res[100][100], dummyMat[100][100];

void mult(int a[100][100], int b[100][100], int res[100][100], int n)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            dummyMat[i][j] = 0;
            for(int k=0;k<n;++k)
            {
                dummyMat[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            res[i][j] = dummyMat[i][j];
        }
    }
}

void powerMatrix(int k, int mat[100][100], int res[100][100], int n)
{
    if(k == 1)
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                res[i][j] = mat[i][j];
            }
        }
        return;
    }
    powerMatrix(k/2, mat, res, n);
    mult(res, res, res, n);
    if(k%2 == 1)
        mult(res, mat, res, n);

}

int main()
{
    int n, m, from, to;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        cin>>from>>to;
        adjMat[from][to] = 1;
    }
    int k;
    cin>>k>>from>>to;
    powerMatrix(k, adjMat, res, n);
    cout<<res[from][to]<<endl;
}
/*
3 5
0 1
0 0
0 2
1 2
2 1
2 1 2
*/
