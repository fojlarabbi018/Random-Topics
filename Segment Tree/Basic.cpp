// build --> O(n) (because we need to create all the nodes, which is approximately 4*n)
// update --> O(log n)
// query --> O(log n)

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
ll a[N];
ll seg[4 * N];

// Here each node is represented an index "idx" and containing
// a range sum of segment "l to r"
// Actually which range sum it's containing depends on the parent's range
// That's why it doesn't need to store extra variables l and r

// For each node, we are building its two children first then
// assigning the sum of children's value

void build(int idx, int l, int r) {
    if(l == r) {
        seg[idx] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);

    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

ll query(int idx, int l, int r, int ql, int qr) {
    if(r < ql || l > qr) return 0;
    if(l >= ql && r <= qr) return seg[idx];
    
    int mid = (l + r) / 2;
    return query(2 * idx, l, mid, ql, qr) + 
           query(2 * idx + 1, mid + 1, r, ql, qr);
}

void update(int idx, int l, int r, int pos, int val) {
    if(l == r) {
        seg[idx] = val;
        return;
    }

    int mid = (l + r) / 2;
    if(pos <= mid) update(2 * idx, l, mid, pos, val);
    else  update(2 * idx + 1, mid + 1, r, pos, val);

    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

// We could use a nice idea also... Say you know the index of 
// pos in the segment tree array, then easily you can visit the path
// from that index to the root using parent and increase the sum to each

// As all single pos are in the last level of segment tree,
// we can save them in a map (in the base conditon of the build func)

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);
    for(int i = 1; i < 4 * n; i++) cout << seg[i] << " ";

    update(1, 1, n, 1, 100);
    for(int i = 1; i < 4 * n; i++) cout << seg[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}
