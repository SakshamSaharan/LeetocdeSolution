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
    int height(TreeNode* root){
        if(root == NULL) return 0;
        int leftht = height(root->left);
        int rightht = height(root->right);

        return max(leftht,rightht) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int lefthtt = height(root->left);
        int righthtt = height(root->right);
        if(abs(lefthtt-righthtt) > 1) return false;
        return  isBalanced(root->left) && isBalanced(root->right);
    }
};