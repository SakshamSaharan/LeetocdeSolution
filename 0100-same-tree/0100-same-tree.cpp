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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*,TreeNode*>>qui;
        qui.push(make_pair(p,q));
        while(! qui.empty()){
            pair<TreeNode*,TreeNode*> info = qui.top();
            qui.pop();
            if(info.first == NULL && info.second == NULL) continue;
            if(info.first == NULL || info.second == NULL) return false;
            if(info.first->val != info.second->val) return false;

            qui.push(make_pair(info.first->right,info.second->right));
            qui.push(make_pair(info.first->left,info.second->left));
        }
        return true;
    }
};