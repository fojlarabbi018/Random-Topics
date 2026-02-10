#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll sum = 0;
    ll mx = LLONG_MIN;

    for(int i = 0; i < n; i++) {
        sum += a[i];
        mx = max(mx, sum);
        if (sum < 0) sum = 0;
    }

    cout << mx << '\n'; 
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
