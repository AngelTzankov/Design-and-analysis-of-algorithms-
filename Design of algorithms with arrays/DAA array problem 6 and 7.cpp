#include <iostream>
using namespace std;

int quickSortPartition(int *arr, int from, int to)
{
    int p1 = from, pivot = arr[to];
    for(int i = from;i <= to-1; ++i)
    {
        if(arr[i] < pivot)
        {
            swap(arr[i], arr[p1++]);
        }
    }
    swap(arr[p1], arr[to]);
    return p1;
}

int quickSelect(int *arr, int from, int to, int k)
{
    if(from > to)
        return INT_MAX;

    int p = quickSortPartition(arr, from, to);
    if(p + 1 == k + from)
        return arr[p];
    else if(p + 1 > k)
    {
        return quickSelect(arr, from, p - 1, k);
    }
    else
    {
        return quickSelect(arr, p + 1, to, k - p - 1);
    }

}

int main()
{
    int n, a[1000];
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    cout<<quickSelect(a, 0, n-1, k)<<endl;
}
