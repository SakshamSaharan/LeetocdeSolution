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
    TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root == nullptr) return nullptr;

        if(p->val > root->val && q->val > root->val){
            return lca(root->right,p,q);
        }
        else if(p->val < root->val && q->val < root->val){
            return lca(root->left,p,q);
        }
        else{
            return root;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;

        return lca(root,p,q);
    }
};