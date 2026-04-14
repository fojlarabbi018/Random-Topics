#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if(parent[v] == v) {
            return v;
        }
        return parent[v] = find(parent[v]);
    } 

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            if(sz[a] < sz[b]) {
                swap(a, b);
            }
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int size(int v) {
        return sz[find(v)];
    }
};

struct Edge {
    int u, v, w;
};


void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for(int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i]. v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });
    
    DSU d(n);
    ll mst_cost = 0;
    for(auto [u, v, w] : edges) {
        if(d.find(u) != d.find(v)) {
            d.unite(u, v);
            mst_cost += w;
        }
    }

    cout << mst_cost << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
