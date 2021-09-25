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
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        // bottom up
        // either min(nums) or min(nums + 1)
        // send up value
        // if child is < val, new  min is child's val
        // either min(nums) or max + 1
        int n = parents.size();
        
        vector<vector<int>> tree(parents.size());

        for (int i = 1; i < parents.size(); i++){ 
            tree[parents[i]].push_back(i);
        }

        int min_idx = min_element(nums.begin(), nums.end()) - nums.begin();

        vector<int> ans(parents.size(), nums[min_idx]);

        set<int> vals;
        dfs(min_idx, vals, tree, nums);

        int cur_idx = min_idx;
        int prev_min = 1;

        while (cur_idx != -1) {
            vals.insert(nums[cur_idx]);
            if (nums[cur_idx] == prev_min) {
                int i = prev_min + 1;
                while (vals.find(i) != vals.end()) {
                    i++;
                }
                ans[cur_idx] = i;
                prev_min = i; 
            } else {
                ans[cur_idx] = prev_min;
            }

            cur_idx = parents[cur_idx];
        }

        return ans;
    }

    void dfs(int cur, set<int>& vals, vector<vector<int>>& tree, vector<int>& nums) {
        vals.insert(nums[cur]);

        for (int i : tree[cur]) {
            dfs(i, vals, tree, nums);
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
