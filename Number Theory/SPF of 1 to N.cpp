// The last if condition is very important (otherwise overwriting will happen)
const int N = 2e5 + 5;
vector<int> spf(N + 1);

void pre_spf() {   
    for(int i = 2; i <= N; i++) {
        spf[i] = i;
    }
    for(int i = 2; i * i <= N; i++) {
        if(spf[i] == i) {
            for(int j = 2 * i; j <= N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pre_spf();
    return 0;
}
