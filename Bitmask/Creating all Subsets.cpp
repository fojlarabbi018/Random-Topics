// It is "creating all subsequences" also, because we are iterating from 0th bit to last bit
// So, first element will come first

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; 
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
	// Simply imagine the array indexing from right to left (elements of the array also from right to left)
	// (it helps to match the bit indexing for comparing set bits to array elements)
    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++) {
            if(mask >> i & 1) cout << a[i] << " ";
        }
        cout << '\n';
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
