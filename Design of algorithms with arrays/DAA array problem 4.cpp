#include <iostream>
using namespace std;

int main()
{
    int n, a[1000];
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }

    int sum = 0;
    for(int i=0;i<n;++i)
    {
        sum += a[i];
    }

    int prefixSum = 0;
    for(int i=0;i<n;++i)
    {
        if(prefixSum * 2 == sum - a[i])
        {
            cout<<i<<endl;
            return 0;
        }
        prefixSum += a[i];
    }

    cout<<"No dividing index!"<<endl;
}
