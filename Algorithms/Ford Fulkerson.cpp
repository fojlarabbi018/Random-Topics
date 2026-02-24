#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1000;
vector<int> parent(N);
vector<int> adj[N];
int capacity[N][N];

int bfs(int s, int t) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;

    queue<pair<int, int>> q;
    q.push({s, INT_MAX});

    while(!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for(auto next : adj[cur]) {
            if(parent[next] == -1 && capacity[cur][next] > 0) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);

                if(next == t) return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    int new_flow;

    while(new_flow = bfs(s, t)) {
        flow += new_flow;
        int cur = t;

        while(cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] = w;
    }

    int s, t;
    cin >> s >> t;
    cout << max_flow(s, t) << '\n';

    return 0;
}
