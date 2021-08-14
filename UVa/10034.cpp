#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define mp make_pair
#define debug(content) if (DEBUG_MODE) cout << "DEBUG: " << content << endl
#define DEBUG_MODE 1
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

struct union_find {
    // When data[x] < 0, x is a root and -data[x] is its tree size. When data[x] >= 0, data[x] is x's parent.
    vector<int> data;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        data.assign(n + 1, -1);
        components = n;
    }

    int find(pdd x) {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }

    int get_size(int x) {
        return -data[find(x)];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (-data[x] < -data[y])
            swap(x, y);

        data[x] += data[y];
        data[y] = x;
        components--;
        return true;
    }
};

template<typename T_edge>
struct kruskal {
    struct edge {
        pdd a, b;
        T_edge weight;
        int index = -1;
        bool in_tree = false;

        edge() {}

        edge(pdd _a, pdd _b, T_edge _weight, int _index = -1) : a(_a), b(_b), weight(_weight), index(_index) {}

        bool operator<(const edge &other) const {
            return weight < other.weight;
        }
    };

    union_find UF;
    vector<edge> edges;
    vector<bool> original_in_tree;

    kruskal(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        UF.init(n);
        edges = {};
    }

    void add_edge(pdd a, pdd b, T_edge weight) {
        edges.emplace_back(a, b, weight, edges.size());
        original_in_tree.push_back(false);
    }

    template<typename T_sum>
    T_sum solve() {
        sort(edges.begin(), edges.end());
        T_sum total = 0;

        for (edge &e : edges)
            if (UF.unite(e.a, e.b)) {
                total += e.weight;
                e.in_tree = true;
                original_in_tree[e.index] = true;
            }

        return total;
    }
};

double dist(pdd x, pdd y) {
    return sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    cout << fixed << setprecision(2);

    rep(i, 0, n) {
        if (i > 0) {
            cout << endl;
        }

        int v;
        cin >> v;

        if (v <= 1) cout << 0 << endl; continue;

        vector<pdd> vtcs(v);
        
        rep(j, 0, v) {
            cin >> vtcs[j].first >> vtcs[j].second;
        }

        kruskal<double> k(v);

        rep(a, 0, v) {
            rep(b, 0, v) {
                k.add_edge(vtcs[a], vtcs[b], dist(vtcs[a], vtcs[b]));
            }
        }
        
        cout << k.solve<double>() << endl;
    }
    
}
