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


////<======= gcd =======>

ll mygcd(ll a, ll b) {
    while(b != 0) {
        ll rem = a % b;
        a = b;
        b = rem;
    }
    return a;
} 


////<======= sieve =======>

const int N = 2e5 + 10;
vector<int> prime;
bitset<N + 1> b(0); // Both fast and memory efficient 
void sieve() {
    for(int i = 2; i*i <= N; i++) {
        if(b[i] != 1) {
            for(int j = i*i; j <= N; j += i) {
                b[j] = 1;
            }
        }
    }
    for(int i = 2; i <= N; i++) {
        if(b[i] != 1) prime.push_back(i);
    }

}


//// <======= spf & prime factorization =======>

// The last if condition is very important (otherwise overwriting will happen)
const int N = 2e5 + 10;
vector<int> spf(N + 1);

void pre_spf() {   
    for(int i = 2; i <= N; i++) {
        spf[i] = i;
    }
    for(int i = 2; i*i <= N; i++) {
        if(spf[i] == i) {
            for(int j = i*i; j <= N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }

}

void prime_fact(int n) {
    vector<int> v;
    while(n > 1) { // Approximately less than O(log n)
        v.push_back(spf[n]);
        n /= spf[n];
    }
    for(auto x: v) cout << x << " ";
    cout << '\n';
    
}


////<======= Binary Exponentiation =======>

const int N = 1e6 + 5, m = 1e9 + 7;
int binpow(ll a, ll n, int m) { // O(log n)
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

const int N = 2005, m = 1e9 + 7;

int C[N][N], fact[N];
void prec() { // O(n^2)
  for (int i = 0; i < N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % m;
    }
  }
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
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

    pre_fact();
    cout << nCr(5, 3);
    return 0;
}
