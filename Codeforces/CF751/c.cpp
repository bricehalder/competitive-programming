#include <bits/stdc++.h>

using namespace std;

typedef vector<int>        vi;
typedef vector< vi >       vvi;
typedef pair<int, int>     pii;
typedef vector< pii >      vii;
 
typedef vector< bool >     vb;
typedef vector< vb >       vvb;
 
typedef long long          ll;
typedef vector<ll>         vl;
typedef vector< vl >       vvl;
typedef pair<ll, ll>       pll;
typedef vector< pll >      vll;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
#define mp make_pair
#define debug(content) if (DEBUG_MODE) cout << "DEBUG: " << content << endl
#define DEBUG_MODE 1
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)

const int LARGE_PRIME = 998244353;
const int LARGE_INT = 1000000007;
const ll LARGE_LONG = 1LL << 60;

// need k to be divisor of num of nonzero elems
// 4
// 13 7 25 19
// 01101  00100  00100
// 00111  00111  00111
// 11001  10000  00000
// 10011  10011  00011
// count if # of that bit is 0 or divisible by k 

void solve(int& len, vector<int>& arr) {
    vector<int> set(1);

    int nonzero = 0;
    trav(num, arr) {
        int bit = 0;

        if (num > 0) {
            nonzero++;
        }

        while (num) {
            if (num & 1) {
                set[bit]++;
            }
            num = num >> 1;
            bit++;

            if (bit >= set.size()) {
                set.push_back(0);
            }
        }
    }

    for (int k = 1; k <= len; k++) {
        bool good = true;

        if (nonzero > 0 && nonzero % k != 0) {
            continue;
        }

        if (nonzero == 0) {
            cout << k << " ";
            continue;
        }
        
        for (int i = 0; i < set.size(); i++) {
            if (set[i] % k != 0) {
                good = false;
                break;
            }
        }

        if (good) {
            cout << k <<  " ";
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* code starts here */
    int n;
    cin >> n;

    rep(i, 0, n) {
        int len;
        vector<int> arr;

        cin >> len;
        arr.resize(len);

        rep(i, 0, len) {
            cin >> arr[i];
        }

        solve(len, arr);
    }
}
