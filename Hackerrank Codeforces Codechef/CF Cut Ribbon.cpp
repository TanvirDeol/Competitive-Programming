#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
#define INF 3e18
long mod(long a, long b)
{
	return (a % b + b) % b;
}
 
 
int main(){
	int n,a,b,c;
	cin>>n>>a>>b>>c;	
	vector<int>dp(n+1,0);
	vector<int>lens ={a,b,c};
	for(int i=1;i<=n;i++){
		for(int j=0;j<lens.size();j++){
		if(i>=lens[j]){
			if(i-lens[j]==0) dp[i]= max(dp[i],dp[i-lens[j]]+1);
			else if(dp[i-lens[j]]>0)dp[i]= max(dp[i],dp[i-lens[j]]+1);
		}
		}
	}
	//for(int r:dp)cout<<r<<" "; cout<<endl;
	cout<<dp[n]<<endl;
	return 0;
}	
