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
	int G;cin>>G;
	double ans = 0;
	double e,p;
	for(int i=0;i<G;i++){
		cin >>e>>p;
		if(e==0 && i>=1)continue;
		if(e==p){cout<<0<<endl; return 0;}
		
		if(i==0){
			if(e==0){ans=1;continue;}
			ans+=1-(e/p);
		}
		else {ans*=1-(e/p);}
		
	}
	
	cout<<setprecision(6)<<fixed<<ans<<endl;
	
	return 0;
}
