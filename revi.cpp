#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data ;
    Node* left;
    Node* right;
    Node(int value){
        data = value;
        left=right=NULL;
    }
};
Node* insert(Node* root , int val){
if(root==NULL){
    return new Node(val);
}
if(root->data > val){
   root->left =  insert(root->left , val);

}
else{
    root->right = insert(root->right , val);
}
return root ;  // haar baar 3 hi return horha h as a root ... after making a node and joining 
}
 Node* buildbst(vector<int>arr){
    Node* root =NULL; // starting m null rkha 
for(int val:arr){
   root =  insert(root , val);
}
return root ; 
}

bool search(Node* root , int key){
  if(root==NULL){
    return false ;
  }
  if(root->data==key){
    return true ; 
  }
  if(root->data > key){ 
search(root->left , key);
  }
  else{
search(root->right , key);
  }

}
 void print(Node* root){
     if(root!=NULL){
        cout<< root->data << " ";
     }
     if(root==NULL){
        return;
     }
     print(root->left);
     print(root->right);
}
Node* findingip(Node* root){ // rightsubtree m left mst node ... 
 
    while(  root!=NULL && root->left!=NULL){  // root!=NULL kya pta root jo aai h vhi null ho  ... 
      root= root->left;
    }
    return root ; 
}
Node* deletenode(Node* root , int key){
if(root==NULL){
    return NULL;
}
if(root->data > key){
   root->left =  deletenode(root->left , key);   // nya root ka left return hokr aaiga  vo particuar node delete hone ke baad 
}
else if(root->data <key){
    root->right = deletenode(root->right , key);
}
else{ //root ==key
// 0 ya 1 child h node ka toh jo not null hoga vo return hojaiga ya agr dono hi null h toh koi return hojaiga... 
if(root->left ==NULL){
    Node* temp =  root->right; // storing the value 
    delete root ; // delete the root 
    return temp; // putting that value in place of root 
}
else if(root->right==NULL){
    Node* temp =  root->left;
    delete root;
    return temp ;
}
  // handling node with 2 children 
  // find ip 
  Node* temp = findingip(root->right);  // root ke rightsub tree m find krege na 
  root->data = temp->data ;
   // delete temp ; yeh nhi aaiga kyu ki  yeh safe nhi h ... kya pta temp ka right exist krta ho phir uska kya hoga 
 root->right =   deletenode(  root->right   ,temp->data  );//“Right subtree me se successor ko delete karo
//aur jo naya subtree bane
//usse parent ke right pointer se jod do”

}
return root ; 
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* buildbst( int st , int end , vector<int>nums){
    if(st>end){
        return NULL;
    }
    int mid = st+(end-st)/2;
    TreeNode* makingroot = new TreeNode(nums[mid]);
    makingroot->left = buildbst(st , mid-1 , nums);
     makingroot->right = buildbst(mid+1 , end , nums);
     return makingroot ; 
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    return buildbst(0 , nums.size()-1 , nums);    
    }
};





int main(){
    vector<int>arr ={3,2,1,5,6,4};
   Node*root =  buildbst(arr);
   print(root);
   cout<< endl;
 Node* newroot =  deletenode(root , 1);
 print(newroot);

}