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
    int minSessions(vector<int>& tasks, int sessionTime) {
        if (tasks.size() == 1) {
            return 1;
        }

        sort(tasks.begin(), tasks.end(), greater<int>());
        
        int count = 1;
        
        int cur_session = 0;

        int sum = 0;

        for (int i = 0 ; i < tasks.size(); i++) {
            sum += tasks[i];
        }

        vector<bool> worked(tasks.size());

        int smallest = tasks.size() - 1;

        for (int i = 0; i < tasks.size(); i++) {
            if (worked[i]) continue;

            if (cur_session + tasks[i] <= sessionTime) {
                cur_session += tasks[i];
                worked[i] = true;
            } else {
                for (int j = tasks.size() - 1; j > i; j--) {
                    if (worked[j]) continue;

                    if (cur_session + tasks[j] <= sessionTime) {
                        cur_session += tasks[j];
                        tasks[j] = true;
                    }
                }

                count++;
                cur_session = 0;
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
