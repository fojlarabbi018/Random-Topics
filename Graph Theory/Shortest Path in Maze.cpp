// Source = S, Target = T, blocked = #, others are dot(.)

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool is_valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void solve() {
    cin >> n >> m;
    char grid[n][m];
    int si, sj, ti, tj;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'S') {
                si = i;
                sj = j;
            }
            if(grid[i][j] == 'T') {
                ti = i;
                tj = j;
            }
        }
    }
    
    vector<vector<bool>> vis(n, vector<bool> (m, false));
    vector<vector<int>> dist(n, vector<int> (m, 0));
    queue<pair<int, int>> q;

    q.push({si, sj});
    vis[si][sj] = true;
    dist[si][sj] = 0;

    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for(int d = 0; d < 4; d++) {
            int ni = i + dr[d];
            int nj = j + dc[d];

            if(is_valid(ni, nj) && !vis[ni][nj] && grid[ni][nj] != '#') {
                vis[ni][nj] = true;
                dist[ni][nj] = dist[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }

    cout << dist[ti][tj] << '\n';
   
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
