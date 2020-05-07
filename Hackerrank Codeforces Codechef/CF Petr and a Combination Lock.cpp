#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long mod(long a, long b)
{
	return (a % b + b) % b;
}
bool pos;
void func(vector<int>& arr, int index, int turn) {
	if (index == arr.size()) {
		if (turn % 360 == 0) { pos = true; }
		return;
	}
	func(arr, index + 1, turn + arr[index]); func(arr, index + 1, turn - arr[index]);
}
int main() {
	pos = false;
	ll N; cin >> N;
	vector<int>turns(N);
	for (int i = 0; i < N; i++)cin >> turns[i];
	func(turns, 0, 0);
	if (pos)cout << "YES" << endl; else cout << "NO" << endl;
	return 0;
}