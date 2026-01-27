#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
 Node* getpredecessor(Node* root){  // leftsubtree m rightmost node
while(root->right!=NULL){
    root=root->right;
}
return root;
}

Node* getsuccessor(Node* root){  // right subtree m leftmost node
while(root->left!=NULL){
    root=root->left;
}
return root;
}

vector<int> getipandis(Node* root , int key){
Node* curr = root;
Node* predecessor=NULL;
Node* sucesseor=NULL;
while(curr!=NULL){
    if(curr->data>key){  // ab hm key ko dhundne ke liye left m jaige 
      sucesseor=curr;// fihal ke liye ..  isko as sucessor consider krlo kyu ki left m jb jaige toh sb isse choti values milegi 
    curr=curr->left;
    }
    else if(curr->data<key){
        predecessor = curr; // isko predcessor maan lia kyu ki right m sb bdi values hi milegi 
        curr=curr->right;
    }
    else{  // agr key equal to node hogai 
        if(curr->left!=NULL){
 predecessor=    getpredecessor(curr->left);
        }
        if(curr->right!=NULL){
  sucesseor=   getsuccessor(curr->right);
        }
        break;


    }
    
}

return {
    predecessor ? predecessor->data : -1,
    sucesseor ? sucesseor->data : -1
};


}

int main(){
  Node* root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
     root->left->right= new Node(5);
       root->right->left = new Node(7);
         root->right->right = new Node(9);  
         int key = 1;
            vector<int>ans (2);   // agr key present nhi hogi bst m toh phir .. ya toh vo key se bdi hogi ya choti toh ek if satify hokr  
            // koi ek value ya toh predecessor ya sucessor define hojaige as root . aur dusra koi will be -1
  ans =    getipandis(root , key);
          cout<<ans[0]<<" inorder predecessor"<< endl;
          cout<<ans[1]<<" inorder sucesseor"<< endl;
}