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
    // linear scan O(MN)
    // two pass horz/vert
    // sliding window of size word
    // start from right -> left
    // if any of the cells blocked, move left to right + 1
    // if any of the cells have letter not in correct spot move
    // check l/r or above/below
    vector<vector<char>> board;

    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        this->board = board;

        if (checkLR(word))
            return true;

        string copy = word;
        reverse(begin(copy), end(copy));

        if (checkLR(copy))
            return true;

        if (checkUD(word))
            return true;

        if (checkUD(copy))
            return true;    

        return false;        
    }

    bool checkLR(string word) {
        int row = 0;
        int left = 0;
        int right = word.size() - 1;

        vector<vector<bool>> dp(board.size(), vector<bool>(board[0].size(), false));

        while (row < board.size()) {
            while (right < board[0].size()) {
                bool good = true;
                for (int i = right; i >= left; i--) {
                    if (dp[row][i]]) continue;

                    char& c = board[row][i];

                    if (c == '#' || (c != ' ' && c != word[right - left])) {
                        left = right + 1;
                        good = false;
                        break;
                    }

                    dp[row][i] = true;
                }

                if (left - 1 >= 0) {
                    if (board[row][left - 1] != '#')
                        good = false;
                }

                if (right + 1 < board[0].size()) {
                    if (board[row][right + 1] != '#')
                        good = false;
                }

                if (good) return true;
            }

            row++;
        }

        return false;
    }

     bool checkUD(string word) {
        int col = 0;
        int up = 0;
        int down = word.size() - 1;

        vector<vector<bool>> dp(board.size(), vector<bool>(board[0].size(), false));

        while (col < board[0].size()) {
            while (down < board.size()) {
                bool good = true;
                for (int i = down; i >= up; i--) {
                    if (dp[i][col]]) continue;

                    char& c = board[i][col];

                    if (c == '#' || (c != ' ' && c != word[down - up])) {
                        up = down + 1;
                        good = false;
                        break;
                    }

                    dp[i][col] = true;
                }

                if (up - 1 >= 0) {
                    if (board[up - 1][col] != '#')
                        good = false;
                }

                if (down + 1 < board.size()) {
                    if (board[down + 1][col] != '#')
                        good = false;
                }

                if (good) return true;
            }

            col++;
        }

        return false;
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
