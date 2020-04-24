#include <bits/stdc++.h>
using namespace std;
int maxO;
vector<int>fish;
vector<int>leaf;
void func(char move, vector<int>data) {
	if (move == 'L') {
		if (data[0] < leaf[0] || data[2] < leaf[1])return;
		else {
			data[0] -= leaf[0]; data[1] += leaf[3]; data[2] -= leaf[1]; data[3] += leaf[2];
			if (data[1] > maxO)maxO = data[1];
			func('L', data); func('F', data);
		}
	}
	else if (move == 'F') {
		if (data[3] < fish[0] || data[1] < fish[1])return;
		else {
			data[3] -= fish[0]; data[1] -= fish[1]; data[2] += fish[3]; data[0] += fish[2];
			func('L', data); func('F', data);
		}
	}
}
void helper(vector<int>& data) {
	if (data[1] > maxO)maxO = data[1];
	func('L', data);
	func('F', data);
}
int main() {
	for (int q = 0; q < 10; q++) {
		maxO = 0;
		vector<int>data(4);
		for (int i = 0; i < 4; i++)cin >> data[i];
		for (int i = 0; i < 4; i++) {
			int x; cin >> x; leaf.push_back(x);
		}
		for (int i = 0; i < 4; i++) {
			int x; cin >> x; fish.push_back(x);
		}
		helper(data);
		cout << maxO << endl;
		fish.clear(); leaf.clear();
	}
	return 0;
}