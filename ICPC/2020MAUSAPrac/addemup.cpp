#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

/* Compile:  g++ -std=c++11 -O2 -Wall template.cpp -o template */

void search(int i) { return; }

int flipNum(int num) {
    string s_num = to_string(num);
    string new_num = "";

    for (int i = s_num.size() - 1; i >= 0; i--) {
        switch(s_num[i]) {
            case '0': new_num.PB('0'); break;
            case '1': new_num.PB('1'); break;
            case '2': new_num.PB('2'); break;
            case '3': 
            case '4':
                return -1;
            case '5': new_num.PB('5'); break;
            case '6': new_num.PB('9'); break;
            case '7': return -1;
            case '8': new_num.PB('8'); break;
            case '9': new_num.PB('6'); break;
        }
    }

    return stoi(new_num);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // solution comes here
    int n, target;
    scanf("%d %d", &n, &target);

    map<int, set<int>> cards;

    int num, flip;
    for (int i = 0; i < n; i++) {
        cin >> num;
        
        flip = flipNum(num);
        cards[num].insert(i);
        if (flip != -1) {
            cards[flip].insert(i);
        }
    }

    int diff;
    for (auto cs : cards) {
        diff = target - cs.first;
        if (cards.count(diff) > 0) {
            int numCard = *cs.second.begin();
            int diffCard = *cards[diff].begin();
            if (numCard != diffCard) {
                cout << "YES" << endl; return 0;
            } else if (cs.second.size() > 1 || cards[diff].size() > 1) {
                cout << "YES" << endl; return 0;
            }
        }
    }

    cout << "NO" << endl;
}

