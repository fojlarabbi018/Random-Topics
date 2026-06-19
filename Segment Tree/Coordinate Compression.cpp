void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    // Coordinate Compression
    vector<int> com = a;
    sort(com.begin(), com.end());
    auto it = unique(com.begin(), com.end());
    com.erase(it, com.end());
    
    for(int i = 0; i < n; i++) {
        a[i] = lower_bound(com.begin(), com.end(), a[i]) - com.begin() + 1;
    }
}
