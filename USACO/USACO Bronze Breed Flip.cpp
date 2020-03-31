#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream fout("breedflip.out");
    ifstream fin("breedflip.in");

    int N; fin >> N;
    string A, B;
    fin >> A >> B;
    int* arr = new int[N];
    int count = 0;
    bool swch = false;
    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) {
            if (swch) { continue; }
            else swch = true; count++;
        }
        else {
            if (swch) { swch = false; }
        }
    }
    fout << count << endl;
    return 0;
}
