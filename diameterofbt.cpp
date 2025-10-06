int height(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right); 
    return 1+max(leftheight, rightheight);
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
  int leftside=    diameterOfBinaryTree(root->left); 
   int rightside=    diameterOfBinaryTree(root->right);
   int includingnode = height(root->left)+height(root->right);
   return max({leftside , rightside , includingnode})   ; 
    }