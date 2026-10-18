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
    bool nodepath(TreeNode* root,TreeNode* n,vector<TreeNode*>& path){
        if(root == nullptr) return false;
        path.push_back(root);
        if(root->val == n->val) return true;

        bool leftpath = nodepath(root->left,n,path);
        bool rightpath = nodepath(root->right,n,path);
        if(leftpath || rightpath) return true;

        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1;
        vector<TreeNode*>path2;
        nodepath(root,p,path1);
        nodepath(root,q,path2);
        TreeNode* lca = nullptr;
        int i=0;
        while(i<path1.size() && i<path2.size()){
            if(path1[i]->val != path2[i]->val){
                return lca;
            }
            lca = path1[i];
            i++;
        }
        return lca;
    }
};