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
    struct cmp {
        bool operator() (const string& lhs, const string& rhs) {
            if (lhs.size() != rhs.size()) {
                return lhs.size() < rhs.size();
            }
            
            int lhs_order = lhs.size();
            int rhs_order = rhs.size();
            
            for (int i = 0; i < lhs.size(); i++) {
                if (lhs[i] != rhs[i]) {
                    return lhs[i] < rhs[i];
                }
            }

            return lhs[lhs.size() - 1] < rhs[rhs.size() - 1];
        }    
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, cmp> pq;
        
        for (string& s : nums) {
            pq.push(s);
        }
        
        string cur;
        while (k) {
            cur = pq.top();
            pq.pop();
            k--;
        }
        
        return cur;
        
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
