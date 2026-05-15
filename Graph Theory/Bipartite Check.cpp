#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1005;
vector<int> adj[N];
bool vis[N];
int col[N];
bool is_bipartite = true;

void dfs(int u) {
    vis[u] = true;
    for(auto v : adj[u]) {
        if(!vis[v]) {
            col[v] = col[u] ^ 1;
            dfs(v);
        }
        else if(col[v] == col[u]) {
            is_bipartite = false;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i);
    }
    cout << is_bipartite << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
