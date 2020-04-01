#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int X; cin >> X;
    for (int q = 0; q < X; q++) {
        ll N, A, B, T; cin >> N >> A >> B >> T;
        ll i = 0; ll score = -(N * B);
        if (score >= T) {
            cout << 0 << "\n"; continue;
        }
        if (N * A < T) {
            cout << -1 << "\n"; continue;
        }

        i = T - (score);
        i = i / (A + B);


        cout << i + 1 << "\n";
    }
    return 0;
}