#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1005;
vector<int> adj[N];
int depth[N];

void dfs(int u, int p) {
    depth[u] = depth[p] + 1;
    for(auto v : adj[u]) {
        if(v != p) {
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
    
    dfs(1, 0);
    for(int i = 1; i <= n; i++) {
        cout << depth[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
