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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        TreeNode* curr = root;
        while(true){
            if(curr->val > val){
                if(curr->left == nullptr){
                    TreeNode* newNode = new TreeNode(val);
                    curr->left = newNode;
                    break;
                }
                curr = curr->left;
            }
            else{
                if(curr->right == nullptr){
                    TreeNode* newNode = new TreeNode(val);
                    curr->right = newNode;
                    break;
                }
                curr = curr->right;
            }
        }

        return root;
    }
};