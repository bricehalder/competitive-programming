#include <iostream>
#include <iomanip>
#include <cmath>

#define ld long double
using namespace std;

ld fact(size_t n)
{
    if (n <= 1)
        return 1;
    return n*fact(n - 1);
}

ld nPk(size_t n, size_t r)
{
    return fact(n) / fact(n - r);
}

int main() {
    size_t n;
    cin >> n;

    ld answer = pow(nPk(n,5), 2);
    answer /= fact(5);

    cout << fixed << setprecision(0);
    cout << answer << endl;

    return 0;
}
