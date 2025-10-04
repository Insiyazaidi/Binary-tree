class Solution {
public:
bool issame(TreeNode*root , TreeNode*subroot){   // bs dono trees ko check krna h identical h ya nhi thats it 

if(root==NULL && subroot==NULL){
    return true;
}
if(root==NULL || subroot==NULL){
    return false ;
}
 bool isleftsame = issame(root->left , subroot->left);
  bool isrightsame =  issame(root->right , subroot->right);
  return (isleftsame && isrightsame && (root->val ==subroot->val));

}

    bool isSubtree(TreeNode* root, TreeNode* subroot) {
if(root==NULL && subroot==NULL){
    return true;
}
if(root==NULL || subroot==NULL){
    return false ;
}

        if(root->val==subroot->val&& issame(root,subroot)){ // phle roots ki value check krlo 
        //phir baaki roots ke kiye isame function call krlo 
            return true;
        }
 return isSubtree(root->left , subroot)|| isSubtree(root->right,subroot);


    }