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

    int n, m;
    cin >> n >> m;


    map<int, int> msg;
    
    int s;
    int unread = 0;
    rep(i, 0, m) {
        cin >> s;

        unread += n - 1;
        
        msg[s] = 0;

    }
}
