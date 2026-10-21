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
    pair<bool,TreeNode*> check(TreeNode* root,int val){
        if(root == nullptr) return {false,nullptr};

        if(root->val == val) return {true,root};

        if(root->val > val) return check(root->left,val);
        if(root->val < val) return check(root->right,val);

        return {false,root};
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) return nullptr;

        pair<bool,TreeNode*> ans = check(root,val);
        if(! ans.first) return nullptr;

        return ans.second;
    }
};