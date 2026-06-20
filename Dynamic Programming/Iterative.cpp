// https://atcoder.jp/contests/dp/tasks/dp_m

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 105, m = 1e9 + 7;
int n, k;
int a[N];
int dp[N][100005];
int pref[N][100005];

void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // Base case
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1;
        pref[i][0] = 1;
    }
    for(int j = 1; j <= k; j++) {
        dp[0][j] = 0;
        pref[0][j] = pref[0][j - 1] + dp[0][j]; // (all are 1 actully)
    }
    
    // Iterative
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            int ans = 0;
            int l = j - a[i];
            if(l <= 0) ans = pref[i - 1][j];
            else ans = (pref[i - 1][j] - pref[i - 1][l - 1] + m) % m;
            dp[i][j] = ans;
            pref[i][j] = (pref[i][j - 1] + dp[i][j]) % m;
        }
    }

    cout << dp[n][k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
