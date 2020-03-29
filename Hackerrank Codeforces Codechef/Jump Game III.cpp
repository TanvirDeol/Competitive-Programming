#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<pair<int, int>> q; vector<bool> vis(arr.size(), false);
        q.push(make_pair(start, arr[start]));
        while (!q.empty()) {
            int index = q.front().first;
            int val = q.front().second;
            if (val == 0)return true;
            q.pop();
            vis[index] = true;

            if (index + arr[index] > arr.size() - 1 || index + arr[index] < 0 || vis[index + arr[index]]) {}
            else {
                pair<int, int> one = make_pair(index + arr[index], arr[index + arr[index]]);
                if (one.second == 0)return true;
                q.push(one);
            }

            if (index - arr[index] > arr.size() - 1 || index - arr[index] < 0 || vis[index - arr[index]]) {}
            else {
                pair<int, int> two = make_pair(index - arr[index], arr[index - arr[index]]);
                if (two.second == 0)return true;
                q.push(two);
            }

        }
        return false;
    }
};
int main()
{
    vector<int> arr = { 4,2,3,0,3,1,2 };
    Sol obj;
    cout << obj.canReach(arr, 5) << endl;


}
