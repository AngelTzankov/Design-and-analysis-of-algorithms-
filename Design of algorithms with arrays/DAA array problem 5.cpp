#include <iostream>
using namespace std;

    int findMedian(int *arr1, int* arr2, int n, int m)
    {
        int l = 0, r = n-1, medPos = (m+n)/2;
        if(arr1[0] > arr2[m-1] && medPos == m)
            return arr1[0];
        while(l < r)
        {
            int mid = l + (r-l)/2;
            if(medPos - mid < m && arr2[medPos - mid] > arr1[mid] && arr2[medPos - mid - 1] < arr1[mid])
            {
                return arr1[mid];
            }
            else if(medPos - mid >= m || arr2[medPos - mid] > arr1[mid] && arr2[medPos - mid - 1] > arr1[mid])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        if(medPos - l < m && arr2[medPos - l] > arr1[l] && arr2[medPos - l - 1] < arr1[l])
        {
            return arr1[l];
        }
        return -1;
    }

int main()
{
        int n, m, arr1[100], arr2[100];
        cin>>n>>m;
        for(int i=0;i<n;++i)
        {
            cin>>arr1[i];
        }
        for(int i=0;i<m;++i)
        {
            cin>>arr2[i];
        }
        int x = findMedian(arr1, arr2, n, m), y = findMedian(arr2, arr1, m, n);
        if(x != -1)
            cout<<x<<endl;
        else
            cout<<y<<endl;
}
/*
3 4
3 7 9
2 4 6 8

    2 1
    1 3
    2

4 5
1 2 3 4
6 7 8 9 10

*/
