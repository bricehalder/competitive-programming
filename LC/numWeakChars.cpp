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
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        // sort by x
        // look at max y at the end
        // for each char see if < max x, store in set
        // on each y, check set to see if there are lower y's in it
        // add each lower y to count
        // 

        sort(all(properties));

        map<int,  int> freq;

        int total = 0;

        int max_x = properties.back()[0];

        for (vi chr : properties) {
            if (chr[0] < max_x) {
                freq[chr[1]]++;

                for (auto it = freq.begin(); it != freq.end(); it++) {
                    if (it->first >= chr[1]) break;

                    total += it->second;
                    it->second = 0;
                }

            }
            
        }

        return total;
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
