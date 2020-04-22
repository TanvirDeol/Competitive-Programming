using namespace std;
int main() {
	for (int q = 0; q < 10; q++) {
		int t, n; cin >> t >> n;
		int play = 0;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			if (s == "B") {
				play += t;
			}
			if (play > 0)
				play--;
		}
		cout << play << endl;
	}
	return 0;
}