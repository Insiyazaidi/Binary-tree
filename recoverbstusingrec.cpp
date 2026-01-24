TreeNode* prev=NULL;
TreeNode* first=NULL;
TreeNode* second=NULL;  


 void inorder(TreeNode* root){  //  // inorder - left - root-right .  // first m prev ki value aaigi , second m current root ki 
   if(root==NULL){
    return ;
   }
inorder(root->left);
if(prev!=NULL && root->val<prev->val){    // { 1, 3 , 8 , 6 , 4 , 9} here prev-8 , root -6  so if prev bda hogya root se toh sorted nhi h 
 
 
 if(first==NULL){    // agr first null hua toh yeh value define krdo .. agr first ki koi particular value exist krti h toh kuch ni ignore kro ...   // this condition is used if we find another pair which is not in correct order then without this condition first value will be chnaged to firstno of second pair which we dont want for eg first will change to 6 ... without if used ...
  first=prev;
 }
 second=root;
}
prev=root;
inorder(root->right);
}

    void recoverTree(TreeNode* root) {
        inorder(root);
    int temp = first->val;  // swapping of incorrect nodes ... 
        first->val=second->val;
        second->val=temp;
    }
};