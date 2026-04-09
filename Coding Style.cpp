#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
vector<int> adj[N];
vector<pair<int, int>> edges;

void dfs(int u, int p, string s) {
    for(auto v : adj[u]) {
        if(v != p) {
            if(s == "out") {
                edges.push_back({u, v});
                dfs(v, u, "in");
            }
            else {
                edges.push_back({v, u});
                dfs(v, u, "out");
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i <= n; i++) {
        adj[i].clear();
    }
    edges.clear();

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int root = -1;
    for(int i = 1; i <= n; i++) {
        int sz = adj[i].size();
        if(sz == 2) {
            root = i;
            break;
        }
    }

    if(n == 2 || root == -1) {
        cout << "NO\n";
        return;
    }

    edges.push_back({adj[root][0], root});
    edges.push_back({root, adj[root][1]});

    dfs(adj[root][0], root, "out");
    dfs(adj[root][1], root, "in");

    cout << "YES\n";
    for(auto [x, y] : edges) {
        cout << x << " " << y << '\n';
    }
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
