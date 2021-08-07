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

void print_list(Graph& adj, int size) {
    for (int i = 1; i < size; ++i) {
        cout << "Node " << i << ": ";
        if (adj[i].size() == 0) {
            cout << endl;
            continue;
        }
        for (size_t j = 0; j < adj[i].size(); ++j) {
            if (j == adj[i].size() - 1) {
                cout << adj[i][j] << endl;
                continue;
            }
            cout << adj[i][j] << " --> ";
        }
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
    // cout << "Now shading: " << graph[i] << endl;
    // cout << "graph[" << i << "].size() = " << graph[i].size() << endl;
    for (size_t j = 0; j < graph[i].size(); ++j) {
        int neighbor = graph[i][j];
        // cout << "neighbor = " << neighbor << endl;
        arr[neighbor] = true;
    }
    // cout << "Current status: " << arr << endl;
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

    // print_list(adj, adj.size());

    vector<Graph> components;

    // Find components using one DFS on whole graph
    for (int i = 1; i <= nodes; ++i) {
        if (!visited[i]) {
            Graph comp;
            initialize(comp, nodes + 1);

            dfs(adj, i, visited, comp);
            components.push_back(comp);

            connected++;
        }
    }

    // Finding the smallest component
    int c = min_index(components);
    // cout << "min index is: " << c << endl;

    // If more than one component, shade in all the nodes except
    // for the nodes in the smallest component
    if (components.size() > 1) {
        for (int i = 0; i < (int) components.size(); ++i) {
            if (i != c) {
                shade(police, components[i]);
            }
        }
    }

    // Working now in the smallest component, find the node with
    // the least adjacencies, and do BFS on it
    int least = least_adj(components[c], components[c].size() - 1);
    // print_list(components[c], components[c].size() - 1);
    cout << "least is: " << least << endl;

    // Now, find the node with the highest level and LEAST adjacencies
    // and do BFS on it, shading in all nodes >= level 2
    vector<bool> visitedbfs2 (nodes, false);
    vector<int> level2 (nodes, 0);
    //
    //
    // int adj_count = nodes - 1;
    // int high_node;
    //
    // for (size_t i = 1; i <= level.size(); ++i) {
    //     if (level[i - 1] == max_level) {
    //         if (components[c][i].size() > 0 &&
    //         (int) components[c][i].size() < adj_count) {
    //             adj_count = components[c][i].size();
    //             high_node = i;
    //         }
    //     }
    // }


    bfs(components[c], least, visitedbfs2, level2);

    for (size_t i = 0; i < level2.size(); ++i) {
        if (level2[i] >= 2) {
            police[i] = true;
        }
    }

    cout << police << endl;

    for (size_t i = 1; i <= adj.size() - 1; ++i) {
        cout << "Node: " << i << "\tLevel: " << level2[i - 1] << endl;
    }

    // cout << "\n# of connected components: " << connected << endl;

    // for (Graph g : components) {
    //     print_list(g, g.size() - 1);
    //     cout << endl;
    // }
}
