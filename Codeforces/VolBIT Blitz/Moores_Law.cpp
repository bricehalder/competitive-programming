#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    short n;
    long t;

    cin >> n;
    cin >> t;

    long double transistors = n * pow(1.000000011,t);

    cout << fixed << setprecision(9);
    cout << transistors << endl;
    return 0;
}
