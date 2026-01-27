class BSTIterator {
public:
stack<TreeNode*>s;
 void getleftnodes(TreeNode* root){
    while(root!=NULL){
        s.push(root);
        root = root->left;
    }
}
    BSTIterator(TreeNode* root) {
       getleftnodes(root); 
    }
    
    int next() {
      TreeNode* ans = s.top();
      s.pop();
      getleftnodes(ans->right); // agr us node ka right exist krta hoga toh uske left nodes store hojaige stack m   
    return ans->val;
    }
    
    bool hasNext() {
       return s.size()>0; 
    }
};