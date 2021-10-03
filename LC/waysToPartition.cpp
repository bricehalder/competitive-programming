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


// without k
// compute sums l-->r and r-->l
// pivot is wherever sums[i - 1] == rsums[i]
// store k - num in hashmap with a list of its idcs
// if we have rsums[i] - sums[i - 1] on left side
// or sums[i - 1] - rsums[i] on the right side
class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<long long> sums(n);
        vector<long long> rsums(n);
        
        unordered_map<long long, int> diffLeft, diffRight;
        
        int count = 0;

        sums[0] = nums[0];
        rsums[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            sums[i] = sums[i - 1] + nums[i];
            rsums[n - 1 - i] = rsums[n - i] + nums[n - 1 - i];
        }
        
        for (int i = 1; i < n; i++) {
            diffRight[sums[i - 1] - rsums[i]]++;
        }

        if (diffRight.count(0)) 
            count = diffRight[0];
        
        for (int i = 0; i < n; i++) {
            int cur = 0;
            long long diff = k - nums[i];
            
            if (diffLeft.count(diff))
                cur += diffLeft[diff];
            
            if (diffRight.count(-diff))
                cur += diffRight[-diff];
            
            count = max(count, cur);
            
            if (i < n - 1) {
                long long dd = sums[i] - rsums[i + 1];    
                diffLeft[dd]++;
                diffRight[dd]--;
                if (!diffRight[dd])
                    diffRight.erase(dd);

            }
        }

        return count; 
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
