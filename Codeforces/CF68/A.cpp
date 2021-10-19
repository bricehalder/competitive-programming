#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

#define ll long long

int main() {
    ll t, n, x;
    cin >> t;

    cout << fixed << setprecision(0);

    for (int i = 0; i < t; i++) {
        cin >> n;
        cin >> x;
        cout << x * 2 << endl;
    }

    return 0;
}
