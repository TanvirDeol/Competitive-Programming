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
		int n,k; cin>>n>>k;
		vector<int>A(n); vector<int>B(n);
		for(int i=0;i<n;i++)cin>>A[i];
		for(int i=0;i<n;i++)cin>>B[i];
		ll sum =0;
		int small=0,big=0;
		while(k-->0){
			small = min_element(A.begin(),A.end()) -A.begin();
			big = max_element(B.begin(),B.end()) -B.begin();
			if(A[small]<B[big])	swap(A[small],B[big]);
			else break;
		}
		sum = accumulate(A.begin(),A.end(),0);
		cout<<sum<<endl;
	}
	
	return 0;
 
}
