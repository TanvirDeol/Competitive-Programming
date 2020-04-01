#include <bits/stdc++.h>
using namespace std;


int main()
{
    int N; cin >> N;
    int max = 0; int min = INT_MAX;
    for (int i = 0; i < N; i++) {
        int cur; cin >> cur;
        if (cur < min)min = cur;
        if (cur > max)max = cur;
    }
    cout << abs(max - min) << endl;
    return 0;
}