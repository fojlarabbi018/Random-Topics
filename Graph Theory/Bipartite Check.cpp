#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1005;
vector<int> adj[N];
bool vis[N], ok = true;
int col[N];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = true;
 
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto v : adj[u]) {
            if(!vis[v]) {
                q.push(v);
                vis[v] = true;
                col[v] = col[u] ^ 1;
            }
            else {
                if(col[u] == col[v]) ok = false;
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
    
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) bfs(i);
    }
    cout << ok << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
