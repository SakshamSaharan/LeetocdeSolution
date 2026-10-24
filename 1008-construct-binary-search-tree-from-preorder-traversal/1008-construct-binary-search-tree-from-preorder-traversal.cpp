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
    TreeNode* builtBST(vector<int>& preorder,int pre_st,int pre_end,vector<int>& inorder,int in_st,int in_end,unordered_map<int,int>& mp){
        if(pre_end < pre_st || in_end < in_st) return NULL;

        TreeNode* root = new TreeNode(preorder[pre_st]);
        int root_index = mp[root->val];
        int numsleft = root_index - in_st;

        root->left = builtBST(preorder,pre_st+1,pre_st+numsleft,inorder,in_st,root_index-1,mp);
        root->right = builtBST(preorder,pre_st+numsleft+1,pre_end,inorder,root_index+1,in_end,mp);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int>mp;
        int n = inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }

        TreeNode* root = builtBST(preorder,0,n-1,inorder,0,n-1,mp);

        return root;
    }
};