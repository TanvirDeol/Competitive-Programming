/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	int sum;
public:
	void search(TreeNode* node, int& L, int& R) {
		if (node->val >= L && node->val <= R)sum += node->val;
		if (node->left != NULL) {
			search(node->left, L, R);
		}
		if (node->right != NULL) {
			search(node->right, L, R);
		}
	}
	int rangeSumBST(TreeNode* root, int L, int R) {
		sum = 0;
		if (root->val >= L && root->val <= R)sum += root->val;

		if (root->left != NULL) {
			search(root->left, L, R);
		}
		if (root->right != NULL) {
			search(root->right, L, R);
		}
		return sum;
	}
};