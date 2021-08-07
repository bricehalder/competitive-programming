#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<vector<int>> Graph;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    for(typename vector<T>::const_iterator it = vec.cbegin();
    it != vec.cend(); ++it)
    {
        os << *it << ' ';
    }
    return os;
}

void initialize(Graph& adj, int nodes) {
    for (int i = 1; i <= nodes + 1; ++i) {
        vector<int> vec;
        adj.push_back(vec);
    }
}

void dfs(Graph& graph, int source, vector<bool>& visited,
    Graph& comp) {

    visited[source] = true;
    comp[source] = graph[source];

    for (size_t i = 0; i < graph[source].size(); ++i) {
        if (!visited[graph[source][i]]) {
            dfs(graph, graph[source][i], visited, comp);
        }
    }
}

void bfs(Graph& graph, int source, vector<bool>& visited,
    vector<int>& level) {
        queue<int> q;
        q.push(source);
        level[source - 1] = 0;

        visited[source] = true;
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (size_t i = 0; i < graph[v].size(); ++i) {
                int neighbor = graph[v][i];
                if (!visited[neighbor]) {
                    level[neighbor - 1] = level[v - 1] + 1;
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
}

int least_adj(Graph& adj, int size) {
    int least = size;
    for (int i = 1; i <= size; ++i) {
        if (adj[i].size() < adj[least].size()) {
            least = (int) i;
        }
    }
    return least;
}

int min_index(vector<Graph>& arr) {
    int min_index = 0;
    int min_size = arr[0].size();

    for (size_t i = 0; i < arr.size(); ++i) {
        int count = 0;
        for (size_t j = 0; j < arr[i].size(); ++j) {
            if (!arr[i][j].empty()) {
                count++;
            }
        }
        if (count < min_size) {
            min_size = count;
            min_index = i;
        }
    }
    return min_index;
}

void plus_true(vector<bool>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (!arr[i]) {
            arr[i] = true;
            return;
        }
    }
}

void shade(vector<bool>& arr, Graph& graph) {
    int count = 0;
    for (size_t i = 0; i < graph.size(); ++i) {
        if (graph[i].size() == 0) {
            continue;
        }
        count++;
        arr[i - 1] = true;
    }
    if (count == 0) {
        plus_true(arr);
    }
}

template<typename T>
int min(vector<T>& v) {
    T min = v[0];
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] < min) { min = v[i]; }
    }
    return min;
}

template<typename T>
int max(vector<T>& v) {
    T max = v[0];
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] > max) { max = v[i]; }
    }
    return max;
}

void shade(vector<bool>& arr, int i, Graph graph) {
    arr[i] = true;
    for (size_t j = 0; j < graph[i].size(); ++j) {
        int neighbor = graph[i][j];
        arr[neighbor] = true;
    }
}

bool try_shade(vector<bool> arr, int i, Graph graph) {
    shade(arr, i, graph);
    return (min(arr) == 0);
}

bool empty(Graph& graph) {
    for (vector<int> v : graph) {
        if (v.size() > 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int nodes, edges;
    int connected = 0;
    Graph adj;

    cin >> nodes >> edges;

    vector<bool> police (nodes, false);
    vector<bool> visited (nodes, false);

    initialize(adj, nodes);

    int x, y;

    for (int i = 1; i <= edges; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<Graph> components;

    for (int i = 1; i <= nodes; ++i) {
        if (!visited[i]) {
            Graph comp;
            initialize(comp, nodes + 1);

            dfs(adj, i, visited, comp);
            components.push_back(comp);

            connected++;
        }
    }

    int c = min_index(components);

    if (components.size() > 1) {
        for (int i = 0; i < (int) components.size(); ++i) {
            if (i != c) {
                shade(police, components[i]);
            }
        }
    }

    int least = least_adj(components[c], adj.size() - 1);

    vector<bool> visitedbfs (nodes, false);
    vector<int> level (nodes, 0);


    bfs(components[c], least, visitedbfs, level);

    for (size_t i = 0; i < level.size(); ++i) {
        if (level[i] >= 2) {
            police[i] = true;
        }
    }

    cout << police << endl;
}
