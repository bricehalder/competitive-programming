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
    vector<vector<int>> grid;
    long long rob1 = 0;
    long long rob2 = 0;

    long long gridGame(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        this->grid = grid;

        rob1 = grid[0][0];
        grid[0][0] = 0;        

        dfs(0, 0, 0);
    }

    long long dfs(int r, int c, long long sum) {
        if (r >= grid.size() || c >= grid.size())
            return 0;

        sum += grid[r][c];
        long long down = dfs(r + 1, c, sum);
        long long right = dfs(r, c + 1, sum);

        if (down > right) {
            rob2 += right;
            return down;
        } else {
            rob2 += down;
            return right;
        }
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
