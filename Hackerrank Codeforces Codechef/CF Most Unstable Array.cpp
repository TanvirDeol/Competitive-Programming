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
		ll n,m;cin>>n>>m;
		if(n==1){cout<<0<<endl;continue;}
		if(n==2){cout<<m<<endl; continue;}
		else cout<<m*2<<endl;
	}
	
	return 0;
 
}
