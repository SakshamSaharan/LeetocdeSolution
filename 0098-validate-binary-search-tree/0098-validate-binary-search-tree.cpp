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
    bool ans(TreeNode* root,TreeNode* mini,TreeNode* maxi){
        if(root == nullptr) return true;

        if((mini != nullptr && root->val <= mini->val) || (maxi != nullptr && root->val >= maxi->val)){
            return false;
        }

        bool checkleft = ans(root->left,mini,root);
        bool checkright = ans(root->right,root,maxi);

        if(!checkleft || !checkright) return false;

        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;

        return ans(root,NULL,NULL);
    }
};