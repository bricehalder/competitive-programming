#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

/* Compile:  g++ -std=c++11 -O2 -Wall template.cpp -o template */

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string T;
    
    cin >> n;

    int d = 1;

    string in;
    for (int i = 0; i < n; i++) {
        cin >> in;

        T += in;
        T += to_string(d++);

    }

}