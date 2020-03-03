#include <bits/stdc++.h>

using namespace std;

template<class C>constexpr int sz(const C&c){return int(c.size());}

using ll=long long;constexpr const char nl='\n',sp=' ';


int incorrect [1001][1001];
int k, num;
int main ()
{
	   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf ("%d", &k);
    int counter = 1;
    int cnt = 0;
    bool stop = false;
    for (int x = 0; x < k; x++)
    {
        for (int y = 0; y < k; y++, counter++)
        {
            scanf ("%d", &num);
            incorrect [x][y] = num;
            if (counter != num)
            {
                stop = true;
                cnt++;
            }
        }
        if (stop)
        {
            break;
        }
    }
    printf ("%d\n", cnt);
    return 0;
}