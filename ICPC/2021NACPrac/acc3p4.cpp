#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

/* Compile:  g++ -std=c++11 -O2 -Wall template.cpp -o template */


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;    
    int op, l, r, a;

    cin >> n >> q;

    vector<int> nums(n, 0);

    for (int i = 0; i < q; i++) {
        cin >> op;

        if (op == 1) {
            cin >> l >> r >> a;
            for (int j = l; j <= r; j++) {
                nums[j] += a * (j - l + 1);
            }
        } else {
            cin >> l >> r;
            int sum = 0;
            for (int j = l; j <= r; j++) {
                sum += nums[j];
            }
            cout << sum << endl;
        }
    }
    
}