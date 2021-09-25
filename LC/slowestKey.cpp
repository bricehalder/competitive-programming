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
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        map<char, int> durs;
         
        durs[keysPressed[0]] = releaseTimes[0];
        int max_amt = durs[keysPressed[0]];
        char ret = keysPressed[0];
        
        for (int i = 1; i < keysPressed.size(); i++) {
           durs[keysPressed[i]] =  max(durs[keysPressed[i]], releaseTimes[i] - releaseTimes[i - 1]); 

           if (durs[keysPressed[i]] > max_amt) {
               max_amt = durs[keysPressed[i]];
               ret = keysPressed[i];
           } else if (durs[keysPressed[i]] == max_amt) {
               if (keysPressed[i] > ret) {
                   ret = keysPressed[i];
               }
           }
        }
        
        for (auto it = durs.begin(); it != durs.end(); it++) {
            cout << it->first << " " << it->second << endl;
        }
        
        
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
