#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    size_t n;
    cin >> n;

    long double answer = (3 * pow(2,2 * n - 3)) + ((n - 3) * (9 * pow(4, (n - 3))));

    cout << fixed << setprecision(0);
    cout << answer << endl;

    return 0;
}
