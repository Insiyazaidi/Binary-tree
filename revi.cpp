class Solution {
public:
int ans = INT_MAX;
TreeNode*prev = NULL;
    int minDiffInBST(TreeNode* root) {
        if(root==NULL){
            return INT_MAX;
        }
        if(root->left !=NULL){
         minDiffInBST(root->left);
        
        }
        if(prev!=NULL){
  ans = min(ans , root->val-prev->val);
        }
      
        prev=root;
          if(root->right){
          minDiffInBST(root->right);
            
        }
        return ans ;

    }
};