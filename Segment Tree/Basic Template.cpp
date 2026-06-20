#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
int a[N];

struct Node {
    int gcd, mn, cnt;
};

struct SegTree {
    Node seg[4 * N];

    SegTree() {
        memset(seg, 0, sizeof(seg));
    }

    Node merge(Node left, Node right) {
        Node res;

        res.gcd = __gcd(left.gcd, right.gcd);
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
            seg[idx] = {a[l], a[l], 1};
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, int val) {
        if(l == r) {
            seg[idx] = {val, val, 1};
            return;
        }

        int mid = (l + r) / 2;

        if(pos <= mid) update(2 * idx, l, mid, pos, val);
        else update(2 * idx + 1, mid + 1, r, pos, val);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if(r < ql || l > qr) {
            return {0, INT_MAX, 0};
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
}st; // Global declaration is a must
// Otherwise stack overflow will occur for large array inside the SegTree
// Always use Node rather than just int or ll(Node with one member = same as int, ll)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
