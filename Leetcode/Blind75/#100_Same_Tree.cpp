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
    bool isSameTree(TreeNode* p, TreeNode* q) {
         //if they end at the same point they are the same
        if (p == nullptr && q == nullptr) return true; // base case
        // if they ever differ they are false
        if (p == nullptr || q == nullptr || p->val != q->val) return false;
        //recursivly return up
        else return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
