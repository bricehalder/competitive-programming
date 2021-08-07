#include <iostream>
#include <iomanip>
#include <cmath>

#define ld long double
using namespace std;

int main() {
    ld n;
    cin >> n;

    ld answer = floor(n / 2520);

    cout << fixed << setprecision(0);
    cout << answer << endl;

    return 0;
}
