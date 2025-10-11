#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
int data;
Node*right;
Node*left;
Node(int val){
    data = val;
    right=left=NULL;
}
};

Node* insert(Node*root , int val){
    if (root==NULL){
        return new Node(val);
    }
    if(val<root->data){
      root->left  = insert(root->left , val);  // insert jb new node bnaiga aur uski call  yha se gai toh new node return bhi yhi hogi aur assign bhi hogi root->left 
    }
    else{
        root->right = insert(root->right , val);
    }
    return root ;  // .. yha se eventually root 3 hi return hogi baar baar 
}   

Node* buildbst( vector<int>arr){
   Node* root = NULL;
   for(int val:arr){
   root =  insert(root , val);
   } 
   return root;
}

Node*getis(Node*root){
    while(  root!=NULL &&root->left!=NULL ){
        root=root->left;
    }
    return root;
}
 Node* deletenode(Node*root , int key){
   if(root==NULL){
    return NULL;
   }
   
    if(key<root->data){
            root->left = deletenode(root->left , key); // yeh root ka new left part dega toh usko phir root se join krvadiya
    }
  else  if(root->data<key){
          root->right = deletenode(root->right , key);
    }
    else {   // yaani hme root mil gya jisko delte krna h 
if(root->right==NULL){   
Node*temp = root->left;
delete root;              // starting ke 2 cases m hmne no child , 1 child ko handle krliya h 
return temp;
}
else if(root->left==NULL){
    Node*temp= root->right;
    delete root;
    return temp;
}
else{   // 2 child .. find inorder successor -- right subtree .. leftmost node  .. aur IS ka hmesha 0 ya phir 1 hi child hoga 2 kbhi nhi 
Node*IS = getis(root->right);

root->data = IS->data;
 root->right = deletenode(root->right ,IS->data );  // kyu ki IS hmesha right m exist krta h isliye , aur hm  root ke right se hi delete krege 


     
}
    }
    return root;
}
void printinoder( Node*root){
    if(root==NULL){
        return;
    }
    printinoder(root->left);
    cout<<root->data<<" ";
     printinoder(root->right);
}
int main(){
    vector<int>arr ={3,2,1,5,6,4};
   Node*root =  buildbst(arr);
   cout<<" before deletion"<<endl;
   printinoder(root);
   deletenode(root , 5);
   cout<<endl;
     cout<<" after  deletion"<<endl;
   printinoder(root);
  
}