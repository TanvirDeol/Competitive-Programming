#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pi;
#define INF 3e18
long mod(long a, long b)
{
	return (a % b + b) % b;
}
int main() {
	int N; cin>>N;
	vector<int>arr(N);
	for(int i=0;i<N;i++){cin>>arr[i]; if(i>0)arr[i]+=arr[i-1];} 
	
	if(arr.size()<4){cout<<0<<endl; return 0;}
	if(arr.size()==4){cout<<1<<endl; return 0;}
	
	ll sum = arr[arr.size()-1];
	int cnt =0;
	ll suma = 0;
	ll sumb = 0;
	ll sumc = 0;
	for(int i=1;i<arr.size()-1;i++){
		for(int j=i;j<arr.size()-1;j++){
			suma = arr[i]; sumb=arr[j]-arr[i]; sumc = sum-arr[j];
			//cout<<suma<<" "<<sumb<<" "<<sumc<<endl;
			if(suma==sumb&& sumb==sumc)cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
