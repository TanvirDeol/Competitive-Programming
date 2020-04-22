class Solution {
    vector<pair<int, int>> data;
public:
    void search(TreeNode* root, int level) {
        if (root->left == NULL && root->right == NULL && root->val != NULL)
        {
            data.push_back(make_pair(level, root->val));
            //  cout << data[data.size() - 1].first << endl;
        }
        else {
            if (root->left != NULL) {
                search(root->left, level + 1);
            }
            if (root->right != NULL) {
                search(root->right, level + 1);
            }
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0; int level = 0;
        if (root->left == NULL && root->right == NULL && root->val != NULL)
        {
            data.push_back(make_pair(0, root->val));
            //  cout << data[data.size() - 1].first << endl;
        }
        else {
            if (root->left != NULL) {
                search(root->left, level + 1);
            }
            if (root->right != NULL) {
                search(root->right, level + 1);
            }
        }
        sort(data.begin(), data.end());
        int max = data[data.size() - 1].first;

        for (int i = data.size() - 1; i >= 0; i--) {
            if (data[i].first == max)sum += data[i].second;
        }
        return sum;
    }
};