#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
 
int main() {
	int T; cin >> T;
	while (T-- > 0) {
		int N, K;
		cin >> N >> K;
		vector<int>A(N);
		vector<int>W(K);
		vector<vector<int>>nums(K, vector<int>());
		for (int i = 0; i < N; i++)cin >> A[i];
		for (int i = 0; i < K; i++)cin >> W[i];
		sort(A.rbegin(), A.rend());
		sort(W.begin(), W.end());
		int idx = 0;
		for (int i = 0; i < K; i++) {
			nums[i].push_back(A[i]);
		}
		A.erase(A.begin(), A.begin() + K);
		for(int i=0;i<K;i++){
			for (int j = 1; j < W[i]; j++) {
				nums[i].push_back(A[0]); A.erase(A.begin());
			}
		}
		ll sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += *max_element(nums[i].begin(), nums[i].end()) + *min_element(nums[i].begin(), nums[i].end());;
		}
		/*for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < nums[i].size(); j++) {
				cout << nums[i][j] << " ";
			}cout << endl;
		}*/
		cout << sum << endl;
	}
	return 0;
}
