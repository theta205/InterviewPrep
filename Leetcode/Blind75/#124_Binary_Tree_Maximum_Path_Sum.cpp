/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN; // worst case
        calc(root,ans); // find ans
        return ans;
    }
    int calc(TreeNode* root, int &ans) {
        if (root == nullptr) return INT_MIN; // return and number under 0
        int curr = root -> val; //  // current node val
        int left = max(calc(root -> left, ans), 0); // only consider if it helps
        int right = max(calc(root -> right, ans), 0); // only consider if it helps
        ans = max(ans, left + right + curr); // if left plus right plus current node is above max update max
        return max(curr + left, curr + right); // return the better current best

    }
};
