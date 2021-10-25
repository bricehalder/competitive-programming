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

// dp[i] = min jumps to reach ground level from i meters below ground level
// if i - a[i] <= 0 --> can reach ground so reach is 1
// if i - a[i] > 0 AND b[i] >= a[i], reach is -1
// reach[i] = min(reach[i - a[i]]) + 1 over a[i] = 1..a[i]
int jumps(int i, vector<int>& a, vector<int>& b, vector<int>& jmps, unordered_map<int, int>& next) {
    if (i <= 0 || i >= jmps.size()) return INT_MAX;

    if (jmps[i] != INT_MAX) return jmps[i];

    if (i - a[i] <= 0) return 1;
    if (i - a[i] > 0 && b[i] >= a[i]) return INT_MAX;
    
    int minJ = INT_MAX;
    int cur = -1;
    for (int j = i - a[i]; j < i; j++) {
        minJ = min(minJ, jumps(j, a, b, jmps, next));
        cur = j;
    }

    next[i] = cur;
    if (minJ != INT_MAX) {
        jmps[i] = minJ + 1;
    }

    return jmps[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* code starts here */
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    vector<int> jmps(n + 1, INT_MAX);
    unordered_map<int, int> next;

    for (int i = 1; i <= n; i++) {
        next[i] = -1;
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int minJ = jumps(n, a, b, jmps, next);

    if (minJ == INT_MAX) {
        cout << -1 << endl;
        return 0;
    }

    cout << jmps[n] << endl;
    
    int nextI = n;
    while (jmps[n]--) {
        cout << next[nextI] << " ";
        nextI = next[nextI];
    }
}

