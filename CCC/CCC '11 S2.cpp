#include <iostream>

using namespace std;


int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	char c;
	char inp[n];
	int count =0;
	for (int i =0;i<n;i++){
		cin>>inp[i];
	}
	for (int i =0;i<n;i++){
		cin>>c;
		if (inp[i]==c){
			count++;
		}
	}
	cout<<count<<"\n";
    return 0;
}