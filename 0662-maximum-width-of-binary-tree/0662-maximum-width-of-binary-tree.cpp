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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans = 0;
        while(! q.empty()){
            int size = q.size();
            int mindx = q.front().second;
            int left = 0,right = 0;
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front().first;
                int currindx = q.front().second - mindx;
                q.pop();
                if(i == 0) left = currindx;
                if(i == size-1) right = currindx;
                if(curr->left != nullptr) q.push({curr->left,(long long)2*currindx+1});
                if(curr->right != nullptr) q.push({curr->right,(long long)2*currindx+2});
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};