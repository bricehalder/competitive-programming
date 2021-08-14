#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define mp make_pair
#define debug(content) cout << "DEBUG: " << content << endl

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

// Returns maximum sum in a subarray of size k.
pii maxSum(vi arr, int n, int k)
{
    // k must be greater
    if (n < k)
    {
       cout << "Invalid";
       return -1;
    }
 
    // Compute sum of first window of size k
    int res = 0;
    for (int i=0; i<k; i++)
       res += arr[i];


    // Compute sums of remaining windows by
    // removing first element of previous
    // window and adding last element of
    // current window.
    int curr_sum = res;
    for (int i=k; i<n; i++)
    {
       curr_sum += arr[i] - arr[i-k];
       res = max(res, curr_sum);
    }
 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    int n, m, k;

    cin >> n >> m >> k;
    vi buildings(m + 1);
    vi days(n);

    priority_queue<int, vector<int>, greater<int>> pq;

    int b;

    int used = 0;

    

    rep(i, 0, n) {
        cin >> b;
        if (buildings[b] + 1 >= floor(n / k) && used < k) {
            // debug("i: " << i << " b: " << b << " buildings[b]: " << buildings[b] << " used: " << used << " floor: " << floor(n/k));
            buildings[b] = 1;
            used++;
        } else {
            buildings[b]++;
        }

        days[i] = buildings[b];
    }

    int sum = 0;

    for (auto& n : days) {
        sum += n;
    }
    // cout << sum << endl;

    used = 0;
    
    vi buildings2(m + 1);
    vi days2(n);

        rep(i, 0, n) {
        if (buildings2[b] + 1 >= ceil((double) n / k) && used < k) {
            // debug("i: " << i << " b: " << b << " buildings[b]: " << buildings[b] << " used: " << used << " floor: " << floor(n/k));
            buildings2[b] = 1;
            used++;
        } else {
            buildings2[b]++;
        }

        days2[i] = buildings2[b];
    }

    int sum2 = 0;

    for (auto& n : days2) {
        sum2 += n;
    }



    maxSum(days, days.size(), k);


    cout << min(sum, sum2) << endl;

    // for (auto& n : days) {
    //     cout << n << " ";
    // }
}
