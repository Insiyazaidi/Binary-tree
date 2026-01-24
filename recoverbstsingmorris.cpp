class Solution {
public:

// Morris traversal me visit ka exact moment sirf 2 jagah hota hai:
TreeNode* prev = NULL;
TreeNode* first=NULL;
TreeNode* second = NULL;
    void recoverTree(TreeNode* root) {  // jha morris traversal m ans.push_back horha tha vha pr ab condition check horhi h 
     TreeNode* curr = root;
     while(curr!=NULL){
        if(curr->left==NULL){
            if(prev!=NULL && prev->val>curr->val ){
                if(first==NULL){
                    first=prev;
                }
                second = curr;
            }
               prev=curr;
       curr=curr->right;
        }

        else{
            //find ip 
            TreeNode* ip = curr->left;
            while(ip->right!=NULL && ip->right!=curr){
              ip = ip->right;
            }
            if(ip->right==NULL){  // making thread
                ip->right=curr;
                curr=curr->left;
            }
            else{ // breaking thread 
             if( prev!=NULL && curr->val<prev->val){
                if(first==NULL){
                    first = prev;
                }
                second = curr ;  
             }
             prev= curr;
             ip->right = NULL;
             curr=curr->right;

            }
        } 
     }
if(first!=NULL && second!=NULL){
    int temp = first->val;
    first->val=second->val;
    second->val = temp;
}

    }
};