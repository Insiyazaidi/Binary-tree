    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p||root==q){  // YEH BASE CASE H 
            return root;
        }
     TreeNode*leftseaaya=   lowestCommonAncestor(root->left, p,q);
      TreeNode*rightseaaya=   lowestCommonAncestor(root->right, p,q);
      if(leftseaaya==NULL && rightseaaya==NULL){  // DONO SIDE SE NULL AAYA TOH NULL HI RETURN KRNA HH 
        return NULL;
      }
      else if(leftseaaya==NULL){  // EK SIDE SE AAYA NULL DUSRE SE KUCH VALID AAYA TOH VALID VLA BHEJNA H 
        return rightseaaya;
      }
        else if(rightseaaya==NULL){
        return leftseaaya;
      }
      else if(leftseaaya!=NULL && rightseaaya!=NULL){ // baaki sb cases already upr check ho chuke h 
        return root ;   // DONO SE VALID AAYA MTLB 
      }
      return NULL;
    }