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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;

        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(! q.empty()){
            auto curr = q.front();
            q.pop();
            TreeNode* currnode = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            mp[col][row].insert(currnode->val);

            if(currnode->left != nullptr) q.push({currnode->left,{row+1,col-1}});
            if(currnode->right != nullptr) q.push({currnode->right,{row+1,col+1}});
        }
        vector<vector<int>>ans;
        for(auto columns : mp){
            vector<int>columnvalues;
            for(auto rows : columns.second){
                for(int value : rows.second){
                    columnvalues.push_back(value);
                }
            }
            ans.push_back(columnvalues);
        }
        return ans;
    }
};