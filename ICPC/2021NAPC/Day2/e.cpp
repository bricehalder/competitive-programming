#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct union_find {
    vector<int> parent;
    vector<int> size;
    int components = 0;

    vector<int> parent_mito_id;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        parent_mito_id.resize(n + 1);
        size.assign(n + 1, 1);
        components = n;

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (size[x] < size[y])
            swap(x, y);

        if (parent_mito_id[x]) {
            parent_mito_id[y] = parent_mito_id[x];
        }
        
        parent[y] = x;
        size[x] += size[y];
        components--;
        return true;
    }
};


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    vector<bool> dead;
    // vector<char> gender;
    // vector<int> mito_id;

    int N, M, K;
    cin >> N;

    // gender.resize(N + 1);
    // mito_id.resize(N + 1);

    char sex;

    for (int i = 1; i <= N; i++) {
        cin >> sex;
        // gender[i] = sex;
    }

    cin >> M;

    union_find UF(N + M);
    dead.resize(N + M + 1);

    int id;
    int fID, mID;

    int next_id = N + 1;
    int new_babies = 0;

    for (int i = 0; i < M; i++) {
        cin >> id;
        if (id < 0) {
            dead[abs(id)] = true;
        } else {
            new_babies += 1;

            mID = id;
            cin >> fID >> sex;
            // gender[next_id] = sex;

            // cout << "fid: " << fID << " next_id: " << next_id << endl;
            UF.unite(fID, next_id);
            
            // cout << "dead after child ";
            // for (auto it = dead.begin(); it != dead.end(); it++)
            // {
            //     cout << *it << " ";
            // }
            // cout << endl;

            next_id += 1;
        }
    }

    // cout << "new babies " << new_babies << endl;
    for (int i = N + new_babies + 1; i < dead.size(); i++) {
        dead[i] = true;
    }

    cin >> K;
    int mito;
    map<int, int> id_idx;

    for (int i = 0; i < K; i++) {
        cin >> id >> mito;
        // if (id_idx.count(mito) > 0) {
        //     UF.unite(id, id_idx[mito]);
        // } else {
        int par_id = UF.find(id);
        id_idx.insert(pair<int, int>(mito, par_id));
        UF.parent_mito_id[par_id] = mito;
        // }
    }

    set<int> pos_ids;
    for (int i = 1; i < UF.parent_mito_id.size(); i++) {
        if (!dead[i]) {
            if (UF.parent_mito_id[i] != 0) {
                pos_ids.insert(UF.parent_mito_id[i]);
            }
        }
    }

    // int uniq_mitos;
    set<int> unknown_mito;
    set<int> num_alive_comp;

    // cout << "dead ";
    // for (auto it = dead.begin(); it != dead.end(); it++)
    // {
    //     cout << *it << " ";
    // }
    // cout << endl;

    // cout << "parent_mito_id ";
    // for (auto it = UF.parent_mito_id.begin(); it != UF.parent_mito_id.end(); it++)
    // {
    //     cout << *it << " ";
    // }
    // cout << endl;

    for (int i = 1; i < dead.size(); i++) {
        if (dead[i]) continue;

        int par_id = UF.find(i);
        // cout << "par_id: " << par_id << " id : " << i << endl;
        // if (!dead[par_id]) {
        num_alive_comp.insert(par_id);
        if (UF.parent_mito_id[par_id] != 0) {
            pos_ids.insert(UF.parent_mito_id[par_id]);
        } else {
            // cout << "WTF: par_id: " << par_id << 
            unknown_mito.insert(par_id);
        }
        // }
    }

    // uniq_mitos += num_alive_comp.size();

    if (pos_ids.size() > 1) {
        cout << "NO" << endl;
    } else if ((pos_ids.size() == 1 && unknown_mito.size() == 0) || (unknown_mito.size() > 0 && num_alive_comp.size() == unknown_mito.size() && num_alive_comp.size() == 1)) {
        cout << "YES" << endl;
    } else {
        cout << "POSSIBLY" << endl;
    }

    // cout << "pos_ids ";
    // for (auto it = pos_ids.begin(); it != pos_ids.end(); it++)
    // {
    //     cout << *it << endl;
    // }

    // cout << "num_alive_comp ";
    // for (auto it = num_alive_comp.begin(); it != num_alive_comp.end(); it++)
    // {
    //     cout << *it << endl;
    // }

    // cout << "unknown_mito ";
    // for (auto it = unknown_mito.begin(); it != unknown_mito.end(); it++)
    // {
    //     cout << *it << endl;
    // }

    // if (pos_ids.size() < 2 && unknown_mito.size() + pos_ids.size() == num_alive_comp.size()) {
    //     if (unknown_mito.size() + pos_ids.size() == 1 || pos_ids.size() == num_alive_comp.size()) {
    //         cout << "YES" << endl;
    //     } else {
    //         cout << "POSSIBLY" << endl;
    //     }
    // } else {
    //     cout << "NO" << endl;
    // }
}