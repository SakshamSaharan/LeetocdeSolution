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
    TreeNode* buildtree(vector<int>& inorder,int in_st,int in_end,vector<int>& postorder,int ps_st,int ps_end,unordered_map<int,int>& mp){
        if(in_st > in_end || ps_st > ps_end) return nullptr;

        TreeNode* root = new TreeNode(postorder[ps_end]);

        int root_indx = mp[root->val];
        int numsleft = root_indx - in_st;

        root->left = buildtree(inorder,in_st,root_indx-1,postorder,ps_st,ps_st+numsleft-1,mp);
        root->right = buildtree(inorder,root_indx+1,in_end,postorder,ps_st+numsleft,ps_end-1,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        int n = inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = buildtree(inorder,0,n-1,postorder,0,n-1,mp);

        return root;
    }
};