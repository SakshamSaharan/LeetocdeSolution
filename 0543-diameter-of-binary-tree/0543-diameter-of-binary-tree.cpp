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
    pair<int,int>diametre(TreeNode* root){
        if(root == NULL) return make_pair(0,0);
        pair<int,int> leftinfo = diametre(root->left);
        pair<int,int> rightinfo = diametre(root->right);

        int currdiametre = leftinfo.second + rightinfo.second + 1;
        int finalheight = max(leftinfo.second,rightinfo.second) + 1;
        int finaldiametre = max(max(leftinfo.first,rightinfo.first),currdiametre);

        return make_pair(finaldiametre,finalheight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diametre(root).first - 1;
    }
};