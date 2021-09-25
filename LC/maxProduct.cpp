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
    int maxProduct(string s) {
        // generate all palindromic subseqs
        // sort subseqs by len
        // for each subseq
        //   if disjoint w other subseq
        //   product is max len
        int n = s.size();
        if (n == 2) return 1;

        vector<vector<int>> subseqs;         

        vector<int> tmp;
        dfs(s, 0, subseqs, tmp); 

        int maxProd = 1;

        for (int i = 0; i < subseqs.size(); i++) {
            for (int j = 0; j < subseqs.size(); j++) {
                if (i == j) continue;

                if (disjoint(subseqs[i], subseqs[j])) {
                    maxProd = max((unsigned long) maxProd, subseqs[i].size() * subseqs[j].size());
                }
            }
        }

        return maxProd;
    }

    bool disjoint(vector<int>& left, vector<int>& right) {
        for (int i : left) {
            for (int j : right) {
                if (i == j) return false;
            }
        }

        return true;
    }

    void dfs(string s, int cur, vector<vector<int>>& subseqs, vector<int>& tmp) {
        if (isPalindrome(tmp, s)) {
            vector<int> new_seq;
            for (int c : tmp) new_seq.push_back(c);
            subseqs.push_back(new_seq);
        }

        for (int i = cur; i < s.size(); i++) {
            tmp.push_back(i);
            dfs(s, i + 1, subseqs, tmp);
            tmp.pop_back();
        }
    }

    bool isPalindrome(vector<int>& tmp, string s) {
        if (tmp.size() == 0) return false;

        int l = 0, r = tmp.size() - 1;

        while (l < r) {
            if (s[tmp[l]]!= s[tmp[r]]) {
                return false;
            }
            l++; r--;
        }
        return true;
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
