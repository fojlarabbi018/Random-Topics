#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e7;
int freq[N];
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // O(n)
    for(int i = 0; i < n; i++) {
        freq[v[i]]++;
    }
    vector<int> ans;
    // O(max)
    for(int i = 1; i < N; i++) {
        if(freq[i] > 0) {
            for(int j = 1; j <= freq[i]; j++) {
                ans.push_back(i);
            }
        }
    }
    // So, overall O(n + max)
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
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


