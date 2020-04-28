#include <iostream>
using namespace std;

#define MOD 1000000007

int main()
{
    long long n, a[1000], suffixProd[1000], b[1000];
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];

    suffixProd[n-1] = a[n-1];
    for(int i=n-2;i>=0;--i)
    {
        suffixProd[i] = suffixProd[i+1] * a[i];
    }

    long long prefixProd = 1;

    for(int i=0;i<n-1;++i)
    {
        b[i] = ( prefixProd * suffixProd[i+1] ) % MOD ;
        prefixProd = (prefixProd * a[i]) % MOD;
    }
    b[n-1] = prefixProd;

    for(int i=0;i<n;++i)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
}
