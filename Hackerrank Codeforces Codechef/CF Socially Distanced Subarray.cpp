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
	int T;cin>>T;
	while(T-->0){
		int N;cin>>N;
		vector<int>arr(N);
		for(int i=0;i<N;i++)cin>>arr[i];
		vector<int>res;
		bool dir = arr[1]>arr[0] ? 1:0;
		res.push_back(arr[0]);
		for(int i=0;i<N-1;i++){
			//if the next element is a change in direction, add it;
			bool b = arr[i+1]>arr[i] ? 1:0;
			if(b != dir){
				res.push_back(arr[i]);
				dir = b;
			}
		}
		res.push_back(arr[N-1]);
		if(arr.size()==2)cout<<2<<endl;
		else cout<<res.size()<<endl;
		for(int x:res)cout<<x<<" "; cout<<endl;
	}
	return 0;
}
