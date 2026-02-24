#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    for(int i = 0; i < m; i++) {
        int u, v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(auto neighbor: adj[cur]) {
            indegree[neighbor]--;
            if(indegree[neighbor] == 0) q.push(neighbor);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}
