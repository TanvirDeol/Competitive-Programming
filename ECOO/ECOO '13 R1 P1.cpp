#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int n = 0; cin >> n;
	string inp;
	int late = 0; int line = 0;

	while (inp.compare("EOF") != 0) {
		cin >> inp;
		if (inp == "TAKE") {
			n++; late++; line++;
			if (n > 999) {
				n = 1;
			}
		}
		else if (inp == "SERVE") {
			line--;
		}
		else if (inp == "CLOSE") {
			cout << late << " " << line << " " << n<<endl;

			late = 0; line = 0;
		}

	}
	return 0;
}