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

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int min_x = INT_MAX, max_x = 0;
        int min_y = INT_MAX, max_y = 0;

        for (auto vi : trees) {
            if (vi[0] < min_x) min_x = vi[0];
            if (vi[1] < min_y) min_y = vi[1];
            if (vi[0] > max_x) max_x = vi[0];
            if (vi[1] > max_y) max_y = vi[1];
        }

        vvi soln;

        for (auto vi : trees) {
            if (vi[0] == min_x || vi[0] == max_x || vi[1] == min_y || vi[1] == max_y) {
                soln.push_back(vi);
            }
        }

        return soln;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* code starts here */
    int n;
    cin >> n;

    rep(i, 0, n) {
        
    }
}
