/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    stack<TreeNode*> stk;
    stk.push(A);
    vector<int> preorder;
    while(!stk.empty()){
        TreeNode* curr = stk.top();
        stk.pop();
        preorder.push_back(curr->val);
        
        if(curr->right) stk.push(curr->right);
        if(curr->left)  stk.push(curr->left);
    }
    return preorder;
}
