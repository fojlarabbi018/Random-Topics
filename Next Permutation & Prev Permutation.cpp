#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end()); // This is a must

    do {
        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
    } while(next_permutation(a.begin(), a.end()));

    // false has been returned in the last check 
    // because when it doesn't find the next permutation then
    // it returns false and gives the first permutation again (the smallest one)
    cout << '\n';
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    prev_permutation(a.begin(), a.end()); 
    // This will also return false, and give the last one again
    cout << '\n';
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}
/*
3
1 2 3
*/
