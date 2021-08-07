#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

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
        return ((int)num_str.back() - '0') + 1;
    }

    int last = pred(num_str.substr(0, num_str.size() - 1));

    if (rest_is_same(num_str)) {
        return ((2 * (last - 1)) + ((int)num_str.back() - '0') + 1);
    }

    int mod = 0;
    if ((num_str.back() < second_val(num_str)  || num_str.back() < num_str[0]) && rest_fine(num_str)) {
        if (num_str.back() != max(second_val(num_str), num_str[0])) { mod--; }
        if (num_str.back() < min(second_val(num_str), num_str[0])) { mod--; }
        if (num_str[num_str.size() - 2] < num_str[num_str.size() - 3]
            && rest_is_same(num_str.substr(0, num_str.size() - 1))) {
            return ((2 * last) + mod);
        }
    }
    if (second_val(num_str) < num_str[0]) {
        return ((2 * last) + mod);
    } else {
        return ((2 * (last - 1)) + 10 + mod);
    }
}

int main() {

    ll n;
    cin >> n;

    cout << fixed << setprecision(0);

    ll count = 0;

    ll base, j;

    for (ll w = 10; w <= n; w *= 10) {
        base = floor(log10(w));
        count += 9 * (pow(2, base - 1) + ((pow(2, base - 1) - 1) * 8));
    }

    j = n / pow(10, base);
    count += (j - 1) * (pow(2, base) + ((pow(2, base) - 1) * 8));

    int predic = 0;

    if (n > 10) {
        predic = pred(to_string(n));
        cout << (count + predic)<< endl;
    }
    else { cout << n << endl; }

    return 0;
}
