#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Must use that
vector<vector<int>> adj;
vector<bool> vis;
vector<int> dist;

void bfs(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dist[src] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
      
        for(auto v : adj[u]) {
            if(!vis[v]) {
                q.push(v);
                dist[v] = dist[u] + 1;
                vis[v] = true;
            }
        }
    }

}
 
void solve() {
    int n;
    cin >> n;
  
    // Always use "assign()" rather than, clear() + resize()
    adj.assign(n + 1, vector<int> ());
    vis.assign(n + 1, false);
    dist.assign(n + 1, 0);

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bfs(1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
