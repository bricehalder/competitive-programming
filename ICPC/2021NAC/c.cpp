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

int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) {
        return 0;
    }
    int m = matrix.size(), n = matrix[0].size(), sz = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!i || !j || matrix[i][j] == '0') {
                dp[i][j] = matrix[i][j] - '0';
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            sz = max(dp[i][j], sz);
        }
    }
    return sz * sz;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* code starts here */
    int n, m, k;
    cin >> n, m, k;

    vvi grid(n, vi(m));

    vii idcs;

    int i, j;
    int furthest_corner = 0;

    rep(i, 0, k) {
        cin >> i, j;
        if (is_corner(i, j)) {
            int d = bord_dist(i, j);
            if (d > furthest_corner) {
                furthest_corner = d;
            }
        }

        grid[i - 1][j - 1] = LARGE_PRIME;
        idcs.push_back({i, j});
    }

    trav(block, idcs) {
        inflate(block);
    }

    trim(grid);

}
