// Say you have been given a maze/grid where each cell has a direction(U, D, L, R)
// How many starting cells are there from where you can escape?

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

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> escape(n, vector<bool> (m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0) {
                if(grid[i][j] == 'U') {
                    q.push({i, j});
                    escape[i][j] = true;
                }
            }

            if(i == n - 1) {
                if(grid[i][j] == 'D') {
                    q.push({i, j});
                    escape[i][j] = true;
                }
            }

            if(j == 0) {
                if(grid[i][j] == 'L') {
                    q.push({i, j});
                    escape[i][j] = true;
                }
            }

            if(j == m - 1) {
                if(grid[i][j] == 'R') {
                    q.push({i, j});
                    escape[i][j] = true;
                }
            }
        }
    }

    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for(int d = 0; d < 4; d++) {
            int ni = i + dr[d];
            int nj = j + dc[d];
            
            int ti = ni, tj = nj;
            if(is_valid(ni, nj)) {
                if(grid[ni][nj] == 'U') ti--;
                else if(grid[ni][nj] == 'D') ti++;
                else if(grid[ni][nj] == 'L') tj--;
                else if(grid[ni][nj] == 'R') tj++;
            }

            if(ti == i && tj == j) {
                q.push({ni, nj});
                escape[ni][nj] = true;
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(escape[i][j]) ans++;
        }
    }

    cout << ans << '\n';  
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
