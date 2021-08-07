#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    short n;
    cin >> n;

    double long sum = 0;

    for (int i = 1; i <= n; ++i) {
        sum += pow(2, i);
    }

    cout << fixed << setprecision(0);
    cout << sum << endl;

    return 0;
}
