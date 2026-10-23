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
    bool check(TreeNode* root,TreeNode* low,TreeNode* high){
        if(root == nullptr) return true;

        if((low != nullptr && root->val <= low->val) ||
            (high != nullptr && root->val >= high->val))
            return false;

        bool checkleft = check(root->left,low,root);
        bool checkright = check(root->right,root,high);

        if(! checkleft || ! checkright) return false;

        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        TreeNode* low = nullptr;
        TreeNode* high = nullptr;
        return check(root,low,high);
    }
};