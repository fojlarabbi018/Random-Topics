#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Total (log n)^2 * sqrt(n)
bool is_prime(ll n) {
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

ll next_prime(ll n) {
    ll i = n + 1;
    while(1) {
        if(is_prime(i)) return i;
        else i++;
    }
    // Only (log n)^2 iterations needed
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    cout << next_prime(n);
    return 0;
}
