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

ll VectorToLong(vector<ll> v)
{
    reverse(v.begin(), v.end());
    int decimal = 1;
    ll total = 0;
    for (auto& it : v)
    {
        total += it * decimal;
        decimal *= 10;
    }
    return total;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* code starts here */
    int n, s, q;
    cin >> n >> s >> q;
    
    vector<ll> perm;
    int p;

    unordered_map<char, int> idcs;
    
    rep(i, 0, n) {
        cin >> p;
        perm.push_back(p);
        idcs[p] = i;
    }

    vector<vl> rows(s, vl(n));

    rows[0] = perm;

    unordered_map<ll, vl> cfg(n);
    cfg[n] = perm;
    cfg[1] = {1};

    // rep(k, 2, n + 1) {
    for (int i = 1; i < s; i++) {
        vl next;
        rep(j, 0, sz(rows[i])) {
            auto it = cfg.find(rows[i][j]);
            // if (it != cfg.end()) {
            next.insert(next.end(), all(it->second));
            cfg[rows[i][j]] = it->second;
            // }
        }
        rows.push_back(next);
        cfg[VectorToLong(rows[i + 1])] = next;
    }
    // }


    string final = rows[s + '0'];

    vector<int> counts(sz(final));
    rep(i, 0, sz(final)) {

    }

}
