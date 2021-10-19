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
    // first msg recv: (distance from origin * 2)
    // # msg sent: first msg recv / patience
    // last msg send: #msg sent / patience
    // last msg recv at: send time + dist * 2

    // convert to adj list
    // bfs and set min time to last msg recv of any node
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        visited[0] = true;

        queue<int> qu;
        qu.push(0);

        int minTime = 0;
        int depth = 0;

        while (!qu.empty()) {
            int sz = qu.size();
            depth++;
            for (int i = 0; i < qu.size(); i++) {
                int cur = qu.front();
                qu.pop();

                for (auto& serv : adj[cur]) {
                    if (visited[serv]) continue;
                    visited[serv] = true;

                    int firstMsgRecv = (depth * 2) - 1;
                    int lastMsgSend = firstMsgRecv - (firstMsgRecv % patience[serv]);
                    int lastMsgRecv = lastMsgSend + depth * 2; 

                    cout << depth << " " << firstMsgRecv << " " << lastMsgRecv << endl;
                    minTime = max(minTime, lastMsgRecv + 1);
                    qu.push(serv);
                }   
            }
        }

        return minTime;
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
