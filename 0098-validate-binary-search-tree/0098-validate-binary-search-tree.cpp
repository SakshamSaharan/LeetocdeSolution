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
    bool check(TreeNode* root,long long low,long long high){
        if(root == nullptr) return true;

        if(root->val <= low || root->val >= high) return false;

        bool checkleft = check(root->left,low,root->val);
        bool checkright = check(root->right,root->val,high);

        if(! checkleft || ! checkright) return false;

        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        long long low = LLONG_MIN;
        long long high = LLONG_MAX;
        return check(root,low,high);
    }
};