public:
int ans =0;
int height(TreeNode* root){
      if(root==NULL){
            return 0; 
        }
        int lefth = height(root->left);
        int righth= height(root->right);
 ans = max(ans , lefth+righth);
 return max(lefth , righth)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
      height(root);
      return ans ;
    }