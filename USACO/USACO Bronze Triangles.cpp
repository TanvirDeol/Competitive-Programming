#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream fout("triangles.out");
    ifstream fin("triangles.in");

    int N; fin >> N;
    vector<int> x; vector<int> y; vector<int> area;
    for (int i = 0; i < N; i++) {
        int ix, iy;
        fin >> ix >> iy;
        x.push_back(ix); y.push_back(iy);
    }
    for (int i = 0; i < N; i++) {
        int b = 0, h = 0;
        int lx = 0, ly = 0;
        for (int j = 0; j < N; j++) {
            if (j == i)continue;
            if (x[j] == x[i]) { h = abs(y[j] - y[i]); if (h > ly)ly = h; }
            else if (y[j] == y[i]) { b = abs(x[j] - x[i]); if (b > lx)lx = b; }
        }
        if (ly != 0 && lx != 0)area.push_back(lx * ly);
    }
    sort(area.rbegin(), area.rend());
    fout << area[0] << endl;
    return 0;
}
