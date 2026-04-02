#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cout << #x << ": " << x << '\n'

////<======= Custom_hash ========>

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
      x += 0x9e3779b97f4a7c15;
      x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
      x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
      return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
      static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
      return splitmix64(x + FIXED_RANDOM);
  }
};
unordered_map<long long int, int, custom_hash> mp; 
// this will work when the key is an "int or long long int"
// and all operations will now be done at O(1)..(even for the larger value)
// O(log (min(a, b)))


////<======= Ordered Set ========>

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void yoyo {

    o_set<int> se;
    se.insert(4);
    se.insert(2);
    se.insert(5);
    // sorted set se = [2, 4, 5]
    cout << se.order_of_key(5) << '\n'; // number of elements < 5
    cout << se.order_of_key(6) << '\n'; // number of elements < 6
    cout << (*se.find_by_order(1)) << '\n'; // 4
    // if you imagine this as a 0-indexed vector, what is se[1]?
}


////<======= Segment Tree =======>

const int N = 2e5 + 5;
struct Node {
    int gcd, mn, cnt;
};

ll a[N];
Node seg[4 * N];

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
    else res.cnt = right.cnt;

    return res;
}

void build(int idx, int l, int r) {
    if(l == r) {
        seg[idx].gcd = a[l];
        seg[idx].mn = a[l];
        seg[idx].cnt = 1;
        return;
    }

    int mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);

    seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
}

void update(int idx, int l, int r, int pos, int val) {
    if(l == r) {
        seg[idx].gcd = val;
        seg[idx].mn = val;
        seg[idx].cnt = 1;
        return;
    }

    int mid = (l + r) / 2;
    if(pos <= mid) update(2 * idx, l, mid, pos, val);
    else  update(2 * idx + 1, mid + 1, r, pos, val);

    seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
} 

Node query(int idx, int l, int r, int ql, int qr) {
    if(r < ql || l > qr) return {0, INT_MAX, 0};
    if(l >= ql && r <= qr) return seg[idx];

    int mid = (l + r) / 2;
   
    return merge(query(2 * idx, l, mid, ql, qr),
           query(2 * idx + 1, mid + 1, r, ql, qr));
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
            int pos, val;
            cin >> pos >> val;
            pos++;
          
            update(1, 1, n, pos, val);
        } 
        else {
            int l, r;
            cin >> l >> r;
            l++; r++;
            Node ans = query(1, 1, n, l, r - 1);
            cout << ans.gcd << " " << ans.mn << " " << ans.cnt << '\n';
        }
    }
}

//// <======= Lazy =======>

const int N = 2e5 + 5;
ll seg[4 * N], lazy[4 * N];
ll a[N];

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
    return query(2 * idx, l, mid, ql, qr) +
           query(2 * idx + 1, mid + 1, r, ql, qr);
}

////<======= gcd =======>

ll mygcd(ll a, ll b) {
    while(b != 0) {
        ll rem = a % b;
        a = b;
        b = rem;
    }
    return a;
} 

////<======= legendare ========>

int legendare(int n, int p) {
    int ans = 0;
    while(n / 2 > 0) {
        ans += n / 2;
        n /= 2;
    }

    return ans;
}
////<======= sieve =======>

const int N = 1e6 + 5;
vector<int> prime;
bitset<N> is_prime;

void sieve() {
    is_prime.set();
    is_prime[1] = 0;
    for(int i = 2; i * i < N; i++) {
        if(is_prime[i]) {
            for(int j = 2 * i; j < N; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    for(int i = 2; i < N; i++) {
        if(is_prime[i]) prime.push_back(i);
    }
}


//// <======= spf & prime factorization =======>

const int N = 1e6 + 5;
vector<int> spf(N);

void pre_spf() {   
    for(int i = 2; i < N; i++) {
        spf[i] = i;
    }

    for(int i = 2; i * i < N; i++) {
        if(spf[i] == i) {
            for(int j = 2 * i; j < N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

vector<int> v;
void prime_fact(int n) {
    while(n > 1) {
        v.push_back(spf[n]);
        n /= spf[n];
    } 
}


//// <========= Normal Prime Factorization ========>

vector<int> v;
void prime_fact(int n) {
    for(int i = 2; i * i <= n; i++) { 
        if(n % i == 0) {
            while(n % i == 0) {
                v.push_back(i);
                n /= i;
            }
        }
    }

    if(n > 1) v.push_back(n);
}

////<======= Binary Exponentiation =======>

const int N = 1e6 + 5, m = 1e9 + 7;
int binpow(ll a, ll n, int m) {
    a = a % m;   
    ll res = 1 % m;
    while(n > 0) {
        if(n & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}


////<======= Combinatorics =======>

// m must be Prime and cannot divide a 
// If any fact is divisible by m, then WA
// N = 1e6 + 5 is safer as m = 1e9 + 7 (fact % m won't be 0)
int inverse(int a, int m) {
    return binpow(a, m - 2, m);
}

int fact[N], invfact[N];
void pre_fact() {
    fact[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = 1LL * fact[i - 1] * i % m;
    }
    // for(int i = 0; i < N; i++) { // O(N * log N)
    //     invfact[i] = inverse(fact[i], m);
    // }
    invfact[N - 1] = inverse(fact[N - 1], m) % m;
    for(int i = N - 2; i >= 0; i--) {
        invfact[i] = 1LL * invfact[i + 1] * (i + 1) % m;
    }
}

int nCr(int n, int r) {
    if(n < r || n < 0 || r < 0) return 0;
    return 1LL * fact[n] * invfact[n - r] % m * invfact[r] % m;
}
int nPr(int n, int r) {
    if(n < r || n < 0 || r < 0) return 0;
    return 1LL * fact[n] * invfact[n - r] % m;
}

//// When N is small

const int N = 2005, m = 1e9 + 7;

int C[N][N], fact[N];
void prec() { // O(n^2)
    for(int i = 0; i < N; i++) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % m;
        }
    }

    fact[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = 1LL * fact[i - 1] * i % m;
    }
}

int nCr(int n, int r) { // O(1)
    if (n < r || n < 0 || r < 0) return 0;
    return C[n][r];
}

int nPr(int n, int r) { // O(1)
    if (n < r || n < 0 || r < 0) return 0;
    return 1LL * nCr(n, r) * fact[r] % m;
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
