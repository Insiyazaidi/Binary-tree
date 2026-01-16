public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root->val>p->val && root->val>q->val){
            return lowestCommonAncestor(root->left , p,q);
        }
           else if(root->val<p->val && root->val<q->val){
            return lowestCommonAncestor(root->right , p,q);
        }
        else{
            return root;
        }
    }
    class Solution {
public:
bool validate (TreeNode* root , long min , long max){
    if(root==NULL){
        return true ; 
    }
    if(root->val<=min || root->val>=max){  // agr range se bhr chali gai 
        return false ; 
    }
    bool leftsubtree = validate(root->left , min , root->val);
    bool rightsubtree =  validate(root->right , root->val , max);
    return leftsubtree && rightsubtree;
}
    bool isValidBST(TreeNode* root) {
      return validate(root , LONG_MIN , LONG_MAX );  
    }
};