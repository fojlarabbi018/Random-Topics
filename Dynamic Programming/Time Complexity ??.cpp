// https://cses.fi/problemset/task/1745

#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int n;
int a[N];
bool vis[N][100005];
bool dp[N][100005];

// A pure brute force version
// f = is it possible to make a sum = sum by using elements from 1 to i ?
bool f(int i, int sum) {
    if(i == 0) {
        return sum == 0;
    }
    if(sum < 0) return 0;

    if(vis[i][sum]) return dp[i][sum];

    int x = f(i - 1, sum);
    int y = f(i - 1, sum - a[i]);

    vis[i][sum] = true;
    return dp[i][sum] = (x | y);
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    memset(vis, false, sizeof(vis));
    memset(dp, false, sizeof(dp));
    
    vector<int> ans;
    // The most important part
    // "Time complexity won't be N * MX * MX"
    // for each small sum the branch creation will be very low
    // (call will be terminated instantly)
    // and as the sum grows the memoization does the rest

    // In short, there are exactly N * MX unique states

    for(int sum = 1; sum < 100005; sum++) {
        if(f(n, sum)) ans.push_back(sum);
    }

    cout << ans.size() << '\n';
    for(auto x : ans) {
        cout << x << " ";
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}
