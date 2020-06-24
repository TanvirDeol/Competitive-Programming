#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
 
int main() {
	int T; cin >> T;
	while (T-- > 0) {
		vector<pi>lens;
		int N; cin >> N; string s; cin >> s;
		int st=-1, end=-1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1' && st==-1)st = i;
			if (s[i] == '0') {
				if (i == s.size() - 1) {
					end = i; 
					if (st > -1 && end > st) { lens.push_back({ st,end }); st = -1; }
				}
				else if(i<s.size()-1){
					if (s[i + 1] == '1') {
						end = i;
						if (st > -1 && end > st) {lens.push_back({ st,end }); st = -1;}
					}
				}
			}
		}
		string temp = s;
		if (!lens.empty()) {
			st = lens[0].first; end = lens[lens.size() - 1].second;
			temp.replace(st, end - st+1, "0");
		}
		cout << temp << endl;
	}
	return 0;
}
