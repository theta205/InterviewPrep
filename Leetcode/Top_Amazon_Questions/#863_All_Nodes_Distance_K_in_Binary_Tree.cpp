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
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (k == 0) return {target -> val}; // if k is zero just return target 

        unordered_map<TreeNode*, int> m; // holds how far nodes are from target
        vector<int> ans; // answer vector

        dfs(root, target, m); // gets how far each node in dfs path is from target
        solve(root, target, m, m[root]); // gets how far each element is from target

        for (auto p : m){ // if distance form k (p.second) equals k add to answer
            if(p.second == k) ans.push_back(p.first->val);
        }
        return ans; // return answer
    }
    void solve(TreeNode* root, TreeNode* target, unordered_map<TreeNode*, int> &m, int far){
        if (root == nullptr) return;

        if (root != target){ 
            if (m[root] != 0 ){ // if in dfs path to target use that
                far = min(far, m[root]); 
            }
            m[root] = far; // else set how far with far variable
        }
        else far = 0; // if root is target dist (how far) is zero
        
        //add one to dist (how far) and recurse into children
        solve(root->left, target, m, far + 1);
        solve(root->right, target, m, far + 1);
    }
    int dfs(TreeNode* root, TreeNode* target, unordered_map<TreeNode*, int> &m){
        if (root == nullptr) return 0; 
        if (root->left == target || root->right == target) {
            m[root] = 1; // if child is target, dist is one
            return 1;
        }
        // else add one as long is the childs distance is not zero
        int recur = max(dfs(root->left,target,m), dfs(root->right,target,m));
        if (recur == 0) return 0;
        else {
            m[root] = recur + 1;
            return recur + 1;
        }
    }
};
