#include<bits/stdc++.h>
using namespace std;
#define ll long long

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << binpow(1e8 + 9, 1e18, 1e9 + 7);
    return 0;
}
// 908727740
