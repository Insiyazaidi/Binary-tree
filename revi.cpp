#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data ; 
    Node* right;
    Node* left;
    Node(int value){
        data = value;
        right=left=NULL;
    }
};
Node* insert(Node* root , int value){
if(root==NULL){
    return new Node(value);
}
if(root->data>value){  //4 agr root h aur hmari value 2 hai ... 
  root->left = insert(root->left , value);
}
else{
    root->right = insert(root->right , value);
}
return root ;
}

Node* buildbst(vector<int>arr){
    Node* root = NULL;
    for(int value : arr){
  root = insert(root , value);
    }

    return root;
}
 bool search(Node* root , int key){
if(root==NULL){
    return 0;
}
if(root->data==key){
return 1;
}
if(root->data>key){
    search(root->left , key);
}
else{
    search(root->right , key);
}
}


int main(){   
    vector<int>arr = {3,2,1,5,6,4};
    Node* root = buildbst(arr);
    cout<< endl;
  cout <<  search(root , 9);

}