#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

#define ld long double
using namespace std;

int main(int argc, char** argv) {
    string filename = argv[1];

    ifstream infile(filename);

    size_t t;
    infile >> t;

    string line;
    size_t b;

    for (int i = 1; i <= t; i++) {
        getline(infile, line);
        b = 0;
        for (char c : line) {
            if (c == 'B') {
                b++;
            }
        }
        bool pass = b >= line.length() / 2 && b != line.length() - 1;
        std::cout << "Case #" + to_string(i) + ": " + (pass ? "N" : "Y") << '\n';
    }

    return 0;
}
