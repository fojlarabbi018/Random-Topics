// ABCABDABCABCABD // (for lps array)
// onionionson (n)
// onions (m)
// O(n + m)

#include<bits/stdc++.h>
using namespace std;
#define ll long long

string s, pat;
vector<int> lps;
void lps_const() {
    int pre = 0;
    int suff = 1;
    lps[0] = 0;
    while(suff < pat.size()) {
        if(pat[pre] == pat[suff]) {
            lps[suff] = pre + 1;
            pre++;
            suff++;
        }
        else {
            if(pre == 0) suff++;
            else pre = lps[pre - 1];
        }

    }
}
int kmp() {
    int first = 0;
    int second = 0;
    while(first < s.size() && second < pat.size()) {
        if(s[first] == pat[second]) {
            first++;
            second++;
        }
        else {
            if(second == 0) first++;
            else second = lps[second - 1];
        }
    }
    if(second == pat.size()) return first - pat.size();
    else return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> pat;
    int m = pat.size();
    lps.assign(m, 0);
    lps_const();
    cout << kmp();
    return 0;
}
