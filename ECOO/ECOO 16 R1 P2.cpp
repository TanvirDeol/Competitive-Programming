#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int main() {
	for (int q = 0; q < 10; q++) {
		int n = 0; cin >> n;
		set<double> nums;
		for (int i = 0; i < n; i++) {
			double inp=0; cin >> inp;
			nums.insert(inp);
		}

		double targets[5] = {0};
		for (int i = 0; i < 5; i++) {
			double inp = 0; cin >> inp;
			targets[i] = inp;
		}

		bool ans[5]={false};
		for(int i =0;i<5;i++){
			for (int j : nums) {
				for (int k : nums) {
					if (nums.count(targets[i] / j / k) != 0) { ans[i] = true; }
					else if (nums.count(targets[i] / j - k) != 0) { ans[i] = true; }
					else if (nums.count((targets[i] - j) / k) != 0) { ans[i] = true;}
					else if (nums.count(targets[i] - j - k) != 0) { ans[i] = true;}
				}
			}
		}
		for (int i = 0; i < 5; i++) {
			if (ans[i]==true) {
				cout << "T";
			}
			else {
				cout << "F";
			}
		}
		cout << endl;
	}
	return 0;
}