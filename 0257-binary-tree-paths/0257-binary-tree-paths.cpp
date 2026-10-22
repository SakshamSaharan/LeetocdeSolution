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
    void search(TreeNode* root,string curr,vector<string>& ans){
        if(root == nullptr) return;
        int n = curr.size();
        curr += to_string(root->val) + "->";
        if(root->left == nullptr && root->right == nullptr){
            
            ans.push_back(curr.substr(0,curr.size()-2));
        }
        else{
            search(root->left,curr,ans);
            search(root->right,curr,ans);
        }
        curr.resize(n);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(root == nullptr) return ans;
        string curr = "";
        search(root,curr,ans);
        return ans;
    }
};