#include <iostream>
// #include <vector>
#include <iomanip>
#include <cmath>
#include <string>
#include <map>

using namespace std;

#define ll long long

bool debug_msgs = false;

bool made_of_two(ll& n) {
    map<char, int> char_freq;
    string num_str = to_string(n);
    for (char c : num_str) {
        char_freq[c]++;
        if (char_freq.size() > 2) { return false; }
    }
    return (char_freq.size() <= 2);
}

bool rest_fine(string& num_str) {
    map<char, int> char_freq;
    for (size_t i = 0; i < num_str.size() - 1; ++i) {
        char_freq[num_str[i]]++;
        if (char_freq.size() > 2) { return false; }
    }
    return true;
}

bool rest_is_same(string num_str) {
    for (size_t i = 1; i < num_str.size() - 1; ++i) {
        if (num_str[i] != num_str[0]) { return false; }
    }
    return true;
}

char second_val(string& num_str) {
    char two;
    for (char c : num_str) {
        two = c;
        if (two != num_str[0]) { return two; }
    }
    return num_str[0];
}

int pred(string num_str) {

    if (num_str.size() == 2) {
        if (debug_msgs) { cout << "FIRST" << endl; }
        return ((int)num_str.back() - '0') + 1;
    }

    int last = pred(num_str.substr(0, num_str.size() - 1));

    if (rest_is_same(num_str)) {
        if (debug_msgs) { cout << "SECOND" << endl; }
        return ((2 * (last - 1)) + ((int)num_str.back() - '0') + 1);
    }

    int mod = 0;
    if ((num_str.back() < second_val(num_str)  || num_str.back() < num_str[0]) && rest_fine(num_str)) {
        if (num_str.back() != max(second_val(num_str), num_str[0])) { mod--; }
        if (num_str.back() < min(second_val(num_str), num_str[0])) { mod--; }
        if (num_str[num_str.size() - 2] < num_str[num_str.size() - 3]
            && rest_is_same(num_str.substr(0, num_str.size() - 1))) {
            if (debug_msgs) { cout << "THIRD" << endl; }
            if (debug_msgs) { cout << "mod " << mod << endl; }
            return ((2 * last) + mod);
        }
    }
    if (second_val(num_str) < num_str[0]) {
        if (debug_msgs) { cout << "FOURTH" << endl; }
        if (debug_msgs) { cout << "mod " << mod << endl; }
        return ((2 * last) + mod);
    } else {
        if (debug_msgs) { cout << "FIFTH" << endl; }
        if (debug_msgs) { cout << "mod " << mod << endl; }
        return ((2 * (last - 1)) + 10 + mod);
    }
}

int main() {

    ll n;
    cin >> n;

    cout << fixed << setprecision(0);

    ll count = 0;

    ll i = 1;

    string nums = to_string(n);

    int fcount = 0;
    for (ll j = i; j <= n; ++j) {
        if (made_of_two(j)) {
            count++;
            if (j >= pow(10,floor(log10(n))) * ((int)nums[0] - '0')) {
                if (debug_msgs) { cout << j << endl; }
                fcount++;
            }
        }
    }
    int predic = 0;

    if (n > 10) { predic = pred(to_string(n)); }

    cout << count << endl;
    // if (debug_msgs) {
        cout << "5Count = " << fcount << endl;
    // }
    // if (debug_msgs) {
        cout << "Pred: " << predic << endl;
    // }


    return 0;
}
