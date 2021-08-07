#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

#define ll long long
using namespace std;

ll nCk(size_t n, size_t k) {
    ll ans = 1;
    k = min(k, (n-k));
    for (size_t i = 1; i <= k; ++i) {
        ans *= (n - (k - i));
        ans /= i;
    }
    return ans;
}

int main() {
    size_t n;
    cin >> n;

    ll answer = nCk(n + 4, n - 1) * nCk(n + 2, n - 1);

    cout << answer << endl;

    return 0;
}
