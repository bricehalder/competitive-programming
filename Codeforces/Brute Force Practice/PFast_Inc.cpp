#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template<typename T>
void get_all_comb(vector<T>& vec, int r, vector<vector<T>>& h) {
    int n = vec.size();

    vector<bool> v(n);
    fill(v.end() - r, v.end(), true);

    do {
        vector<T> to_push;
        for (int i = 0; i < n; ++i) {
            if (v[i]) {
                to_push.push_back(vec[i]);
            }
        }
        h.push_back(to_push);
    } while (next_permutation(v.begin(), v.end()));
}

int main() {
    int n, m;
    int bad_count;
    int num;
    cin >> n >> m;

    vector<string> names;
    vector<pair<string, string>> incomp;
    vector<string> solns;

    string input;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        names.push_back(input);
    }

    string input2;
    for (int i = 0; i < m; ++i) {
        cin >> input >> input2;
        incomp.push_back(make_pair(input, input2));
    }

    if (m == 0) {
        cout << n;
        cout << endl;
        sort(names.begin(), names.end());
        for (vector<string>::iterator it = names.begin(); it != names.end(); ++it) {
            cout << *it << endl;
        }
        return 0;

    } else {

        bool done = false;
        for (int i = n; i > 0; --i) {
            vector<vector<string>> poss;
            get_all_comb(names, i, poss);
            for (vector<vector<string>>::iterator it = poss.begin(); it != poss.end(); ++it) {
                if (!done) {
                    bad_count = 0;
                    for (pair<string, string> p : incomp) {
                        if (!(find(it->begin(), it->end(), p.first) != it->end() && find(it->begin(), it->end(), p.second) != it->end())) {
                            num = it->size();
                        } else {
                            bad_count++;
                        }
                    }
                    if (bad_count == 0) {
                        for (string n : *it) {
                            solns.push_back(n);
                        }
                        done = true;
                    }
                }
            }
        }
        cout << num << endl;
        sort(solns.begin(), solns.end());
        for (string n : solns) { cout << n << endl; }
    }

    return 0;
}
