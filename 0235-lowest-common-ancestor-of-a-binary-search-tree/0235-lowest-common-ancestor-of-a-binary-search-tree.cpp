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

        if(root->val == p->val || root->val == q->val) return root;

        TreeNode* leftsubtree = lca(root->left,p,q);
        TreeNode* rightsubtree = lca(root->right,p,q);

        if(leftsubtree != NULL && rightsubtree != NULL) return root;
        if(leftsubtree == NULL && rightsubtree == NULL) return nullptr;

        return leftsubtree == nullptr ? rightsubtree : leftsubtree;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        TreeNode* ans = lca(root,p,q);
        return ans;
    }
};