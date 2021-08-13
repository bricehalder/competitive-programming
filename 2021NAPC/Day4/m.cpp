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

int m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    int n;

    cin >> n >> m;

    priority_queue<int, vi, greater<int>> pq;

    vector<pii> times(n);

    rep(i, 0, n) {
        cin >> times[i].first >> times[i].second;
    }

    sort(all(times));
    int saved = 0;

    for (auto& [a, s] : times) {
        while (!pq.empty() && pq.top() + m < a) {
            pq.pop();
        }

        if (!pq.empty() && pq.top() <= a) {
            pq.pop();
            saved++;
            // debug("a:" << a << " s:" << s);
        }

        pq.push(a + s);
    }

    cout << saved << endl;

}
