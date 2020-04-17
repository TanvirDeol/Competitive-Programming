#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<int>arr;
vector<int> ans;


void func(vector<int> sim, int i, int lights, int rec) {

	if (i == sim.size() - 1) {
		int cons = 0;
		for (int j = 0; j < sim.size(); j++) {
			if (sim[j] == 1)cons++;
			if (sim[j] == 0) {
				if (cons >= 4) {
					for (int k = j - cons; k < j; k++)sim[k] = 0;
				}cons = 0;
			}
			if (j == sim.size() - 1) {
				if (cons >= 4) {
					for (int k = j - cons + 1; k <= j; k++)sim[k] = 0;
				}cons = 0;
			}
		}

		if (accumulate(sim.begin(), sim.end(), 0) == 0) {
			ans.push_back(lights);
		}

		//for (int i = 0; i < sim.size(); i++)cout << sim[i] << " ";
		//cout << endl; 
		if (rec == 0)
			func(sim, 0, lights, rec + 1);
		return;
	}
	if (sim[i] == 1)func(sim, i + 1, lights, rec);
	else {
		func(sim, i + 1, lights, rec);
		sim[i] = 1;
		int cons = 0;
		for (int j = 0; j < sim.size(); j++) {
			if (sim[j] == 1)cons++;
			if (sim[j] == 0) {
				if (cons >= 4) {
					for (int k = j - cons; k < j; k++)sim[k] = 0;
				}cons = 0;
			}
			if (j == sim.size() - 1) {
				if (cons >= 4) {
					for (int k = j - cons + 1; k <= j; k++)sim[k] = 0;
				}cons = 0;

			}
		}
		func(sim, i + 1, lights + 1, rec);
	}
}

int main()
{

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		arr.push_back(x);
	}
	func(arr, 0, 0, 0);
	cout << *min_element(ans.begin(), ans.end()) << endl;


	return 0;
}