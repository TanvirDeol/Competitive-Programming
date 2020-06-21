#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair <int, int > pi;
#define INF 3e18
 
 
int main() {
	int t;cin>>t;
	while(t-->0){
		ll n;cin>>n;
		vector<char>arr(n);
		pi least = {1,INT_MAX};
		map<pi,vector<int>>mp;
		string s;cin>>s;
		for(int i=0;i<n;i++)arr[i]=s[i];
		vector<pi>pref(n);
		pi cur = {0,0};
		int temp=0;
		mp[cur].push_back(-1);
		for(int i=0;i<n;i++){
			switch(arr[i]){
				case 'L': cur.first--; break;
				case 'R': cur.first++; break;
				case 'D': cur.second--; break;
				case 'U': cur.second++; break;
			}
			if(mp[cur].size()>0){
			//	cout<<"FOUND"<<endl;
				temp = abs(i-*max_element(mp[cur].begin(),mp[cur].end())); 
				if(abs(least.first-least.second)>temp)least = {*max_element(mp[cur].begin(),mp[cur].end())+1,i+1};
				if(temp==2)break;
			}
			mp[cur].push_back(i);
			
		}
		if(least.second-least.first == INT_MAX-1)cout<<"-1"<<endl;
		else cout<<least.first+1<<" "<<least.second<<endl; 
		
	}
	return 0;
}
