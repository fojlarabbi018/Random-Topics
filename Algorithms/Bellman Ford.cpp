#include<bits/stdc++.h>
using namespace std;
#define ll long long

// O(V + E)

const ll INF = 1e18;

struct Edge {
    int u, v;
    ll w;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for(int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int src;
    cin >> src;
    
    vector<ll> dist(n + 1, INF);
    dist[src] = 0;

    // Relaxing n - 1 times
    for(int i = 1; i < n - 1; i++) {
        for(auto e : edges) {
            if(dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Negative cycle cheaking
    bool neg_cycle = false;
    for(auto e : edges) {
        if(dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            dist[e.v] = dist[e.u] + e.w;
            neg_cycle = true;
            break;
        }

    }

    if(neg_cycle) {
        cout << "Negative cycle found\n";
    }
    else {
        for(int i = 1; i <= n; i++) {
            cout << i << " -> " << dist[i] << '\n';
        }

    }
    return 0;
}

/*
5 8
1 2 6
1 3 7
2 3 8
2 4 5
2 5 -4
3 4 -3
3 5 9
4 2 -2
1

Output:
1 → 0
2 → 2
3 → 7
4 → 4
5 → -2

For negative cycle
3 3
1 2 1
2 3 -1
3 1 -1
1
*/

