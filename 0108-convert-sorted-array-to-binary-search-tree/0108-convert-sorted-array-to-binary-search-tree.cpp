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
    TreeNode* createBST(vector<int>& nums,int st,int end){
        if(st > end) return NULL;

        int mid = st + (end-st)/2;
        TreeNode* curr = new TreeNode(nums[mid]);

        curr->left = createBST(nums,st,mid-1);
        curr->right = createBST(nums,mid+1,end);

        return curr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int st = 0;
        int end = nums.size()-1;
        TreeNode* ans = createBST(nums,st,end);
        return ans;
    }
};