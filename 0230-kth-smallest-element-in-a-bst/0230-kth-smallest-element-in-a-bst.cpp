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
    int currelement = 0;
    int minelement = 0;
public:
    void smallest(TreeNode* root,int k){
        if(root == nullptr || currelement > k){
            return;
        }

        smallest(root->left,k);
        currelement++;
        if(currelement == k){
            minelement = root->val;
            return;
        }
        smallest(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        smallest(root,k);
        return minelement;
    }
};