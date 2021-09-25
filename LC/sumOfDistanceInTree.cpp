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
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vi> adj;
        set<int> visited;
        vector<int> soln;
        soln.resize(n);

        for (auto vi : edges) {
            adj[vi[0]].push_back(vi[1]);
        }

        dfs(0, adj, visited, soln);

        return soln;
    }

    int dfs(int node, vvi& adj, set<int>& visited, vi& soln) {
        if (visited.find(node) != visited.end()) return 0;

        visited.insert(node);

        int sum = 0;
        for (auto i : adj[node]) {
            sum += dfs(i, adj, visited, soln) + 1;
        }

        soln[node] = sum;
        return sum;
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
