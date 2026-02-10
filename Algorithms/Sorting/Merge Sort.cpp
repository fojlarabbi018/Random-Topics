#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
vector<int> a(N);

vector<int> merge(vector<int> &l, vector<int> &r) {
    int n = l.size(), m = r.size();
    vector<int> ans;
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(l[i] <= r[j]) ans.push_back(l[i++]);
        else ans.push_back(r[j++]);
    }

    while(i < n) ans.push_back(l[i++]);
    while(j < m) ans.push_back(r[j++]);
    
    return ans;
}

vector<int> merge_sort(int low, int high) {
    if(low == high) return {a[low]};
    int mid = (low + high) / 2;
    vector<int> left = merge_sort(low, mid);
    vector<int> right = merge_sort(mid + 1, high);

    return merge(left, right);
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    a = merge_sort(0, n - 1);
    for(int i = 0; i < n; i++) cout << a[i];
 
    return 0;
}
