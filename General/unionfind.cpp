#include <bits/stdc++.h>

using namespace std;

bool validTree(int n, vector<vector<int>> edges) {
    // initialize n isolated islands
    vector<int> nums(n, -1);
    
    // perform union find
    for (int i = 0; i < edges.size(); i++) {
        int x = find(nums, edges[i][0]);
        int y = find(nums, edges[i][1]);
        
        // if two vertices happen to be in the same set
        // then there's a cycle
        if (x == y) return false;
        
        // union
        nums[x] = y;
    }
    
    return edges.size() == n - 1;
}

int find(vector<int> nums, int i) {
    if (nums[i] == -1) return i;
    return find(nums, nums[i]);
}