#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

/* Compile:  g++ -std=c++11 -O2 -Wall template.cpp -o template */

struct xyz {
    int l;
    int u;
    double f;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y, n;

    cin >> x >> y >> n;

    int li, ui;
    double fi;

    double sum = 0;

    int distance = 0;
    vector<xyz> lst;

    for (int i = 0; i < n; i++) {
        cin >> li >> ui >> fi;

        if (lst.empty()) {
            lst.push_back({0, li, 1});
        } else {
            if (lst.back().u != li) {
                lst.push_back({lst.back().u, li, 1});
            }
        }
        lst.push_back({li, ui, fi});
    }

    if (!lst.empty()) {
        lst.push_back({lst.back().u, y, 1});
    }

    for (int i = 0; i < lst.size(); i++) {
        sum += (lst[i].u - lst[i].l) * lst[i].f;
    }
    
    if (sum == 0) {
        cout << setprecision(10) << x / y << endl;
    } else {
        cout << setprecision(10) << x / sum << endl;
    }

    return 0;
}