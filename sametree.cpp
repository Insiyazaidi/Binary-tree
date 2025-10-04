public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){   // dono null h toh return krdo true ... 
            return true;
        }
        if(p==NULL || q==NULL){   // agr p null hai pr q null nhi h ... ya phir q null h p null nhi h toh false return kro ... agr dono null h toh phir vo toh upr hi check krlege
            return false ;
        }
     bool isleftsame =   isSameTree(p->left , q->left);
    bool   isrightsame =   isSameTree(p->right , q->right);
return isleftsame && isrightsame && p->val==q->val;
    }