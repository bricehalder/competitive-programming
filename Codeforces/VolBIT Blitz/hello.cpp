#include <iostream>
#include <iomanip>

#define ll long long
int main() {
    ll n;
    std::cin >> n;

    std::cout << std::fixed << std::setprecision(0);

    std::cout << 2 - (n % 2);
    return 0;
}
