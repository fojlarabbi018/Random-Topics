// https://cses.fi/problemset/task/1745/

#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int n;
int a[N];
bool vis[N][100005];
vector<int> ans;

// This is also a very nice version of recursive dp (moving forward)
void f(int i, int sum) {
    if(i == n + 1) {
        if(sum > 0) ans.push_back(sum);
        return;
    }

    if(vis[i][sum]) return;

    f(i + 1, sum);
    f(i + 1, sum + a[i]);
    vis[i][sum] = true;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    memset(vis, false, sizeof(vis));
    f(1, 0);

    sort(ans.begin(), ans.end());
    auto it = unique(ans.begin(), ans.end());
    ans.erase(it, ans.end());

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
