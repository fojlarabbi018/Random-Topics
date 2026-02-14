#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    priority_queue<pair<int, int>> ap, bp, cp;
    for(int i = 0; i < n; i++) {
        ap.push({a[i], i});
        bp.push({b[i], i});
        cp.push({c[i], i});
    }
    
    vector<int> max3a, max3b, max3c;
    int cnt = 3;
    while(cnt--) {
        max3a.push_back((ap.top()).second);
        max3b.push_back((bp.top()).second);
        max3c.push_back((cp.top()).second);
        ap.pop();
        bp.pop();
        cp.pop();
    }
    int ans = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                int x = max3a[i];
                int y = max3b[j];
                int z = max3c[k];
                if(x != y && y != z && z != x) {
                    int sum = a[x] + b[y] + c[z];
                    ans = max(ans, sum);
                }

            }
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
