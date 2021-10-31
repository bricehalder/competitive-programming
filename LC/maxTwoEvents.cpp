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
    // sort by value
    // greedily choose top two
    // while not overlap continue
    struct cmp {
        bool operator() (const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[2] > rhs[2];
        }
    };
    
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), cmp());

        vector<vector<vector<int>>> best;
        
        for (auto e : events) {
            int counter = 0; 
            bool inserted = false;
            for (auto b : best) {
                counter++;

                if (b.size() < 2 && !overlap(b[0], e)) {
                    b.push_back(e);
                    inserted = true;
                }
            }
            if (!inserted) {
                best.push_back({e});
            }
        }

        int bestSum = 0;

        for (auto b : best) {
            int sum = 0;

            for (auto e : b) {
                sum += e[2];
            }

            bestSum = max(bestSum, sum);
        }

        return bestSum;
    }

    bool overlap(vector<int>& one, vector<int>& two) {
        bool ret = true;
        
        if (one[0] < two[0]) {
            ret = one[1] >= two[0];
        } else if (two[0] < one[0]) {
            ret = two[1] >= one[0];
        }
        
        for (int i : one) {
            cout << i << " ";
        }
        cout << "| ";
        for (int i : two) {
            cout << i << " ";
        }
        cout << "| " << ret << endl;
        return ret;
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
