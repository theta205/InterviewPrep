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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root; // if null return
        // swap right and left bst recursively
        invertTree(root->left); invertTree(root->right);
        // swap right and left
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root; // return root
    }
};
