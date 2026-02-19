#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
int seg[4 * N], lazy[4 * N];
int a[N];

void push(int idx, int l, int r) {
    if(lazy[idx] == 0) return;
    seg[idx] += (r - l + 1) * lazy[idx];

    if(l != r) {
        lazy[2 * idx] += lazy[idx];
        lazy[2 * idx + 1] += lazy[idx];
    }

    lazy[idx] = 0;
}

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

void update(int idx, int l, int r, int ql, int qr, int val) {
    push(idx, l, r);

    if(r < ql || l > qr) return;
    if(l >= ql && r <= qr) {
        lazy[idx] += val;
        push(idx, l, r);
        return;
    }
    
    int mid = (l + r) / 2;
    update(2 * idx, l, mid, ql, qr, val);
    update(2 * idx + 1, mid + 1, r, ql, qr, val);

    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

ll query(int idx, int l, int r, int ql, int qr) {
    push(idx, l, r);

    if(r < ql || l > qr) return 0;
    if(l >= ql && r <= qr) return seg[idx];

    int mid = (l + r) / 2;
    return query(idx * 2, l, mid, ql, qr) +
           query(idx *2 + 1, mid + 1, r, ql, qr);
}


void solve() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
        } 
        else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
