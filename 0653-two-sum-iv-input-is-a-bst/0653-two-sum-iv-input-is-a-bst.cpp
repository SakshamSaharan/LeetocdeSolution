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
class BSTiterator{
private:
    stack<TreeNode*>st;
    bool reverse;

    void pushall(TreeNode* root){
        while(root != NULL){
            st.push(root);

            if(reverse) root = root->right;
            else root = root->left;
        }
    }
public:
    BSTiterator(TreeNode* root,bool isreverse){
        reverse = isreverse;
        pushall(root);
    }   

    int next(){
        TreeNode* curr = st.top();
        st.pop();

        if(reverse == true){
            pushall(curr->left);
        }
        else{
            pushall(curr->right);
        }
        return curr->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;

        BSTiterator leftitr(root,false);
        BSTiterator rightitr(root,true);

        int i = leftitr.next();
        int j = rightitr.next();

        while(i < j){
            int currsum = i+j;

            if(currsum == k) return true;
            if(currsum > k){
                j = rightitr.next();
            }
            else{
                i = leftitr.next();
            }
        }
        return false;
    }
};