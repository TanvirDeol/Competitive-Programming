#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef pair<int, double> pi;
 
 
int main() {
	int N; cin >> N;
	vector<int>arr(N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	int sz; bool mx = 0;
	sz = N / 2;
	if (N & 1) mx = 1;
	int b = 0;
	vector<int>A;
	vector<int>B;
	for (int i = 0; i < sz*2; i++) {
		int x = arr[i];
		if (!b) { A.push_back(x); b = 1; }
		else { B.push_back(x); b = 0; }
	}
	sort(A.begin(), A.end());
	sort(B.rbegin(), B.rend());
	for (int i = 0; i < A.size(); i++) cout << A[i] << " ";
	if (mx)cout << arr[arr.size() - 1] << " ";
	for (int i = 0; i < B.size(); i++) cout << B[i] << " ";
	cout << endl;
}
