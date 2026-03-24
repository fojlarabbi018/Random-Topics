#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1005;
vector<int> adj[N];
bool vis[N];

void dfs(int u) {
    vis[u] = true;
    for(auto v : adj[u]) {
        if(!vis[v]) {
            dfs(v);
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

    // dfs(1);

    // for(int i = 1; i <= n; i++) {
    //     if(!vis[i]) {
    //         cout << "Disconnected graph\n";
    //         return;
    //     }
    // } 
    // cout << "Connected graph\n";
    
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
            cnt++;
        }
    }

    cout << "Total Connected components: " << cnt << '\n'; 
    /*
    👉 A connected component = a group of nodes where
    every node is reachable from every other node  
    */
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
