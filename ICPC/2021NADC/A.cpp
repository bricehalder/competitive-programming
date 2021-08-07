#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

/* Compile:  g++ -std=c++11 -O2 -Wall template.cpp -o template */

int n;    
vector<int> limits;

bool is_valid_time(string time) {
    if (time.length() != n * 2) {
        int num_zeros = (n * 2) - time.length();
        time = string(num_zeros, '0').append(time);
    }

    for (int i = 1; i < time.length(); i += 2) {
        int num = stoi(time.substr(i - 1, 2));
        cout << num << endl;
        if (num >= limits[i - 1]) {
            return false;
        }
    }
    return true;
}

bool is_error_prone(string cooking_time) {
    for (int i = 0; i < cooking_time.length(); i++) {
        string omit_one = cooking_time;
        omit_one.erase(i);
        if (!is_valid_time(omit_one)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ti;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ti;
        limits.push_back(ti);
    }
    
    for (int i = 0; i < limits.size(); i++) {
        for (int j = 0; j < limits[i]; j++) {
            
        }
    }

}