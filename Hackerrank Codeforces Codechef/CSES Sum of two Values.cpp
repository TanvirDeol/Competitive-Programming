#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pi;
#define INF 3e18
long mod(long a, long b)
{
	return (a % b + b) % b;
}
int main() {
	int N, X;
	cin >> N >> X;
	vector<int>A(N);
	for (int i = 0; i < N; i++)cin >> A[i];
	vector<int>arr = A;
	sort(arr.begin(), arr.end());
	int i = 0, j = N - 1;
	ll sum = arr[i] + arr[j];
	bool found = 0;
	while (i < j) {
		if (sum > X)j--;
		else if (sum < X)i++;
		else if (sum == X) { found = 1; break; }
		sum = arr[i] + arr[j];
	}
	if (found) {
		int idx = find(A.begin(), A.end(), arr[i]) - A.begin()+1;
		int s;
		if(arr[i]==arr[j]) s =  find(A.begin()+idx, A.end(), arr[j]) - A.begin()+1;
		else s =  find(A.begin(), A.end(), arr[j]) - A.begin()+1;
		cout<<idx<<" "<<s<<endl;
	}
	else cout << "IMPOSSIBLE" << endl;
	return 0;
