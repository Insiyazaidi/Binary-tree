int search( vector<int>& inorder , int val , int left , int right ){
    for(int i=left;i<=right;i++){
        if(inorder[i]== val){
  return i;
        }
      
    }
    return -1;
}
   TreeNode* helper(vector<int>& preorder, vector<int>& inorder , int &preidx , int left , int right){
  if(left>right){
    return NULL;
}
  
    TreeNode* root = new TreeNode (preorder[preidx]);

 int inorderidx = search( inorder , preorder[preidx] , left , right );
 preidx++;
 root->left =  helper(preorder ,  inorder ,preidx ,left , inorderidx-1 );
 root->right =  helper(preorder ,  inorder ,preidx  , inorderidx+1, right );
 return root;

   }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preidx =0;
      return helper(preorder ,  inorder ,preidx , 0 , inorder.size()-1);  
    }