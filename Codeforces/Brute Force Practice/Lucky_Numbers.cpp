#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

#define ll long long

int count_freq(string s, char c) {
    int count = 0;
    for (char ch : s) {
        if (ch == c) { count++; }
    }
    return count;
}

bool super_lucky(int n) {
    for (char ch : to_string(n)) {
        if (ch != '4' && ch != '7') { return false; }
    }
    return (count_freq(to_string(n), '4') == count_freq(to_string(n), '7'));
}

void get_lucky(ll& n) {
    int last;
    int first;
    string nums;

    while (!super_lucky(n)) {
        last = stoi(to_string(to_string(n).back())) - '0';
        first = stoi(to_string(to_string(n).front())) - '0';

        if (first < 4 || first > 7) {
            if (first < 4) {
                for (size_t i = 0; i < to_string(n).size(); ++i) {
                    if (i == 0) {
                        n += (4 * pow(10, to_string(n).size() - 1 - i)) - n;
                        if (to_string(n).size() % 2) { n *= 10; }
                    } else {
                        if (i < to_string(n).size() / 2) {
                            n += (4 * pow(10, to_string(n).size() - 1 - i));
                        } else {
                            n += (7 * pow(10, to_string(n).size() - 1 - i));
                        }
                    }
                }
                break;
            } else {
                n += (10 - first) * pow(10, to_string(n).size() - 1);
            }
        } else if (first > 4 && first < 7) {
            if (to_string(n).size() % 2) {
                n += pow(10, to_string(n).size()) - n;
                continue;
            }

            for (size_t i = 0; i < to_string(n).size(); ++i) {
                if (i == 0) {
                    n += (7 * pow(10, to_string(n).size() - 1)) - n;
                } else {
                    if (i <= to_string(n).size() / 2) {
                        n += (4 * pow(10, to_string(n).size() - 1 - i));
                    } else {
                        n += (7 * pow(10, to_string(n).size() - 1 - i));
                    }
                }
            }
        } else if (first == 7) {
            if (to_string(n).size() % 2) {
                n += pow(10, to_string(n).size()) - n;
                continue;
            }
            nums = to_string(n);
            for (size_t i = 1; i < nums.size(); ++i) {
                if (i <= nums.size() / 2) {
                    if (nums[i] < '4') {
                        nums[i] = '4';
                        if (i == 1 && nums[i + 1] < '4') {
                            for (size_t j = i + 1; j < nums.size(); ++j) {
                                nums[j] = '0';
                            }
                        }
                        n = stoi(nums);
                    } else if (nums[i] < '7' && nums[i] > '4') {
                        nums[i] = '7';
                        n = stoi(nums);
                    } else if (nums[i] >= '7') {
                        size_t k;
                        for (k = i + 1; k < nums.size(); ++k) {
                            if (nums[k] < '7') {
                                break;
                            }
                        }
                        if (k == nums.size()) { n += 8 * pow(10, nums.size() - 1) - n; }
                    }
                }
            }
        } else if (first == 4) {
            if (to_string(n).size() % 2) {
                n += pow(10, to_string(n).size()) - n;
                continue;
            }
            nums = to_string(n);
            if (nums[1] > '7') {
                n += 5 * pow(10, nums.size() - 1) - n;
            } else {
                for (size_t i = 1; i < nums.size(); ++i) {
                    if (i < nums.size() / 2) {
                        if (nums[i] > '4' && nums[i] < '7') {
                            nums[i] = '7';
                            for (size_t j = i + 1; j < nums.size(); ++j) {
                                nums[j] = '0';
                            }
                        } else if (nums[i] < '4') {
                            nums[i] = '4';
                        }
                    }
                }
                n = stoi(nums);
            }
        }

        if (super_lucky(n)) { break; }
        if (last == 4) { n += 3; }
        else if (last == 7) { n += 7; }
        else { n++; }
    }
}

int main() {
    ll n;
    cin >> n;

    cout << fixed << setprecision(0);

    if (super_lucky(n)) { cout << n << endl; return 0; }

    get_lucky(n);

    cout << n << endl;

    return 0;
}
