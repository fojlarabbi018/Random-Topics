// O(1) per query

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1000;
int arr[N][N]; 
ll pre[N][N];
ll diff[N][N]; 
// In 2D, "diff" matrix of all 0s are taken (also valid for normal array)
// then after all the operations, just add the main matrix value to the "pre"

void solve() {
    int n, m, q; cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];

        }
    }
    for(int i = 1; i <= q; i++) {
        int x1, y1, x2, y2, d;
        cin >> x1 >> y1 >> x2 >> y2 >> d;
        diff[x1][y1] += d;
        diff[x1][y2 + 1] -= d;
        diff[x2 + 1][y1] -= d;
        diff[x2 + 1][y2 + 1] += d;

    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + diff[i][j];

        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << pre[i][j] + arr[i][j] << " ";

        }
        cout << '\n';
    }
   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
/*
5 4 1
1 1 1 1 
2 2 2 2 
3 3 3 3 
4 4 4 4
5 5 5 5
3 3 4 4 7
*/
