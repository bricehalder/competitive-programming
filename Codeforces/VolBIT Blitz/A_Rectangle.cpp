#include <iostream>
#include <iomanip>
#include <cmath>

#define ll long long
using namespace std;

int main() {
    ll x1, y1, x2, y2;
    ll answer = 0;

    cin >> x1 >> y1 >> x2 >> y2;

    ll xlen = (x2 - x1) + 1;

    ll yhigh = ((y2 - y1) / 2) + 1;
    ll ylow = (y2 - y1) / 2;

    answer += ylow * floor(xlen / 2.0);
    answer += yhigh * ceil(xlen / 2.0);

    cout << fixed << setprecision(0);
    cout << answer << endl;

    return 0;
}
