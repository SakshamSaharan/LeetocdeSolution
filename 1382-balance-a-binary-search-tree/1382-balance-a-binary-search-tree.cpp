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
    void inorder(TreeNode* root,vector<int>& values){
        if(root == nullptr) return;

        inorder(root->left,values);
        values.push_back(root->val);
        inorder(root->right,values);
    }
    TreeNode* BuildBST(vector<int>& values,int st,int end){
        if(st > end) return NULL;

        int mid = st + (end-st)/2;
        TreeNode* curr = new TreeNode(values[mid]);

        curr->left = BuildBST(values,st,mid-1);
        curr->right = BuildBST(values,mid+1,end);

        return curr;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root == nullptr) return nullptr;
        vector<int>values;
        inorder(root,values);
        int n = values.size();
        TreeNode* newroot = BuildBST(values,0,n-1);
        return newroot;
    }
};