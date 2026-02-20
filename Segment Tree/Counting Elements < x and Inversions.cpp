#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
ll seg[4 * N];

// Remember, here the seg tree is built from freq array
void update(int idx, int l, int r, int pos, int val) {
    if(l == r) {
        seg[idx] += val;
        return;
    }

    int mid = (l + r) / 2;
    if(pos <= mid) update(2 * idx, l, mid, pos, val);
    else update(2 * idx + 1, mid + 1, r, pos, val);

    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

int query(int idx, int l, int r, int ql, int qr) {
    if(r < ql || l > qr) return 0;
    if(l >= ql && r <= qr) return seg[idx];

    int mid = (l + r) / 2;
    return query(2 * idx, l, mid, ql, qr) +
           query(2 * idx + 1, mid + 1, r, ql, qr);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    // Coordinate Compression
    vector<int> com = a;
    sort(com.begin(), com.end());
    auto it = unique(com.begin(), com.end());
    com.erase(it, com.end());
    
    for(int i = 0; i < n; i++) {
        a[i] = lower_bound(com.begin(), com.end(), a[i]) - com.begin() + 1;
    }

    int m = com.size();
    ll inv_cnt = 0;
    for(int i = n - 1; i >= 0; i--) {
        inv_cnt += query(1, 1, m, 1, a[i] - 1);
        update(1, 1, m, a[i], 1);
    }

    cout << inv_cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}
