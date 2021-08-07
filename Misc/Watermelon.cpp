// input is integer number w (1 ≤ w ≤ 100) = weight of the watermelon
// Print YES, if the boys can divide the watermelon into two parts,
// each of them weighing even number of kilos; and NO in the opposite case.

#include <iostream>
#include <cassert>

int main () {
    // Read input
    size_t w;
    std::cin >> w;

    assert (w >= 1 && w <= 100);

    if ((w - 2) % 2 == 0 && (w - 2) > 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
