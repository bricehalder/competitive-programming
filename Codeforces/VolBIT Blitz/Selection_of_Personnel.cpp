#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

#define ll long long
using namespace std;

ll nCk(size_t n, size_t k) {
    ll ans = 1;
    for (size_t i = 1; i <= min(k,n-k); ++i) {
        ans *= (n - (k - i));
        ans /= i;
    }
    return ans;
}

int main() {
    size_t n;
    cin >> n;

    ll answer = nCk(n,7) + nCk(n,6) + nCk(n,5);

    cout << answer << endl;

    return 0;
}
