#include <iostream>
#include <iomanip>

#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll ans = n - (n / 2) - (n / 3) + (n / 6) - (n / 5) + (n / 10) -
        (n / 7) + (n / 14) + (n / 15) + (n / 21) - (n / 30) + (n / 35) -
        (n / 42) - (n / 70) - (n / 105) + (n / 210);
    cout << fixed << setprecision(0);
    cout << ans << endl;
    return 0;
}
