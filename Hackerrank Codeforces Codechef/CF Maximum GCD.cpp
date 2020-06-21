#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define INF 3e18
 
int main() {
	int T; cin >> T;
	while (T-- > 0) {
		int N; cin >> N;
		if (N & 1)N--;
		cout << N / 2 << endl;
	}
	return 0;
}
