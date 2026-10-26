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

        while(root != nullptr){
            if(p->val > root->val && q->val > root->val){
                root = root->right;
            }
            else if(p->val < root->val && q->val < root->val){
                root = root->left;
            }
            else{
                break;
            }
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;

        return lca(root,p,q);
    }
};