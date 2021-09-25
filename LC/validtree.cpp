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

bool dfs(int s, int parent, vvi& adj, vb& visited) {
    if (visited[s]) return false;
    visited[s] = true;

    bool ret = true;
    // process node s
    for (auto u : adj[s]) {
        if (u != parent && !dfs(u, s, adj, visited)) ret = false;
    }

    return ret;
}

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vb visited(n);
        vvi adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        if (!dfs(0, -1, adj, visited)) return false; 

        return edges.size() == n - 1;
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
