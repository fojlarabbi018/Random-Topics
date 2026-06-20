#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
int a[N];

struct Node {
    int mn, cnt;
};

struct SegTree {
    Node seg[4 * N];

    SegTree() {
        memset(seg, 0, sizeof(seg));
    }

    Node merge(Node left, Node right) {
        Node res;

        res.mn = min(left.mn, right.mn);

        if(left.mn == right.mn) {
            res.cnt = left.cnt + right.cnt;
        }
        else if(left.mn < right.mn) {
            res.cnt = left.cnt;
        }
        else {
            res.cnt = right.cnt;
        }

        return res;
    }

    void build(int idx, int l, int r) {
        if(l == r) {
            seg[idx] = {a[l], 1};
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, int val) {
        if(l == r) {
            seg[idx] = {val, 1};
            return;
        }

        int mid = (l + r) / 2;

        if(pos <= mid) update(2 * idx, l, mid, pos, val);
        else update(2 * idx + 1, mid + 1, r, pos, val);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if(r < ql || l > qr) {
            return {INT_MAX, 0};
        }
        if(l >= ql && r <= qr) {
            return seg[idx];
        }

        int mid = (l + r) / 2;

        return merge(
            query(2 * idx, l, mid, ql, qr),
            query(2 * idx + 1, mid + 1, r, ql, qr)
        );
    }
};


void solve() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    SegTree st;
    st.build(1, 1, n);

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int pos, val;
            cin >> pos >> val;
            pos++;
          
            st.update(1, 1, n, pos, val);
        } 
        else {
            int l, r;
            cin >> l >> r;
            l++; r++;
            Node ans = st.query(1, 1, n, l, r);
            cout << ans.mn << " " << ans.cnt << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
