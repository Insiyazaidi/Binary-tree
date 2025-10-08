class Solution {
public:

   void helper(TreeNode* root , string path ,vector<string>&ans ){
    if(root->left==NULL && root->right==NULL){
       ans.push_back(path);
       return;
    }
  if(root->left){
    helper(root->left , path+"->"+to_string(root->left->val), ans);
  }
    if(root->right){
    helper(root->right , path+"->"+to_string(root->right->val) , ans);
  }
  }
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string>ans;
string path = to_string(root->val);
   helper(root , path , ans);
return ans;
    }
};