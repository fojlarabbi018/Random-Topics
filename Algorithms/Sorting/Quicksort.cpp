#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
vector<int> a(N);

int partition(int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quick_sort(int low, int high) {
    if(low >= high) return;
    int pvt_index = partition(low, high);
    quick_sort(low, pvt_index - 1);
    quick_sort(pvt_index + 1, high);
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    quick_sort(0, n - 1);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
 
    return 0;
}
