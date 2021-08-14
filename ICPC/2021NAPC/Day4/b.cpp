#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define mp(a, b) make_pair(a, b)
#define debug(content) cout << "DEBUG: " << content << endl


typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

vector<bool> visited;
vector<int> soln;
string nums;


bool dfs(int num, int idx) {
    if (num == 0) return false;
    if (idx >= visited.size()) return true;

    if (visited[num - 1]) return false;

    visited[num - 1] = true;
    soln.push_back(num);

    char c1, c2;
    string next;

    if (idx + 1 < sz(nums)) {
        c1 = nums[idx + 1];
        next += c1;
        
        if (dfs(stoi(next), idx + 1) != 1) {
            if (idx + 2 < sz(nums)) {
                c2 = nums[idx + 2];
                next += c2;
                if (dfs(stoi(next), idx + 2) != 1) {
                    soln.pop_back();
                    return false;
                } else {
                    return true;
                }
            }
            return false;
        } else {
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> nums;

    int n;

    if (nums.size() < 10) {
        n = nums.size();
    } else {
        n = ((nums.size() - 9) / 2) + 9;
    }

    visited.resize(n);

    int flag = dfs(nums[0] - '0', 0);

    if (flag == 1) {
       rep(i, 0, sz(soln) - 1) {
           cout << soln[i] << " ";
       }
       cout << endl;
    } else {
        rep(i, 0, sz(visited)) {
            cout << i + 1 << ": " << visited[i] << endl;
        }
    }

}
