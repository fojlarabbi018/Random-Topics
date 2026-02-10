// O(n + m)

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int mod = 1e9 + 7;
int base = 10;
string s, pat;
vector<int> power;
vector<int> ph;

void pow_calc() {
    int n = s.size();
    power[0] = 1;
    for(int i = 1; i <= n; i++) {
        power[i] = power[i - 1] * base; // mod
    }
}
void prefix_hash() {
    ph[0] = s[0] - '0';
    for(int i = 1; i < s.size(); i++) {
        ph[i] = ph[i - 1] * base + (s[i] - '0'); // mod
    }
}
int sub_string(int l, int r) {
    if(l == 0) return ph[r];
    return ph[r] - ph[l - 1] * power[r - l + 1]; // mod
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> pat;
    int y = stoi(pat);
    int n = s.size();
    int m = pat.size();

    power.assign(n + 1, 1);
    ph.assign(n, 0);
    pow_calc();
    prefix_hash();
    // r (i + m - 1) cannot be out of the boundary, <= n - 1;
    for(int i = 0; i + m - 1 < n; i++) {
        int x = sub_string(i, i + m - 1);
        if(x == y) {
            cout << pat << " " << "found at " << i << '\n'; 
        }
    }
    return 0;
}
