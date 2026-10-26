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
class BSTIterator {
public:
    vector<int>vec;
    int n;
    int index;
    void inorder(TreeNode* root,vector<int>& vec){
        if(root == nullptr) return;

        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);

    }
    BSTIterator(TreeNode* root) {
       
        inorder(root,vec);
        index = -1;
        n = vec.size();
    }
    
    int next() {
        return vec[++index];
    }
    
    bool hasNext() {
        return index+1 < n ? true : false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */