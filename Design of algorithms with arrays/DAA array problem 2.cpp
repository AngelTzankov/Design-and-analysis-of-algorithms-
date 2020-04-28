#include <iostream>
using namespace std;

int main()
{
    int n, a[1000], x, y, k;
    int cnt[1001] = {0};
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    cin>>x>>y;

    for(int i=0;i<n;++i)
    {
        cnt[a[i]] += 1;
    }

    for(int i=2;i<=k;++i)
    {
        cnt[i] += cnt[i-1];
    }

    cout<<cnt[y] - cnt[x-1]<<endl;
}
