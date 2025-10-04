#include<bits/stdc++.h>
using namespace std;
int n; 
// A good example of global declaration
int arr[100];
bool is_taken[100]={false};
void sub_sq(int pos){
	// Base case
	if(pos>n){
		for(int i=1;i<=n;i++){
			if(is_taken[i]) cout<<arr[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	is_taken[pos]=false;
	sub_sq(pos+1);
	// Not taking the current element
	// Without taking that element, compute all possible combinations
	// for the next whole part

	// After that, take that element and do the same
	is_taken[pos]=true;
	sub_sq(pos+1);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sub_sq(1);
	
	return 0;
}
