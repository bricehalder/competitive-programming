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
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        // keep track of all w/h ratios we have seen
        // sum is n choose 2 for each ratio   
        // n * (n - 1) / 2
        
        long long sum = 0;

        map<double, int> freq;

        for (auto& rect : rectangles) {
            double ratio = rect[0] / (double) rect[1];
            freq[ratio]++;
        }

        for (auto it = freq.begin(); it != freq.end(); it++) {
            long long n = it->second;
            sum += (n * (n - 1)) / 2;
        }

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
