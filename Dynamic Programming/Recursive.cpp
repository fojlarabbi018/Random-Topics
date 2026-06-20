// https://atcoder.jp/contests/dp/tasks/dp_m

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 105, m = 1e9 + 7;
int n, k;
int a[N];
int dp[N][100005];

// This is the most intuitive way to use recursive dp
// Direct calling the final ans which depends on the prev ans
int f(int i, int rem_sum) {
    if(i == 0) return rem_sum == 0;
    if(dp[i][rem_sum] != -1) {
        return dp[i][rem_sum];
    }

    ll ans = 0;
    for(int j = 0; j <= a[i]; j++) {
        ans += f(i - 1, rem_sum - j);
        ans %= m;
    }

    return dp[i][rem_sum] = ans;
}

void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    memset(dp, -1, sizeof(dp));
    cout << f(n, k) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
