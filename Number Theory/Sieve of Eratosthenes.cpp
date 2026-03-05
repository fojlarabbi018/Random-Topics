// It's just a pre-computation to save all the primes till a number
// O(n*log log n) ---> for i to N
// O(n*log log sqrt(n)) ---> i to sqrt(N)

// See the last number is N, and we are eliminating the numbers by its divisors
// So, for last N, only till sqrt(N) is enough to check. Because after that no
// no divisor will be found that can eliminate N

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6 + 5;
vector<int> prime;
bitset<N> is_prime;

void sieve() {
    is_prime.set();
    is_prime[1] = 0;
    for(int i = 2; i * i < N; i++) {
        if(is_prime[i]) {
            for(int j = 2 * i; j < N; j += i) {
                is_prime[j] = 0;
            }
        }
    }
  
    for(int i = 2; i < N; i++) {
        if(is_prime[i]) prime.push_back(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    return 0;
}
