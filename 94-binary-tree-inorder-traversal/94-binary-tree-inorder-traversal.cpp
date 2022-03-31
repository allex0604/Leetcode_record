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
    void order(TreeNode* curr, vector<int>& ans){
        if(curr != NULL){
            if(curr->left != NULL) order(curr->left, ans);
            ans.push_back(curr->val);
            if(curr->right != NULL) order(curr->right, ans);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> ans;
        order(root, ans);
        return ans;
    }
};