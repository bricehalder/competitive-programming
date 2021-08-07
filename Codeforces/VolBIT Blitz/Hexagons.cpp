#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long number = 1 + 6 * ((n * (n + 1)) / 2);

    cout << fixed << setprecision(0) << number;

    return 0;
}
