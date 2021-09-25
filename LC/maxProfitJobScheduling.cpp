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
    // dp[i] = max profit at time i
    // sort by start time
    // if i != end time
    //      dp[i] = dp[i - 1]

    // if i is endTime
    //    dp[i] = max(dp[i - 1], dp[start(i)] + profit[i]

    // O(max_time)

    // use hash map for end time to job look up

    struct job {
        int start, end;
        int profit;

        bool operator< (const job& o) {
            return start < o.start || start == o.start && end < o.end;
        }
    };
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<job> jobs;
        map<int, vector<job>> end_jobs;
        
        int max_time = 0;

        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
            end_jobs[endTime[i]].push_back(jobs.back());
            max_time = max(max_time, endTime[i]);
        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(max_time + 1);

        for (int i = 1; i <= max_time; i++) {
            if (end_jobs.find(i) == end_jobs.end()) {
                dp[i] = dp[i - 1];
                continue;
            }

            for (auto& j : end_jobs[i]) {
                dp[j.end] = max(dp[j.end], max(dp[j.end - 1], dp[j.start] + j.profit));
            }
        }

        return dp[max_time];

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