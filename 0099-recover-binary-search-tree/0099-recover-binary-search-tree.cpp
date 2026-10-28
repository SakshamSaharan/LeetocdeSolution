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
    void inorder(TreeNode* root,vector<int>& vec){
        if(root == nullptr) return;

        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }
    void buildtree(TreeNode* root,vector<int>& vec,int& i){
        if(root == nullptr) return;

        buildtree(root->left,vec,i);
        root->val = vec[i++];
        buildtree(root->right,vec,i);
    }
    void recoverTree(TreeNode* root) {
        if(root == nullptr) return;
        vector<int>vec;
        inorder(root,vec);
        sort(vec.begin(), vec.end());
        int i=0;
        buildtree(root,vec,i);
    }
};