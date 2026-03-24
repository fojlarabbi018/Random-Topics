#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1005;
vector<int> adj[N];
bool vis[N];
int dist[N];

// O(V + 2E) = O(V + E)
// For each node, all its adjacent nodes are checked (adjacent edges simply)
// And finally you can see that each edges are checked twice
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
                vis[v] = true;
                dist[v] = dist[u] + 1;
            }
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
    
    bfs(1);
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
