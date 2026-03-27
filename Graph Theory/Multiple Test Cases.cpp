// Two options //

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
vector<int> adj[N];
bool vis[N];
int depth[N];

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

    for(int i = 0; i <= n; i++) {
        adj[i].clear();
        vis[i] = false;
        depth[i] = 0;
    }
  
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);
    map<int, int> mp;
    int mx = INT_MIN;
    for(int i = 1; i <= n; i++) {
        mp[depth[i]]++;
        mx = max(mx, mp[depth[i]]);
    }

    for(int i = 1; i <= n; i++) {
        int mx_child = adj[i].size() - 1;
        if(i == 1) mx_child++;
        if(mx_child == mx) {
            mx++;
            break;
        }
    }

    cout << mx << '\n';   
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


/// or
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
