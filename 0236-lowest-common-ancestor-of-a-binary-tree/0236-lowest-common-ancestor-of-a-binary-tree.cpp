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
    bool nodetorootpath(TreeNode* root,TreeNode* n,vector<TreeNode*>& path){
        if(root == NULL) return false;
        path.push_back(root);
        if(root->val == n->val) return true;
        bool leftcheck = nodetorootpath(root->left,n,path);
        bool rightcheck = nodetorootpath(root->right,n,path);
        if(leftcheck || rightcheck) return true;
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1;
        vector<TreeNode*>path2;
        nodetorootpath(root,p,path1);
        nodetorootpath(root,q,path2);
        TreeNode* lca = NULL;
        for(int i=0,j=0;i<path1.size() && j<path2.size();i++,j++){
            if(path1[i]->val != path2[j]->val) return lca;
            lca = path1[i];
        }
        return lca;
    }
};