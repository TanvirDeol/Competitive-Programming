#include <bits/stdc++.h>
using namespace std;
#define ll  long long

void print(int* bitTree, int n) {
	for (int i = 1; i <= n; i++) {
		cout << bitTree[i] << " ";
	}cout << endl;
}
ll getSum(ll* bitTree, int index) {
	long long sum = 0;
	while (index > 0) {
		sum += bitTree[index];
		index -= index & (-index);
	}
	return sum;
}


void update(ll* bitTree, ll sz, ll index, ll val) {

	index++;
	while (index <= sz) {
		bitTree[index] += val;
		index += index & (-index);
	}
}


ll* construct(ll* arr, ll sz) {

	long long* bitTree = new long long[sz + 1];
	for (int i = 1; i <= sz; i++) {
		bitTree[i] = 0;
	}

	for (int i = 0; i < sz; i++) {
		update(bitTree, sz, i, arr[i]);
	}

	return bitTree;
}


int main() {
	int n = 0, m = 0;
	cin >> n >> m;
	ll* arr = new ll[n];
	vector<ll> order;

	for (int i = 0; i < n; i++) {
		ll inp = 0; cin >> inp;
		arr[i] = inp;
		order.push_back(inp);
	}
	ll* bitTree = construct(arr, n);
	//print(bitTree, n);
	sort(order.begin(), order.end());


	string emp; getline(cin, emp);

	for (int i = 0; i < m; i++) {
		string s; getline(cin, s);
		istringstream ss(s.substr(1));

		if (s[0] == 'C') {
			ll x = 0, v = 0;
			ss >> x >> v;

			update(bitTree, n, x - 1, v - arr[x - 1]);

			int point = find(order.begin(), order.end(), arr[x - 1]) - order.begin();

			arr[x - 1] = v;


			order.erase(order.begin() + point);
			ll idx = lower_bound(order.begin(), order.end(), v) - order.begin();
			order.insert(order.begin() + idx, v);


			//	print(bitTree, n);
		}
		else if (s[0] == 'Q') {
			ll v = 0; ss >> v;

			ll idx = upper_bound(order.begin(), order.end(), v) - order.begin();

			cout << idx << endl;
			//	print(bitTree, n);
		}
		else if (s[0] == 'S') {
			ll l = 0, r = 0;
			ss >> l >> r;
			ll ans = getSum(bitTree, r) - getSum(bitTree, l - 1);
			cout << ans << endl;
			//	print(bitTree, n);
		}
	}


	return 0;
}