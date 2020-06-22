#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N, K;
vector<int>arr;
vector<int>cows;

bool blow(int rad) {
	vector<pi>dam;
	int cnt = 0; int c = 0;
	for (int i = 0; i < N; i++) {
		if (dam.empty()) {
			dam.push_back({ arr[0],arr[0] + (2 * rad) }); cnt++; c++;
		}
		else {
			if (arr[i] <= dam[dam.size() - 1].second && arr[i] >= dam[dam.size() - 1].first) {
				cnt++;
			}
			else {
				dam.push_back({ arr[i],arr[i] + (2 * rad) }); cnt++; c++;
			}
		}
	}
	return (cnt == N && c<=K);
}
int binSrch(int l, int h) {
	if (l == h) return l;
	if (l + 1 == h) { if (blow(l))return l; else return h; }
	int m = (l + h) / 2;
	if (blow(m))return binSrch(l, m);
	else return binSrch(m + 1, h);
}
int main() {
	ifstream cin("angry.in");
	ofstream cout("angry.out");
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int x; cin >> x; arr.push_back(x);
	}
	sort(arr.begin(), arr.end());

	cout << binSrch(1, arr[arr.size()-1]) << endl;
	return 0;
}
