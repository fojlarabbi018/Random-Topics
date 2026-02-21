#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 1e18;
void solve() {
    vector<ll> v;
    // It will never be overflowed
  
    for(ll p2 = 1; p2 <= INF; p2 *= 2) {
        for(ll p3 = 1; p2 * p3 <= INF; p3 *= 3) {
            for(ll p5 = 1; p2 * p3 * p5 <= INF; p5 *= 5) {
                v.push_back(p2 * p3 * p5); 
            }
        }
    }
    sort(v.begin(), v.end());
   
    cout << "The 1500'th ugly number is ";
    cout << v[1500 - 1] << ".\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
