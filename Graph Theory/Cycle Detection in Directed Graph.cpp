#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1005;
vector<int> adj[N];
bool vis[N];
int col[N];
bool ok = false;

// 0 = unvisited, 1 = active, 2 = finished
// Cycle will only be found when there is an edge from "depth to up" 
// during recursion call (back edge)

void dfs(int u) {
    col[u] = 1;

    for(auto v : adj[u]) {
        if(col[v] == 0) {
            dfs(v);
        }
        else if(col[v] = 1) {
            ok = true;
        }
    }
    col[u] = 2; 
    // dfs call has finished for this u (2 = blue)
    // because all its adjacents are visited
}

bool has_cycle() {
    return ok;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    dfs(1);
    cout << has_cycle() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
