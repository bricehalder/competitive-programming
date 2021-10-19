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
    int calcCost(int cost, int time, int change) {
        int nextChange = (cost / change) * change + change;

        if (cost + time > nextChange) {
            return nextChange;
        } else {
            return cost + time;
        }
    }

    // make graph
    // djikstras for shortest path, except visit each node twice, on second visit = ssecond shortest
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(n + 1, 0);

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});

        vector<int> costs(n + 1, INT_MAX);

        while (!pq.empty()) {
            int cost = pq.top().first;
            int cur = pq.top().second;
            pq.pop();

            if (visited[cur] == 2) continue;
            visited[cur]++;

            if (visited[cur] == 2 && cur == n) {
                return cost;
            }

            for (auto& node : adj[cur]) {
                int tempCost = cost + calcCost(cost, time, change);
                if (tempCost < costs[node]) {
                    costs[node] = tempCost;
                    pq.push({tempCost, node});
                }
            }

        }

        return -1;
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
