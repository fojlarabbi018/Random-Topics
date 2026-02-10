#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a (n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    // preprocessing
    int len = ceil(sqrt (n + .0)); // size of the block and the number of blocks
    vector<int> b (len, 0);
    int max_b = INT_MIN;
    for (int i=0; i<n; i++) {
        // The most important part
        if(i % len == 0){
            max_b = INT_MIN;
        }
        if(a[i] > max_b) {
            max_b = a[i];
            b[i / len] = max_b;
        }
    }
    for(int i=0; i<len; i++){
        cout<<b[i]<<" ";
    }

    int q;
    cin >> q;
    // answering the queries
    for (int p=1; p<=q; p++) {
        int l, r;
        cin >> l >> r;
        int max_q = INT_MIN;
        for (int i=l; i<=r; ) {
            if (i % len == 0 && i + len - 1 <= r) {
                // if the whole block starting at i belongs to [l, r]
                if(b[i / len] > max_q) {
                    max_q = b[i / len];
                }
                i += len;
            }
            else {
                if(a[i] > max_q) {
                    max_q = a[i];
                }
                i++;
            }
        }
        cout << max_q <<"\n";
    }
    return 0;
}
