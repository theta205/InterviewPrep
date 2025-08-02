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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap; //Get the index of each number in a map
        for (int i = 0; i < inorder.size(); ++i)
            inMap[inorder[i]] = i;

        int preIndex = 0; // preOrder is global in scope and passed my reference
        return build(preorder, inorder, inMap, 0, inorder.size() - 1, preIndex);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
        unordered_map<int, int> &inMap,
        int inStart, int inEnd, int &preIndex
    ){
        if (inStart > inEnd) return nullptr; 
        // checks if inorder that we are checking is at empty (inEnd is valid index)
        // create root 
        int x = preorder[preIndex++]; //
        TreeNode* root = new TreeNode(x);
        //recursively get right and left
        root -> left = build(preorder,inorder,inMap, inStart, inMap[x] - 1, preIndex); 
        root -> right = build(preorder,inorder,inMap, inMap[x] + 1, inEnd, preIndex); 
        return root;
    }
};
//preorder: root, left, right
//inorder: left, root, right
