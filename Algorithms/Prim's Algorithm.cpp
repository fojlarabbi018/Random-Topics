#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<bool> visited(n + 1, false);
    priority_queue<pair<int, int>,
                  vector<pair<int, int>>,
                  greater<pair<int, int>>> pq;

    ll mst_cost = 0;
    pq.push({0, 1});

    while(!pq.empty()) {
        auto [wt, u] = pq.top();
        pq.pop();

        if(visited[u]) continue;

        visited[u] = true;
        mst_cost += wt;

        for(auto [v, w] : adj[u]) {
            if(!visited[v]) {
                pq.push({w, v});
            }
        }
    }

    cout << mst_cost << '\n';

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "Graph is disconnected\n";
            break;
        }
    }
  
return 0;  
}

/*
Time Complexity = O(E log V)
Why?
Each edge is checked and then unvisited nodes are pushed → O(E)
Each push/pop from heap costs log V 
because the heap can have max V - 1 elements at a time (only unvisited are pushed)
So total ≈ E log V

Input:
1 —(-2)— 2
| \     |
4  3    1
|    \  |
3 —5— 4

4 5
1 2 -2
1 3 4
1 4 3
2 4 1
3 4 5

Ans = 3
*/
