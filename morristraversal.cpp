public:
vector<int>ans;   // morris approach no recursion 
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode*curr = root;
        while(curr!=NULL){
   if(curr->left==NULL){
        ans.push_back(curr->val);
        curr=curr->right;   
      }
else{  // null nhi h mtlb ..
   TreeNode* IP = curr->left;
   while(IP->right!=NULL && IP->right!=curr){
    IP=IP->right;
   }
   if(IP->right==NULL){ // yaani connection nhu h 
IP->right = curr;
curr=curr->left;
   } 
    else{ // yaani connection  h 
IP->right = NULL;
ans.push_back(curr->val);
curr=curr->right;
   }
}

        }
     return ans ;
    }
};