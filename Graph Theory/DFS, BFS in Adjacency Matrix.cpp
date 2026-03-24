#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1005;
int adj[N][N];
bool vis[N];
int dist[N];

// O(V^2) [All the cells will be checked]
void dfs(int u) {
    vis[u] = true;
    // cout << u << " ";
    for(int v = 1; v < N; v++) {
        if(adj[u][v] == 1 && !vis[v]) {
            dfs(v);
        }
    }
}

// O(V^2) [All the cells will be checked]
void bfs(int src) {
    vis[src] = true;
    dist[src] = 0;

    queue<int> q;
    q.push(src);
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        // cout << u << " ";
        for(int v = 1; v < N; v++) {
            if(adj[u][v] == 1 && !vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
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
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // dfs(1);  
    bfs(1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
