class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) { // base case
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr) { // if both l and r are ancestors of p or q
            return root;
        }

        return left != nullptr ? left : right; // otherwise return nullptr if both are nullptr or the one that isnt nulltpr 
    }
};
