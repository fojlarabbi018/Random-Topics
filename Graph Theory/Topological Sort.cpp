#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1005;
vector<int> adj[N];
bool vis[N];
int indeg[N];

// Only valid for DAG
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        indeg[v]++;
        adj[u].push_back(v);
    }
    
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indeg[i] == 0) q.push(i);
    }

    vector<int> ans;
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        ans.push_back(u);
        for(auto v : adj[u]) {
            indeg[v]--;
            if(indeg[v] == 0) q.push(v);
        }
    }
    
    // If there is any cycle anywhere, then at a time the queue 
    // will be empty before visiting all nodes thus ans.size() != n
    if(ans.size() != n) cout << "Impossible\n";
    else {
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
