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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root == NULL) return -1;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<long long>ans;
        long long currsum = 0;
        while(! q.empty()){
            TreeNode*curr = q.front();
            q.pop();
            if(curr == NULL){
                ans.push_back(currsum);
                currsum = 0;
                if(q.empty()) break;
                q.push(NULL);
                continue;
            }
            currsum += curr->val;
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
        }
        if(ans.size() < k) return -1;
        sort(ans.begin(),ans.end(),greater<long long>());
        return ans[k-1];
    }
};