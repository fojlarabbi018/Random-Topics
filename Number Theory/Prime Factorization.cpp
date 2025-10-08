#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> v;
    int i = 2;
    while(n > 1) {
        if(n % i == 0) { 
            // n will never be divided by 4 or 6 or 9.....
            // Because 2 will come before 4, 8, .... and 3 before 9, ...
            v.push_back(i); // i is guaranteed to be prime
            n = n / i; // Quotient
            i = 2;
        } 
        else i++;
    }
    sort(v.begin(), v.end());
    for(auto i: v) {
        cout << i << " ";
    }
    cout << '\n';
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
