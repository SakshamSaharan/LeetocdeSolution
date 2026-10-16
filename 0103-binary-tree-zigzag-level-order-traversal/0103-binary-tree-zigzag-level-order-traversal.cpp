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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*>q;
        q.push(root);
        q.push(nullptr);
        vector<vector<int>>vec;
        vector<int>ans;
        while(! q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == nullptr){
                vec.push_back(ans);
                if(q.empty()) break;
                ans.clear();
                q.push(nullptr);
                continue;
            }
            ans.push_back(curr->val);
            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr) q.push(curr->right);
        }
        for(int i=1;i<vec.size();i+=2){
            int j=0;
            int k = vec[i].size()-1;
            while(k > j){
                swap(vec[i][j],vec[i][k]);
                j++;
                k--;
            }
        }
        return vec;
    }
};