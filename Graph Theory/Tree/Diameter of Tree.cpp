#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1005;
vector<int> adj[N];
int depth[N];

// 👉 Diameter = longest distance between any two nodes
void dfs(int u, int p) {
    for(auto v : adj[u]) {
        if(v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // 1st DFS
    // When a dfs is applied from any node, then the farthest node
    // will always be an endpoint of the diameter
    dfs(1, -1);
    int node1 = 1, mx = INT_MIN;
    for(int i = 1; i <= n; i++) {
        if(depth[i] > mx) {
            mx = depth[i];
            node1 = i;
        }
    }
    
    // 2nd DFS
    memset(depth, 0, sizeof(depth));
    dfs(node1, -1);

    mx = INT_MIN;
    int node2 = 1;
    for(int i = 1; i <= n; i++) {
        if(depth[i] > mx) {
            mx = depth[i];
            node2 = i;
        }
    }
    cout << mx << " ";
    // node1 and node2 are the two endpoints of the diameter
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
