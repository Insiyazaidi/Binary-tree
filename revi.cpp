#include<iostream>
#include<vector>
using namespace std;
class Node {
    public:
int data ;
Node* left ;
Node* right;
Node(int value ){
 data = value ;
 left = right = NULL;
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

return root ; 

}

 Node* findip(root){
while(root!=NULL && root->right!=NULL){
    root=root->right;
}
return root ; 
}

 Node* buildbst(vector<int>arr){
    Node* root = NULL;
    for(int val: arr){
        root = insert(root , val);  
    }
return root ; 
 }
  bool search(Node* root , int key){
    if(root==NULL){
        return false ;
    }

if(root->data > key){
    search(root->left , key);
}
else if(root->data < key){
    search(root->right , key);
}
else if(root->data == key){
    return true ; 
}

 }
  Node * deletenode(Node * root , key){
    // phle search kroc 
    if(root==NULL){
        return NULL;
    }
    if(root->data > key ){
      root->left =   deletenode(root->left , key);
    }
    else if(root->data < key){
      root->right =   deletenode(root->right , key);
    }
    else{
        // yaani mil gya root jisko delete krna hh 
        // ab hmare pass 3 cheeze h 
        if(root->left==NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {   // agr dono child exist krte h root ke ... 
          Node* ip =   findip(root->left );  // ip means leftsubtreee m right most node .
          root->data = ip->data ; 

          root->left = deletenode(root->left , ip->data);   // Left subtree me jaakar us node ko delete karo jiska data ip->data hai...
        } 
    }
    return root ; 

 }
int main(){
vector<int>arr = {3,2,1,5,6,4};
Node* root = buildbst(arr);
cout << root->data  << " " << endl;
 cout << search(root , 10) << endl;
 Node* newnode = deletenode(root , 6);
 cout << newnode->data << " ";

}

class Solution {
public:
int prevorder = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL){
            return -1;
        }
        if(root->left!=NULL){
          int leftans=   kthSmallest(root->left , k);
          if(leftans!= -1){   // yaani -1 nhi aaya kuvh value aai h left se toh vahi return krlo
            return leftans;
          }
        }
         if(prevorder+1==k){   // { starting m prevorder 0 se initialize kiya .. first root ke liye prevorder 1 hojaiga   }
            return root->val;
         }
          prevorder = prevorder+1;   // {agr ans nhi mila .. toh prev+1 krdo to update .. }

        if(root->right!=NULL){
            int rightans = kthSmallest(root->right , k);
            if(rightans!= -1){
                return rightans;
            }
        }
        return -1;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==NULL){
        return NULL;
       } 
       if(root->val>p->val && root->val>q->val){  // this guarantee ki leftsubtree m hi answer milega toh yha se jo milega vhi return krdo .. rightsubtree ki call llgange ki zaroorat nhi  hh 
      return  lowestCommonAncestor(root->left , p ,q);  // if node p , q both lie in leftsubtree 
       }
       else if(root->val<p->val && root->val<q->val){
      return   lowestCommonAncestor(root->right , p ,q); // if node p,q both lie in rightsubtree  
       }
       else{   // if one node lie in right and other lie in left ... this is the condition of lca 
        return root;
       }
    }

    class Solution {
public:
TreeNode* helper(vector<int>& preorder , int& i , int bound){
    if(i>=preorder.size() || bound<preorder[i]){
        return NULL;
    }
    
    TreeNode* root = new TreeNode(preorder[i]);
    i++;
    root->left = helper(preorder , i , root->val);   // leftsub tree ke liye upper bound root ki value hogi 
     root->right = helper(preorder , i , bound);  // rightsubtree ke liye upper boung vhi hoga jo root ke liye upper bound tha ... 

     // for eg-- 3 root h aur uska upper bound jo tha vo 6 tha .. ab  hmne 3 root bna liye uska leftsubtree ka upperboud 3 hoga yaani left m koi bhi value aaksti h bs vo 3 se choti ho .. aur right subtree ka yeh rheega ki 3 se bdi value koi bhi aaksti h bs vo uske upr vle node se choti ho ie 6 se choti hu ... vrna bst property violate hojaigi .. 

    return root ; 

}

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
         return helper(preorder , i , INT_MAX);
    }
};