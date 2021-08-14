#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define mp make_pair
#define debug(content) if (DEBUG_MODE) cout << "DEBUG: " << content << endl
#define DEBUG_MODE 1

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    int n, k;
    cin >> n >> k;

    vector<int> scores(k);
    vector<vi> problems(k);

    string s;
    rep(i, 0, n) {
        cin >> s;
        rep(j, 0, k) {
            problems[j].push_back(s[j]);
        }
    }

    vector<char> max_diff(k);
    rep(i, 0, k) {
        int ts = 0, fs = 0;
        rep(j, 0, n) {
            if (problems[i][j] == 'T') {
                ts++;
            } else {
                fs++;
            }
        }

        max_diff[i] = ts > fs ? 'T' : 'F';

    }

    // debug("max_diff: ");
    // rep(i, 0, sz(max_diff)) {
    //     debug(max_diff[i]);
    // }

    int min_ans = INT_MAX;

    rep(i, 0, n) {
        int score = 0;
        rep(j, 0, k) {
            if (problems[j][i] == max_diff[j]) score++;
        }
        if (score < min_ans) min_ans = score;
    }

    cout << min_ans << endl;

   
}
