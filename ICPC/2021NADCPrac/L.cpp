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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int e, f, c;
    cin >> e >> f >> c;
    
    int bottles_drank = 0;
    int bottles_have = e + f;

    while (bottles_have >= c) {
        int new_bottles_drank = bottles_have / c;
        bottles_have -= (bottles_have / c) * c;
        bottles_have += new_bottles_drank;

        bottles_drank += new_bottles_drank;
    }

    cout << bottles_drank;
}