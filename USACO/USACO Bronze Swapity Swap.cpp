#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream fout("swap.out");
    ifstream fin("swap.in");
    int N, K, Ai, An, Bi, Bn;
    fin >> N >> K >> Ai >> An >> Bi >> Bn;
    int rem = 1;
    vector<int>nums(N);
    iota(nums.begin(), nums.end(), 1);
    vector<int>init(N);
    iota(init.begin(), init.end(), 1);
    vector<int>real(N);
    iota(real.begin(), real.end(), 1);
    reverse(nums.begin() + Ai - 1, nums.begin() + An);
    reverse(nums.begin() + Bi - 1, nums.begin() + Bn);
    int count = 0;
    bool cont = false;

    for (int i = 0;; i++) {
        count++;
        vector<int>temp(N);
        for (int j = 0; j < N; j++) {
            int cur = nums[j];
            temp[j] = real[cur - 1];
        }
        real = temp;
        if (count == K) {
            cont = true; break;
        }
        if (real == init)break; else rem++;
    }

    if (!cont) {
        K = K % rem;
        for (int i = 0; i < K; i++) {
            vector<int>temp(N);
            for (int j = 0; j < N; j++) {
                int cur = nums[j];
                temp[j] = init[cur - 1];
            }
            init = temp;
        }
        for (int n : init) { fout << n << endl; }
    }
    else {
        for (int n : real) { fout << n << endl; }
    }
    return 0;
}
