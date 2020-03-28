#include <cstdio>
#include <iostream>

using namespace std;
long long a[100000], b[100000];
bool check(long long x, long long n) {
    long long nextStateOffset = b[0];
    for (long long i = 0; i < n - 1; ++i) {
        //std::cout << "b[" << i << "]: " << nextStateOffset << std::endl;
        if(nextStateOffset < x) {
            nextStateOffset = b[i + 1] - ((a[i + 1] - a[i]) + (x - nextStateOffset));
        } else if(nextStateOffset > x && ((nextStateOffset - x) - (a[i + 1] - a[i])) > 0) {
            nextStateOffset =  b[i + 1] + (nextStateOffset - x) - (a[i + 1] - a[i]);
        } else {
            nextStateOffset = b[i + 1];
        }
    }

    //std::cout << "b[n - 1]: " <<  nextStateOffset << std::endl;
    //here nextStateOffset should equal the remaining alchohol for the last building
    return nextStateOffset >= x;
}

long long maxRakia(long long l, long long r, long long n) {
    long long m;
    long long lastTrue = 0;

    while(l <= r) {
        m = (l + r)/2;

        if(check(m, n)) {
            lastTrue = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return lastTrue;
}

int main() {
    long long n;

    std::scanf("%lld", &n);

    long long r = 0;

    for (long long i = 0; i < n; ++i) {
        std::scanf("%lld %lld", &a[i], &b[i]);
        if(b[i] > b[r]) {
            r = i;
        }
    }

    //std::cout << "RESULT: " << check(51, n) << std::endl;
    long long res = maxRakia(0, b[r], n);
    std::printf("%lld\n", res);

}
