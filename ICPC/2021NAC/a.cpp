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

int k_sum(vector<int> a, int n, int k)
{
    // To store the right index
    // and the current sum
    int r = 0, sum = 0;
 
    // To store the number of sub-arrays
    int ans = 0;
 
    // For all left indexes
    for (int l = 0; l < n; l++) {
 
        // Get elements till current sum
        // is less than k
        while (sum > k) {
            if (r == n)
                break;
            else {
                sum += a[r];
                r++;
            }
        }
 
        // No such subarray is possible
        if (sum < k)
            break;
 
        // Add all possible subarrays
        ans += n - r + 1;
 
        // Remove the left most element
        sum -= a[l];
    }
 
    // Return the required answer
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* code starts here */
    int n, k;
    cin >> n >> k;

    vector<int> diff;
    int p;
    rep(i, 0, n) {
        cin >> p;
        diff.push_back(p);
    }

    sort(all(diff));

    int sum = diff[0] + diff[1];

    int sum2 = 0;
    rep(i, 2, sz(diff)) {
        sum2 += diff[i];
    }

    diff.erase(diff.begin());
    diff.erase(diff.begin());

    rep(i, 0, sz(diff)) {
        cout << diff[i] << " ";
    }
    debug(sum);
    cout << k_sum(diff, sz(diff), sum);
}
