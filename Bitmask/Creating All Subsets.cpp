#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int mask=0; mask<(1<<n); mask++){
		for(int i=0;i<n;i++){
			if(mask>>i & 1){ // Checking whether ith bit is on or off
				cout<<arr[n-1-i]<<" ";
				// Remember bit indexing is from right to left
				// which is opposite to arr indexing
				// i is giving the position of bit...
			}
		}
		cout<<"\n";
	}
	return 0;
}
// Output for --> 1 2 3
/*
empty
  3 
  2 
  3 2 
  1 
  3 1 
  2 1 
  3 2 1  */
