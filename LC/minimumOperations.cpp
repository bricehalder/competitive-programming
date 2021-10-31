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
    // bfs 
    // push start
    //     if num < 0 or > 1000 then can't push more
    //     then for each num
    //          push cur +-^ num
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> qu;
        qu.push(start);

        vector<bool> visited(1001, false);
        int dist = 0;
        
        while (!qu.empty()) {
            int size = qu.size();
            while (size--) {
                int cur = qu.front();    
                qu.pop();
                
                if (cur == goal) return dist;
                
                if (cur < 0 || cur > 1000 || visited[cur]) continue;
                visited[cur] = true;

                for (int i : nums) {
                    qu.push(cur + i);
                    qu.push(cur - i);
                    qu.push(cur ^ i);
                }
            }
            
            dist++;
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
