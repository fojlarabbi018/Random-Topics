// Answering the queries
// Worst case ---> (sqrt(n) - 1) + (sqrt(n) - 2) + (sqrt(n) - 1) = 3*sqrt(n) - 4
// (when l = 1 and r = n-2)...... whatever, it's asymptotically sqrt(n)
// O(q*sqrt(n))

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Preprocessing
    int len = ceil(sqrt(n + .0)); 
    // len is the size of the block and the number of blocks
    vector<int> block(len, 0);
    for(int i = 0; i < n; i++) {
        block[i / len] += a[i];
    }

    int q;
    cin >> q;
    for(int p = 1; p <= q; p++) {
        int l, r;
        cin >> l >> r;
        int sum = 0;
        for (int i = l; i <= r; ) {
            if (i % len == 0 && i + len - 1 <= r) {
                // if the whole block starting at i belongs to [l, r]
                sum += block[i / len];
                i += len;
            }
            else {
                sum += a[i];
                i++;
            }
        }
        cout << sum <<"\n";
    }
    return 0;
}
