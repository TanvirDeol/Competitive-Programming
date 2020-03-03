#include <bits/stdc++.h>

using namespace std;

int main() {

	for (int q = 0; q < 10; q++) {
		int n = 0, x = 0, y = 0, z = 0;
		string s;
		getline(cin, s);
		istringstream ss(s);
		ss >> n >> x >> y >> z;

		vector< vector<int> > data;
		vector< vector<int> > ans;
		for (int i = 0; i < n; i++) {
			string inp;
			getline(cin, inp);
			vector<int> nums;
			for (int j = 0; j < inp.size(); j++) {
				nums.push_back(inp[j] - '0');
			}
			data.push_back(nums);
		}
		string emp; getline(cin, emp);
		for (int i = 0; i < n; i++) {
			string inp;
			getline(cin, inp);
			vector<int> nums;
			for (int j = 0; j < inp.size(); j++) {
				nums.push_back(inp[j] - '0');
			}
			ans.push_back(nums);
		}
		getline(cin, emp);

		for (int i = 0; i < data.size(); i++) {
			for (int j = 0; j < data[i].size(); j++) {
				if (data[i][j] == 0) {
					data[i][j] = z;
				}
				else if (data[i][j] % 2 == 0) {
					data[i][j] += x;
				}
				else if (data[i][j] % 2 == 1) {
					data[i][j] -= y;
					if (data[i][j] < 0) {
						data[i][j] = 0;
					}
				}
			}
		}

		vector<string> dataFinal;
		vector<string> ansFinal;
		for (int i = 0; i < data.size(); i++) {
			string str = "";
			for (int j = 0; j < data[i].size(); j++) {
				str += to_string(data[i][j]);
			}
			dataFinal.push_back(str);
			
		}
		for (int i = 0; i < ans.size(); i++) {
			string str = "";
			for (int j = 0; j < ans[i].size(); j++) {
				str += to_string(ans[i][j]);
			}
			ansFinal.push_back(str);
			
		}


		vector <int> mismatch;
		for (int i = 0; i < n; i++) {
			if (dataFinal[i] != ansFinal[i]) {
				mismatch.push_back(i + 1);
			}
		}
		if (mismatch.empty()) {
			cout << "MATCH" << endl;
		}
		else {
			cout << "FAIL: ";
			string op = "";
			for (int i = 0; i < mismatch.size(); i++) {
				op += to_string(mismatch[i]) + ",";
			}
			op = op.substr(0, op.size() - 1);
			cout << op << endl;
		}
	}
	return 0;
}