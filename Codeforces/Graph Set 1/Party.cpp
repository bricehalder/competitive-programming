#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int MX = 2001;
vector<int> V[2001];
vector<bool> visited;
vector<int> level;
int curr_max = 0;

void bfs(int source) {
        queue<int> q;
        q.push(source);
        level[source] = 0;

        visited[source] = true;
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (size_t i = 0; i < V[v].size(); ++i) {
                int neighbor = V[v][i];
                if (!visited[neighbor]) {
                    level[neighbor] = level[v] + 1;

                    if (level[neighbor] > curr_max) {
                        curr_max = level[neighbor];
                    }

                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
}

void print_list(int size) {
    for (int i = 1; i <= size; ++i) {
        cout << "Node " << i << ": ";
        if (V[i].size() == 0) {
            cout << endl;
            continue;
        }
        for (size_t j = 0; j < V[i].size(); ++j) {
            if (j == V[i].size() - 1) {
                cout << V[i][j] << endl;
                continue;
            }
            cout << V[i][j] << " --> ";
        }
    }
}

void reset(int nodes) {
    level.assign(nodes, 0);
    visited.assign(nodes, false);
}

int main() {
    int nodes;
    vector<int> roots;
    cin >> nodes;
    int x;
    for (int i = 1; i <= nodes; ++i) {
        cin >> x;
        if (x > 0) {
            V[x].push_back(i);
        } else {
            roots.push_back(i);
        }
    }

    // print_list(nodes);

    for (int root : roots) {
        reset(nodes + 1);
        bfs(root);
    }

    cout << curr_max + 1 << endl;

    return 0;
}
