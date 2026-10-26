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
    bool nodepath(TreeNode* root,TreeNode* target,vector<TreeNode*>& path){
        if(root == nullptr) return false;

        path.push_back(root);
        if(root->val == target->val) return true;
        bool leftpath = nodepath(root->left,target,path);
        bool rightpath = nodepath(root->right,target,path);

        if(leftpath || rightpath) return true;
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;

        vector<TreeNode*>path1;
        vector<TreeNode*>path2;

        nodepath(root,p,path1);
        nodepath(root,q,path2);

        TreeNode* store = nullptr;

        int i=0;
        while(i<path1.size() && i<path2.size()){
            if(path1[i]->val != path2[i]->val) return store;
            store = path1[i];
            i++;
        }
        return store;
    }
};