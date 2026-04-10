// https://codeforces.com/contest/2065/problem/F

// My solution

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5e5 + 5;
vector<int> adj[N], seen[N];
int depth[N], a[N], ans[N];

void dfs(int u, int p) {
    for(auto v : adj[u]) {
        if(v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

void dfs2(int u, int p) {
    int val = a[u];
    if(!seen[val].empty()) {
        int last = seen[val].back();
        if(abs(depth[u] - depth[last]) < 3) {
            ans[val] = 1;
        }
    }
    seen[val].push_back(u);
    // cout << "entering " << val << '\n';

    for(auto v : adj[u]) {
        if(v != p) {
            dfs2(v, u);
        }
    }

    // cout << "exiting " << val << '\n';
    seen[val].pop_back();
}

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i <= n; i++) {
        adj[i].clear();
        seen[i].clear();
        depth[i] = 0;
        a[i] = 0;
        ans[i] = 0;
    }
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    dfs2(1, 0);
    
    for(int i = 1; i <= n; i++) {
        map<int, int> mp;
        for(auto v : adj[i]) {
            mp[a[v]]++;
        }

        for(auto [x, y] : mp) {
            if(y >= 2) ans[x] = 1;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i];
    }
    cout << '\n';
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
