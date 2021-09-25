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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // check if either left or right sum == node sum
public:
    map<TreeNode *, int> st_sum;

    bool checkEqualTree(TreeNode* root) {
        return helper(root, 0);
    }
    
    int dfs(TreeNode *node) {
        if (!node) return 0;

        if (st_sum.find(node) != st_sum.end()) {
            return st_sum[node];
        }

        int val = node->val + dfs(node->left) + dfs(node->right);
        st_sum[node] = val;

        return val;
    }
    
    bool helper(TreeNode *root, int prev) {
        if (!root) return false;
        if (!root->left && !root->right) return false;

        int val = root->val + prev;
        int left = dfs(root->left);
        int right = dfs(root->right);

        if (root->left && !root->right) {
            if (left == val) return true;
        }

        if (root->right && !root->left) {
            if (right == val) return true;
        }

        if (root->left && root->right) {
            if (left + val == right || right + val == left) {
                return true;
            }
        }

       return helper(root->right, left + val) || helper(root->left, right + val);
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
