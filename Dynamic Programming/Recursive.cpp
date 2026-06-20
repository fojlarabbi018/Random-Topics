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
// f(i, rem) = how many ways we can distribute rem candies among 1 to i
int f(int i, int rem) {
    if(i == 0) return rem == 0;
    if(dp[i][rem] != -1) {
        return dp[i][rem];
    }

    ll ans = 0;
    for(int j = 0; j <= a[i]; j++) {
        ans += f(i - 1, rem - j);
        ans %= m;
    }

    return dp[i][rem] = ans;
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
