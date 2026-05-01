#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5;
vector<int> adj[N], rev_graph[N];
bool vis[N];
stack<int> st;
vector<int> scc;

void dfs1(int u) {
    vis[u] = true;
    for(auto v : adj[u]) {
        if(!vis[v]) {
            dfs1(v);
        }
    }
    st.push(u);
}

void dfs2(int u) {
    vis[u] = true;
    scc.push_back(u);
    for(auto v : rev_graph[u]) {
        if(!vis[v]) {
            dfs2(v);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_graph[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs1(i);
    }
    
    vector<vector<int>> total_scc;
    memset(vis, 0, sizeof(vis));
    while(!st.empty()) {
        int u = st.top();
        st.pop();
        if(!vis[u]) {
            dfs2(u);
            total_scc.push_back(scc);
            scc.clear();
        }
    }

    for(auto v : total_scc) {
        for(auto x : v) {
            cout << x << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}

// Time complexity = O(V + E)
