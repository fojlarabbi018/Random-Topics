#include<bits/stdc++.h>
using namespace std;
#define ll long long

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

void prime_fact(int n) {
    vector<int> v;
    while(n > 1) {
        v.push_back(spf[n]);
        n /= spf[n];
    }
    for(auto x: v) cout << x << " ";
    cout << '\n';  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pre_spf();
    prime_fact(112);
    return 0;
}
