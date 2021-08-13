#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    int cases;

    cin >> cases;

    int n, m;

    rep(i, 0, cases) {
        cin >> n >> m;

        deque<int> movies(n);
        unordered_map<int, void *> pos(n);

        rep(i, 0, sz(movies)) {
            movies.push_back(i);
            pos[n - i] = &movies[0] + i;
        }

        int a;
        rep(i, 0, m) {
            cin >> a;

            auto it = pos[a];

            cout << (int *)it - &movies[0] << " ";

            movies.push_front(a);
            pos[a] = &movies[0];
        }
        cout << endl;

        movies.clear();
        pos.clear();
    }

}
