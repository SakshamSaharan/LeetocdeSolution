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
    void inorder(TreeNode* root,unordered_set<int>& st){
        if(root == nullptr) return;

        inorder(root->left,st);
        st.insert(root->val);
        inorder(root->right,st);
    }

    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        unordered_set<int>st;
        inorder(root,st);
        for(auto it = st.begin();it!=st.end();it++){
            if(st.find(k-*it) != st.end() && k-*it != *it) return true;
        }
        return false;
    }
};