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

void search(int i) { return; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    if (s.substr(0, 3).compare("555") == 0) {
        cout << 1;
    } else {
        cout << 0;
    }
}