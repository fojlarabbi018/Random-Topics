// https://codeforces.com/edu/course/2/lesson/6/5/practice/contest/285084/problem/C

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // Checking how many pairs <= x 
    // Say the ans is 9, then definitely there will be k pairs which are <= 9 
    auto check = [&](ll x) {
        ll cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += upper_bound(b.begin(), b.end(), x - a[i]) - b.begin();
            // Fixing a[i] and counting how many b[j] --> (a[i] + b[j] <= x)
            // If I can manage to get the iterator of upper bound of x - a[i]
            // then I can easily count how many b[j] are <= x - a[i]
        }
        return cnt;
    };

    ll low = a[0] + b[0];
    ll high = a[n - 1] + b[n - 1];
    ll ans;
    while(low <= high) {
        ll mid = (low + high) / 2;
        if(check(mid) >= k) { 
        // Coming from the right side. And searching the last x that 
        // satisfies the condition. 
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    cout << ans << '\n';
    return 0;
}
