#include <iostream>
#include<bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	string s ="";
	string min ="";
	int max = INT_MAX;
	while(s!="Waterloo"){
	int n =0;
	cin>>s>>n;
	if (n<max){
		max = n;
		min = s;
	}

	}
	cout<<min<<"\n";


    return 0;
}