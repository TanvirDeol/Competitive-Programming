#include <bits/stdc++.h>
using namespace std;

int main() {
	int G, P; cin >> G >> P;
	int* planes = new int[P];

	bool* gates = new bool[G + 1];
	for (int i = 0; i <= G; i++) {
		gates[i] = 0;
	}

	for (int i = 0; i < P; i++) {
		int inp;
		cin >> inp;
		planes[i] = inp;
	}

	int count = 0;
	int docked = 0;
	bool stop = false;


	for (int i = 0; i < P; i++) {
		int cur = planes[i];

		for (int j = cur; j > 0; j--) {

			if (j == docked) { stop = true; break; }

			if (j == 1 && !gates[j]) { gates[j] = 1; count++; stop = false; docked = cur; break; }
			else if (j == 1 && gates[j]) docked = cur;

			if (gates[j] == 0) { gates[j] = 1; count++; stop = false; break; }
			else { stop = true; }
		}
		if (stop) break;
	}
	cout << count << endl;
	return 0;
}
