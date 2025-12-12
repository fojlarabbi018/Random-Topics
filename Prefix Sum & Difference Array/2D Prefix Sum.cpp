#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1000;
int arr[N][N]; 
ll pre[N][N];

void solve() {
    // vector<vector<ll>> pre(n + 1, vector<ll> (m + 1, 0));
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + arr[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << pre[i][j] << " ";

        }
        cout << '\n';
    }
    /* -----for 0 based index-----
    Just imagine there is an extra column and extra row with all 0s in the pre array (left & top)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int up = (i > 0) ? pre[i - 1][j] : 0;
            int left = (j > 0) ? pre[i][j - 1] : 0;
            int diag = (i > 0 && j > 0) ? pre[i - 1][j - 1] : 0;

            pre[i][j] = a[i][j] + up + left - diag;
        }
    } */
   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
