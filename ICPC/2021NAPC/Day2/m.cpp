#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

/* Compile:  g++ -std=c++11 -O2 -Wall template.cpp -o template */

void search(int i) { return; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    // solution comes here
    int n;
    cin >> n;
    int sides = floor(sqrt(n));
    cout << "The largest square has side length " << sides << "." << endl;
}