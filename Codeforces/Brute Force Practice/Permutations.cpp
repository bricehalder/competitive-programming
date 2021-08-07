#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template<typename T>
void get_all_perms(vector<T>& vec, vector<vector<T>>& h) {
    do {
        vector<T> to_push;
        for (size_t i = 0; i < vec.size(); ++i) {
            to_push.push_back(vec[i]);
        }
        h.push_back(to_push);
    } while (next_permutation(vec.begin(), vec.end()));
}

// template<typename T>
// ostream& operator<<(ostream& os, const vector<T>& vec) {
// 	for(typename vector<T>::const_iterator it = vec.cbegin();
// 		it != vec.cend(); ++it)
// 	{
// 		os << *it << ' ';
// 	}
// 	return os;
// }

int max(vector<int>& v) {
    int max = v[0];
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] > max) { max = v[i]; }
    }
    return max;
}

int min(vector<int>& v) {
    int min = v[0];
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] < min) { min = v[i]; }
    }
    return min;
}

vector<int> strv_to_intv(vector<string>& v) {
    vector<int> new_v;
    for (size_t i = 0; i < v.size(); ++i) {
        new_v.push_back(stoi(v[i]));
    }
    return new_v;
}

int s_max(vector<string>& v) {
    vector<int> v_int = strv_to_intv(v);
    return max(v_int);
}

int s_min(vector<string>& v) {
    vector<int> v_int = strv_to_intv(v);
    return min(v_int);
}

string apply_perm(string& num, vector<int>& permutation) {
    string new_num;
    for (int i : permutation) {
        new_num += num[i];
    }
    return new_num;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> orig_list;
    vector<string> num_list;

    string input;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        orig_list.push_back(input);
    }

    int curr_min = s_max(orig_list) - s_min(orig_list);
    int temp_min = curr_min;

    vector<vector<int>> poss;
    vector<int> range_k;

    for (int i = 0; i < k; ++i) {
        range_k.push_back(i);
    }

    get_all_perms(range_k, poss);

    for (vector<int> permutation : poss) {
        num_list = orig_list;
        for (size_t i = 0; i < num_list.size(); ++i) {
            num_list[i] = apply_perm(num_list[i], permutation);
        }
        // cout << num_list << endl;
        temp_min = s_max(num_list) - s_min(num_list);
        if (temp_min < curr_min) {
            curr_min = temp_min;
        }
    }

    cout << curr_min << endl;

    return 0;
}
