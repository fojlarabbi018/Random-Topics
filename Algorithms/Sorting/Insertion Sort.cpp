#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int temp, j;
    for(int i = 1; i < n; i++) {
        if(v[i - 1] > v[i]) {
            temp = v[i]; // Will be compared to the previous elements
            j = i - 1;
            while(j >= 0 && v[j] > temp) {
                v[j + 1] = v[j];
                j--;
            }
            v[j + 1] = temp;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
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


