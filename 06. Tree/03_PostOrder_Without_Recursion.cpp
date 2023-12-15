/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    TreeNode* node = A;
    stack<TreeNode*> stk;
    vector<int> postOrder;
    while(node!=NULL || !stk.empty()){
        if(node!=NULL){
            stk.push(node);
            node = node->left;
        }else{
            TreeNode* tmp = stk.top()->right;
            if(tmp == NULL){
                tmp = stk.top();
                stk.pop();
                postOrder.push_back(tmp->val);
                while(!stk.empty() && stk.top()->right == tmp){
                    tmp = stk.top();  
                    stk.pop();
                    postOrder.push_back(tmp->val);
                }
            }else{
                node = tmp;
            }
        }
    }
    return postOrder;
}
