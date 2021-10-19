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
    // 11
    // 01
    //  3

    // 0011
    // 0010
    // 0001
    // 0101

    // for each subset, see if bitwise OR is equal to max
    // dfs
    int countMaxOrSubsets(vector<int>& nums) {
        int maxSubset = nums[0];
        
        for (int num : nums) {
            maxSubset |= num;
        }

        cout << maxSubset << endl;

        return dfs(0, nums, maxSubset, 0);
    }

    int dfs(int cur, vector<int>& nums, int maxSubset, int curSum) {
        if (cur == nums.size()) {
            return 0;
        }

        int contrib = 0;
        if (curSum | nums[cur] == maxSubset) {
            contrib = 1;
        }

        return contrib + dfs(cur + 1, nums, maxSubset, curSum | nums[cur]) + dfs(cur + 1, nums, maxSubset, curSum);
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
