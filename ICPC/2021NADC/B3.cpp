#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> iPair;

vector<int> compute_pi(string pat) {
  int n = pat.length();
  vector<int> pi(n);
  pi[0] = 0;
  for (int i = 1; i < n; i++) {
    pi[i] = 0;
    int j = pi[i - 1]; /* trying length j + 1 */
    while (j > 0 && pat[j] != pat[i]) {
      j = pi[j - 1];
    }
    if (pat[j] == pat[i]) {
      pi[i] = j + 1;
    }
  }
  return pi;
}

vector<int> find_matches(string text, string pat, int stop) {
  int n = pat.length(), m = text.length();
  string s = pat + "$" + text;
  vector<int> pi = compute_pi(s), ans;
  for (int i = n + 1; i <= n + m; i++) { /* n + 1 is where the text starts */
    if (pi[i] == n) {
      ans.push_back(i - 2 * n); /* i - (n - 1) - (n + 1) */

      // STOP WHEN REACH KTH OCCURENCE
      if (ans.size() == stop) {
        return ans;
      }
    }
  }
 return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    ll q;

    cin >> s;
    cin >> q;

    vector<int> pi = compute_pi(s);

    string t;
    ll k;

    map<string, vector<int>> occurences;

    for (int i = 0; i < q; i++) {
        cin >> t;
        cin >> k;

        // DONT CARE ABOUT THESE
        if (t.length() > s.length()) {
          cout << -1 << endl;
          continue;
        }

        // CACHE SUBSTRINGS
        if (occurences.find(t) != occurences.end()) {
          if (occurences[t].empty() || occurences[t].size() > k) {
              cout << -1 << endl;
          } else {
              cout << occurences[t][k - 1] + 1 << endl;
          }
          continue;
        }

        vector<int> occ = find_matches(s, t, k);
        occurences.insert(make_pair(t, occ));

        if (occ.empty()) {
            cout << -1 << endl;
        } else {
            cout << occ[k - 1] + 1<< endl;
        }
    }

    return 0;
}

