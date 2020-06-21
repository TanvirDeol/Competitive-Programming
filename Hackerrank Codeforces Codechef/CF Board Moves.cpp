#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < string,ll> pi;
#define INF 3e18
long mod(long a, long b)
{
	return (a % b + b) % b;
}
 
int main(){
	int t;cin>>t;
	while(t-->0){
		ll n; cin>>n;
		if(n==1){cout<<0<<endl;continue;}
		ll sum=0;
		while(n>1){
			ll add = ((2*n) +2*(n-2))*floor(n/2);
			sum+=add;
			n-=2;
		}
		cout<<sum<<endl;
	}
	return 0;
}
