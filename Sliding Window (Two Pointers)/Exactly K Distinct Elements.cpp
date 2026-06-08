/* 
Given an array of size n, you need to find the number of subarrays 
containing Exactly K distinct elements
1 ≤ n ≤ 2⋅10^5, 1 ≤ ai ≤ 10^9


Actually it is impossible to find that directly without n^2, but 
what we can do is to find for "at most K" then just need to subtract "at most K - 1"

Exactly(K) = Atmost(K) - Atmost(K - 1)
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
vector<int> a;

ll atmost(int x) {
    map<int, int> mp;
    int l = 1;
    int distinct = 0;
    ll ans = 0;
    // Actually fixing l and seeing how far can we go
    // then all are valid from l to r
    // all ends at r
    for(int r = 1; r <= n; r++) {
        if(mp.find(a[r]) == mp.end()) {
            distinct++;
            mp[a[r]]++;
        }
        else mp[a[r]]++;

        while(distinct > x) {
            mp[a[l]]--;
            if(mp[a[l]] == 0) {
                distinct--;
                mp.erase(a[l]);
            }
            l++;
        }
        ans += r - l + 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    a.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll ans = atmost(k) - atmost(k - 1);
    cout << ans << '\n';

    return 0;
}
