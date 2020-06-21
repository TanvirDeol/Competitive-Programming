#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, int > pi;
#define INF 3e18
 
 
int main() {
	ll n,x;
	cin>>n>>x;
	vector<ll>arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr.begin(),arr.end());
	ll sum =0;
	for(int i=0;i<n;i++){
		sum+=arr[i]*x;
		if(x>1)x--;
	}
	cout<<sum<<endl;
	return 0;
}
