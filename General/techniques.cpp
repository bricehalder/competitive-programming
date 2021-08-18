#include <bits/stdc++.h>

using namespace std;

typedef vector<int>        vi;
typedef vector< vi >       vvi;
typedef pair<int, int>     pii;
typedef vector< pii >      vii;
 
typedef vector< bool >     vb;
typedef vector< vb >       vvb;
 
typedef long long          ll;
typedef vector<ll>         vl;
typedef vector< vl >       vvl;
typedef pair<ll, ll>       pll;
typedef vector< pll >      vll;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
#define mp make_pair
#define debug(content) if (DEBUG_MODE) cout << "DEBUG: " << content << endl
#define DEBUG_MODE 1
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)

queue<int> q;
vector<int> adj[N]; // Unweighted
vector<pair<int,int>> adj2[N]; // Weighted
bool visited[N];

/* Comparison operator overlord for sort() */
struct P {
    int x, y;
    bool operator<(const P &p) {
        if (x != p.x) return x < p.x;
        else return y < p.y;
    }
};

/* Compile:  g++ -std=c++11 -O2 -Wall techniques.cpp -o techniques */

void search(int i) { return; }

int main() {
    /* File I/O if needed */
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout << fixed << setprecision(0);

    ios::sync_with_stdio(0);
    cin.tie(0);

    /* Basic input  */
    int a, b;
    string x;
    cin >> a >> b >> x;

    /* scanf and printf a little bit faster than cin/cout */
    int a, b;
    scanf("%d %d", &a, &b);

    int a = 123, b = 456;
    printf("%d %d\n", a, b);

    string s;
    getline(cin, s);

    /* Unknown amount of data */
    while (cin >> x) {
        // code
    }









    /* Graphs */
    int N = 10;

    int s = 5;
    for (auto u : adj[s] {
    // process node u
    }
    // solution comes here


    void dfs(int u) { // DFS for normal usage
        printf(" %d", u); visited[u] = 1; // this vertex is visited, mark it
        TRvii (AdjList[u], v) { // try all neighbors v of vertex u
            if (visited[v->first] == 0) // avoid cycle
                dfs(v->first); // v is a (neighbor, weight) pair
        }
    }

    void dfs(int s) {
        if (visited[s]) return;
        visited[s] = true;
        // process node s
        for (auto u: adj[s]) {
            dfs(u);
        }
    }

    void bfs(int x) {
        visited[x] = true;
        distance[x] = 0;
        q.push(x);
        while (!q.empty()) {
            int s = q.front(); q.pop();
            // process node s
            for (auto u : adj[s]) {
                if (visited[u]) continue;
                visited[u] = true;
                distance[u] = distance[s]+1;
                q.push(u);
            }
        }
    }

    queue<int> q; map<int, int> dist;
    q.push(s); dist[s] = 0; // start from source

    while (!q.empty()) {
        int u = q.front();
        q.pop(); // queue: layer by layer!
        printf("Visit %d, Layer %d\n", u, dist[u]);
        TRvii(AdjList[u], v) // for each neighbours of u
        if (!dist.count(v->first)) {                                 // dist.find(v) != dist.end() also works
            dist[v->first] = dist[u] + 1; // if v not visited before + reachable from u
            q.push(v->first);             // enqueue v for next steps
        }    
    }







    // binary search
    bool search(int x[], int n, int k) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (x[mid] >= k) r = mid; 
        else l = mid + 1;
    }
        return x[l] == k;
    }

















    /* Combinatorics */

    //generate n choose k table using DP for later use
    vvl nck(21, vl(21, 0));
    for (int i = 0; i <= 20; i++) {
        nck[i][0] = 1;
    }
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= i; j++) {
            nck[i][j] = nck[i-1][j-1] + nck[i-1][j];
        }
    }
}