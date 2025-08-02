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
    bool isValidBST(TreeNode* root) {
        double max = INT_MAX, min = INT_MIN; // setup and min and max that are greater than constraints 
        return validate(root, --min, ++max);
    }
    bool validate(TreeNode* root, double min, double max) {
        if (root == nullptr) return true; // base case
        if (root->val >= max || root->val <= min) return false; // if not valid BST
        else return validate(root->left, min, root->val) &&  validate(root->right, root->val, max);
        // recursive return ... and update min or max based off left or right
    }
};
