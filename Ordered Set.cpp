#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll INF = 1e18;

// Total number of inversion counting using "ordered set" (making it multiset)
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    o_set<pair<int, ll>> se;
    ll cnt = 0;
    int uid = 0;
    for(int i = 1; i <= n; i++) {
        cnt += se.size() - se.order_of_key({a[i], INF});
        se.insert({a[i], uid++});
    }

    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}
