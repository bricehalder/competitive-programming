#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

/* Compile:  g++ -std=c++11 -O2 -Wall template.cpp -o template */

bool isPrime(ll x) {
    for (ll d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> input;
    string in;
    while (cin >> in) {
        input.push_back(in);

        if (input.size() > 3) {
            cout << 0 << endl;;
            return 0;
        }
    }

    if (input.size() < 3) {
        cout << 0 << endl;
        return 0;
    }

    string s1, s2, s3;
    s1 = input[0];
    s2 = input[1];
    s3 = input[2];

    size_t found1 = s1.find('+');
    size_t found2 = s2.find('+');
    size_t found3 = s3.find('+');

    if (found1 != string::npos || found2 != string::npos || found3 != string::npos) {
        cout << 0 << endl;
        return 0;
    }

    found1 = s1.find('-');
    found2 = s2.find('-');
    found3 = s3.find('-');

    if (found1 != string::npos || found2 != string::npos || found3 != string::npos) {
        cout << 0 << endl;
        return 0;
    }

    ll one, two, three;

    try {
        one = stoll(s1);
        two = stoll(s2);
        three = stoll(s3);
    } catch (exception& e) {
        cout << 0 << endl;
        return 0;
    }

    string new_s1 = to_string(one);
    string new_s2 = to_string(two);
    string new_s3 = to_string(three);

    if (s1 != new_s1 || s2 != new_s2 || s3 != new_s3) {
        cout << 0 << endl;
        return 0;
    }

    if (one % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    if (one <= 3 || one > 1000000000) {
        cout << 0 << endl;
        return 0;
    }

    if (two < 1 || three < 1) {
        cout << 0 << endl;
        return 0;
    }

    if (!isPrime(two) || !isPrime(three)) {
        cout << 0 << endl;
        return 0;
    }

    if (two + three != one) {
        cout << 0 << endl;
        return 0;
    }

    cout << 1 << endl;
    return 0;  
}