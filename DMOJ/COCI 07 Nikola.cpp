#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define INF 3e18

int N;
vector<vector<int>>dp;
vector<int>arr;
int search(int sq, int jump) {
	if (sq <= 0 || sq > N)return INT_MAX;
	if (sq == N) { int res = arr[sq]; dp[sq][jump] = res; return res; }
	if (dp[sq ][jump] == -1) {
		int res =  arr[sq]+ min(search(sq - jump, jump), search(sq + jump+1, jump + 1));
		dp[sq][jump] = res;
		return res;
	}
	else return dp[sq][jump];
}

int main() {
	N; cin >> N;
	arr.resize(N+1);
	for (int i = 1; i <= N; i++)cin >> arr[i];
	dp.resize(N+1, vector<int>(N+1,-1));
	cout << search(2, 1) << endl;

	
	
	return 0;
}
