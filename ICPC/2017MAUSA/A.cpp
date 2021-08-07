#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
    int S;
    cin >> S;

    set<pair<int, int>> soln;

    for (int i = 2; i <= (S + 1) / 2; i++) {
        for (int j = 0; j <= 1; j++) {
            if (S % (i + (i - j)) == 0 || S % (i + i - j) == i) {
                soln.insert(make_pair(i, i - j));
            }
        }
    }

    cout << S << ":" << endl;

    for (const pair<int, int> &p : soln) {
        cout << p.first << "," << p.second << endl;
    }

    return 0;
}
