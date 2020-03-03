#include <bits/stdc++.h>

using namespace std;

template<class C>constexpr int sz(const C&c){return int(c.size());}

using ll=long long;constexpr const char nl='\n',sp=' ';



int main() {

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int max;
    int N;

    cin >> max >> N;
    int cars[N];

    int x = 0;
    int cW = 0;

    for(int i = 0; i < N; i++) {
            int W;
            cin >> W;
            cars[i] = W;

            if(i > 3) {
               cW += W;
               cW -= cars[i - 4];
            } else {
               cW += W;
            }

            if(cW > max)
                  break;

            x++;
    }

    cout << x;


    return 0;

}