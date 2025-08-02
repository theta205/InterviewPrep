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
    void bfs(vector<vector<int>> &res, TreeNode* root, int level) {
        if (root == nullptr) return;
        if (res.size() <= level) {
            res.resize(level + 1);
        }
        res[level].push_back(root -> val);
        bfs(res, root -> left, level + 1);
        bfs(res, root -> right, level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res{};
        bfs(res, root, 0);
        return res;
    }
};
