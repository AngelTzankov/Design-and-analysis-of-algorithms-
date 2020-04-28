#include <iostream>
using namespace std;

int main()
{
    int n, a[1000];

    ///Problem 1 Naive
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }

    int prod = 0, firstAnsIdx, secondAnsIdx;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(a[i] * a[j] > prod)
            {
                prod = a[i] * a[j];
                firstAnsIdx = i;
                secondAnsIdx = j;
            }
        }
    }
    cout<<prod<<endl;

    int biggestIdx = 0, secondBiggestIdx = 1, smallestIdx = 0, secondSmallestIdx = 1;
    if(a[0] > a[1])
        swap(smallestIdx, secondSmallestIdx);
    for(int i=0;i<n;i++)
    {
        if(a[i] > a[biggestIdx])
        {
            secondBiggestIdx = biggestIdx;
            biggestIdx = i;
        }
        else if(a[i] > a[secondBiggestIdx])
        {
            secondBiggestIdx = i;
        }

        if(a[i] < a[smallestIdx])
        {
            secondSmallestIdx = smallestIdx;
            smallestIdx = i;
        }
        else if(a[i] < secondSmallestIdx)
        {
            secondSmallestIdx = i;
        }
    }
    cout<<max(a[secondSmallestIdx] * a[smallestIdx], a[biggestIdx] * a[secondBiggestIdx])<<endl;
}
