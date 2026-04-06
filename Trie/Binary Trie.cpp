#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    Node* next[2];
    Node() {
        for(int i = 0; i < 2; i++) {
            next[i] = NULL;
        }
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(int num) { // O(32)
        Node* cur = root;
        for(int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(cur->next[bit] == NULL) {
                cur->next[bit] = new Node();
            }
            cur = cur->next[bit];
        }
    }

    int get_max_xor(int num) { // O(32)
        Node* cur = root;
        int ans = 0;
        for(int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int want = bit ^ 1;

            if(cur->next[want] != NULL) {
                ans |= (1 << i);
                cur = cur->next[want];
            }
            else cur = cur->next[bit];
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    Trie t;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        t.insert(a[i]);
    }

    int mx = INT_MIN;
    for(int i = 0; i < n; i++) {
        int cur_mx = t.get_max_xor(a[i]);
        mx = max(mx, cur_mx);
    }

    cout << mx << '\n';   
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
