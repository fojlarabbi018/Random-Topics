// Time limit is 300 ms, that's why it needs to handle in a diff way

// Got TLE (see below)
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6 + 5;
bitset<N + 1> is_prime;

void sieve() {
    is_prime.set();
    is_prime[1] = 0;

    for(int i = 2; i * i <= N; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= N; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}

vector<int> ten_pow(10);
void power() {
    int p = 1;
    for(int i = 0; i <= 9; i++) {
        ten_pow[i] = p;
        p *= 10;
    }
}

bool has_zero(int n) {
    while(n > 0) {
        int rem = n % 10;
        if(rem == 0) return true;
        n /= 10;
    }
    return false;
}

bool is_valid(int n) {
    if(has_zero(n)) return false;

    int cnt_digit = floor(log10(n)) + 1;

    while(cnt_digit > 1) {
        int rem = n % ten_pow[cnt_digit - 1];
        if(!is_prime[rem]) return false;
        cnt_digit--;
        n = rem;
    }

    if(!is_prime[n]) return false;
    return true;
}

void solve() {
    int n;
    cin >> n;
    
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(is_prime[i]) {
            if(is_valid(i)) cnt++;
        }
    }

    cout << cnt << '\n';  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();
    power();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}


//==================================//
/// AC one
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6 + 5;
bitset<N + 1> is_prime;

void sieve() {
    is_prime.set();
    is_prime[1] = 0;

    for(int i = 2; i * i <= N; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= N; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}

vector<int> ten_pow(10);
void power() {
    int p = 1;
    for(int i = 0; i <= 9; i++) {
        ten_pow[i] = p;
        p *= 10;
    }
}

bool has_zero(int n) {
    while(n > 0) {
        int rem = n % 10;
        if(rem == 0) return true;
        n /= 10;
    }
    return false;
}

bool is_valid(int n) {
    if(has_zero(n)) return false;

    int cnt_digit = floor(log10(n)) + 1;

    while(cnt_digit > 1) {
        int rem = n % ten_pow[cnt_digit - 1];
        if(!is_prime[rem]) return false;
        cnt_digit--;
        n = rem;
    }

    if(!is_prime[n]) return false;
    return true;
}

vector<int> cnt(N + 1);
void pre() {
    cnt[0] = 0; cnt[1] = 0;
    for(int i = 2; i <= N; i++) {
        if(is_prime[i]) {
            cnt[i] = cnt[i - 1] + is_valid(i);
        }
        else cnt[i] = cnt[i - 1]; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();
    power();
    pre();

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << cnt[n] << '\n';
    }
    return 0;
}
