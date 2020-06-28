#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef pair<int, double> pi;
 
 
int main() {
	int N; cin >> N;
	vector<int>arr(N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	int m = 0; int cnt = 0;
	for (int i = 0; i < N; i++) {
		int idx = upper_bound(arr.begin(), arr.end(), arr[i] + 5)-arr.begin();
		m = max(m, idx - i);
	}
	cout << m << endl;
}
