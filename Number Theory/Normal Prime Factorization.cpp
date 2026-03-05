// O(sqrt(n)) ---> For prime
// O(log n) ---> For composite 
// A number n can have max log n primes in the P. Factorization (say all are 2s)
// Simply size of the vector v can be max log n

#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> v;
void prime_fact(int n) {
    for(int i = 2; i * i <= n; i++) { 
        if(n % i == 0) {
            while(n % i == 0) { // Always think n in skeleton view(PF)
                v.push_back(i);
                n /= i;
            }
        }
    }
    
    if(n > 1) v.push_back(n); // When n itself becomes a prime
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    prime_fact(100);
    return 0;
}
