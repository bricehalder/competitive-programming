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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c;
    vector<int> nums;
    // solution comes here
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c;
        nums.push_back(c);
    }

    sort(nums.begin(), nums.end());

    int cur = nums[0];
    
    int total = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1] + 1) {
            total += cur;
            cur = nums[i];
        }
    }
    
    total += cur;
    cout << total << endl;

}