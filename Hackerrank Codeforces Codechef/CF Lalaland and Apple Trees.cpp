#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
 
ll m;
void func(vector<pi>A, vector<bool>vis, int dir, int pos) {
	ll sum = 0;
	bool b = 0;
	while (true) {
		if (dir == 0) {
			b = 0;
			for (int i = pos; i < A.size(); i++) {
				if (!vis[i]) {
					b = 1;
					sum += A[i].second; vis[i] = 1; m = max(m, sum);
					dir = 1; pos = i; break;
				}
			}
		}
		else {
			b = 0;
			for (int i = pos; i >=0; i--) {
				if (!vis[i]) {
					b = 1;
					sum += A[i].second; vis[i] = 1; m = max(m, sum);
					dir = 0; pos = i; break;
				}
			}
 
		}
		if (!b)break;
	}
}
int main() {
	//dir =1 is left and dir = 0 is right
	m = 0;
	int N; cin >> N;
	vector<pi>arr(N+1);
	vector<bool>vis(N+1, 0);
	arr[0] = { 0,0 };
	for (int i = 1; i <= N; i++) {
		int x, a; cin >> x >> a;
		arr[i] = { x,a };
	}
	sort(arr.begin(), arr.end());
	int idx = -1;
	for (int i = 0; i <= N; i++) {
		if (arr[i].first == 0 && arr[i].second == 0) { idx = i; break; }
	}
	vis[idx] = 1;
	func(arr, vis, 0, idx);
	func(arr, vis, 1, idx);
	cout << m << endl;
 
	return 0;
}
