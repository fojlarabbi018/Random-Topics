#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<int> a;
vector<bool> is_taken;

void rec(int pos) {
    if(pos > n) {
        for(int i = 1; i <= n; i++) {
            if(is_taken[i]) {
                cout << a[i] << " ";
            }
        }
        cout << '\n';
        return;
    }

    is_taken[pos] = false;
    rec(pos + 1);

    is_taken[pos] = true;
    rec(pos + 1);
}

void solve() {
    cin >> n;
    a.resize(n + 1);
    is_taken.resize(n + 1, false);
    for(int i = 1; i <= n; i++) cin >> a[i];

    rec(1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}

/* 
Subsequences follow an awesome recurrence relation
Say you have given an array a = 1, 2, 3, 4, 5 (as we need index, we took same values same as index)
now say you have only 4, 5 then there will be [{}, {5}, {4}, {4, 5}] these seqs
now when you add an extra element like 3 on the left of 4, 5 then the prev 4 remains the same
(seqs without 3) and extra 4 will be created by adding 3 on the left of each seq
*/
