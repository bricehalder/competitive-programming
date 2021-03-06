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

vector<int> adj[N]; // Unweighted
bool visited[N];

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    // process node s
    for (auto u: adj[s]) {
        dfs(u);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r, b, y;
    // solution comes here
    cin >> n, m, r, b, y;
}