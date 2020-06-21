#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair <int, int > pi;
#define INF 3e18
 
 
int main() {
	int b;cin>>b;
	vector<int>by(b);
	for(int i=0;i<b;i++)cin>>by[i];
	int g;cin>>g;
	vector<int>gr(g);
	for(int i=0;i<g;i++)cin>>gr[i];
	sort(by.begin(),by.end());
	sort(gr.begin(),gr.end());
	int index =0,cnt=0;
	if(g<b){
		for(int i=0;i<g;i++){
			while(true){
				if(index==b)break;
				//cout<<gr[i]<<" "<<by[index]<<" "<<index<<endl; 
				if(abs(gr[i]-by[index])<=1){cnt++;index++;break;}
				else if(abs(gr[i]-by[index])>1 && gr[i]<by[index])break;
				else index++;
			}
		}
	}
	else{
		for(int i=0;i<b;i++){
			while(true){
				if(index==g)break;
				//cout<<by[i]<<" "<<gr[index]<<" "<<index<<endl; 
				if(abs(by[i]-gr[index])<=1){cnt++; index++;break;}
				else if(abs(by[i]-gr[index])>1 && by[i]<gr[index])break;
				else index++;
			}
		}	
	}
	cout<<cnt<<endl;
	
	return 0;
}
