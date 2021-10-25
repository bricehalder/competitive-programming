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

void solve(int& sz, vector<int>& arr, int& queries) {
    vector<vector<int>> trans(1);
    trans[0] = arr;
    
    bool stable = false;
    // cout << sz << " " << arr[0] << " " << queries << endl;
    rep(i, 0, queries) {
        int x, k;
        cin >> x >> k;

        int cur = trans.size() - 1;
        while (trans.size() - 1 < k && !stable) {
            unordered_map<int, int> freq;
            bool curStable = true;

            for (int i = 0; i < sz; i++) {
                freq[trans[cur][i]]++;
            }

            trans.push_back(vector<int>(sz));

            for (int i = 0; i < sz; i++) {
                if (freq[trans[cur][i]] != trans[cur][i]) {
                    curStable = false;
                }
                trans[cur + 1][i] = freq[trans[cur][i]];
            }

            cur++;
            if (curStable) {
                stable = true;
            }
        }

        if (stable) {
            if (k >= trans.size()) {
                cout << trans[trans.size() - 1][x - 1] << endl;
            } else {
                cout << trans[k][x - 1] << endl;
            }
        } else {
            cout << trans[k][x - 1] << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> arr;

    /* code starts here */
    int n;
    cin >> n;

    rep(i, 0, n) {
        int sz;
        vector<int> arr;
        int queries;

        cin >> sz;
        arr.resize(sz);
        for (int i = 0 ; i < sz; i++) {
            cin >> arr[i];
        }
        cin >> queries;
        solve(sz, arr, queries);
    }
}
