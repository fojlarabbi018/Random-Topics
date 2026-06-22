#include<bits/stdc++.h>
using namespace std;
#define ll long long

// m can be any number (need not to be a prime)
ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll g = extended_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

ll mod_inverse(ll a, ll m) {
    ll x, y;
    ll g = extended_gcd(a, m, x, y);

    if(g != 1) return -1; // inverse doesn't exist

    return (x % m + m) % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << mod_inverse(3, 7) << '\n'; // 5
}
