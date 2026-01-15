#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data ;
    Node* left ;
    Node* right ;
    Node(int value){
        data = value ;
        left = right = NULL;
    }
};
Node* insert(Node* root , int val){
    if(root ==NULL){
        return new Node(val);
    }
    if(root->data > val){
       root->left =  insert(root->left , val);  // root->left will be NULL for this case so that ek new node bn jai 
    }
    else{
        root->right = insert(root->right , val);
    }
return root ; 
}
Node* buildbst(vector<int>arr){
    Node* root = NULL;
for(int val : arr){
    root = insert(root , val); // haaar bar new root pass krrhe h 
}
return root ; 
}
int main(){
    vector<int>arr ={3,2,1,5,6,4};
   Node*root =  buildbst(arr);
   cout<< root->data<<" ";
   cout<< root->left->data << " ";
   cout<< root->right->data<< " ";
}