bool validate (TreeNode*root , long min , long max ){
    if(root==NULL){
        return true;
    }
    if(root->val<=min || root->val>=max){
        return false ;
    }
    bool leftsubtree = validate(root->left , min , root->val);
     bool rightsubtree = validate(root->right , root->val , max);
     return  leftsubtree &&  rightsubtree ;
}
    bool isValidBST(TreeNode* root) {
     return    validate(root , LONG_MIN , LONG_MAX);
    }