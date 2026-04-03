#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
vector<int> adj[N];
vector<int> leaf;

void dfs(int u, int p) {
    bool isLeaf = true;

    for(auto v : adj[u]) {
        if(v != p) {
            isLeaf = false;
            dfs(v, u);
        }
    }

    if(isLeaf) leaf.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // solve();
    return 0;
}
