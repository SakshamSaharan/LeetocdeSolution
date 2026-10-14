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
        if(root == NULL) return false;
        path.push_back(root);
        if(root->val == n->val) return true;
        bool isleft = nodepath(root->left,n,path);
        bool isright = nodepath(root->right,n,path);
        if(isleft || isright){
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1;
        vector<TreeNode*>path2;
        nodepath(root,p,path1);
        nodepath(root,q,path2);
        int i = 0;
        TreeNode* store = NULL;
        while(i<path1.size() && i<path2.size()){
            if(path1[i]->val != path2[i]->val) {
                return store; 
            }
            store = path1[i];
            i++;
        }
        return store;
    }
};