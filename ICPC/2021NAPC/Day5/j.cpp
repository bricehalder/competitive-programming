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

    int n;
    cin >> n;

    map<char, map<char, int>> m;

    int non_vax = 0;
    string person;
    rep(i, 0, n) {
        cin >> person;
        char key = person[0];
        if (key == 'N') non_vax++;
        m[key]['A'] += person[1] == 'Y' ? 1 : 0;
        m[key]['B'] += person[2] == 'Y' ? 1 : 0;
        m[key]['C'] += person[3] == 'Y' ? 1 : 0;

    }

    int vax = n - non_vax;

    double vax_AInfected = (double) m['Y']['A'] / vax;
    double vax_BInfected = (double) m['Y']['B'] / vax;
    double vax_CInfected = (double) m['Y']['C'] / vax;

    double non_vax_AInfected = (double) m['N']['A'] / non_vax;
    double non_vax_BInfected = (double) m['N']['B'] / non_vax;
    double non_vax_CInfected = (double) m['N']['C'] / non_vax;

    double aEff = (1.0 - (vax_AInfected / non_vax_AInfected)) * 100;
    double bEff = (1.0 - (vax_BInfected / non_vax_BInfected)) * 100;
    double cEff = (1.0 - (vax_CInfected / non_vax_CInfected)) * 100;

    cout.precision(6);

    if (aEff <= 0) {
        cout << "Not Effective" << endl;
    } else {
        cout << fixed << aEff << endl;
    }

    if (bEff <= 0) {
        cout << "Not Effective" << endl;
    } else {
        cout << fixed << bEff << endl;
    }

    if (cEff <= 0) {
        cout << "Not Effective" << endl;
    } else {
        cout << fixed << cEff << endl;
    }

}
