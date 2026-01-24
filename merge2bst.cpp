#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data ;
    Node* left;
    Node* right;
    Node(int value ){
   data = value;
   left=right=NULL;
    }
};
Node* insert(Node* root , int val){
    if(root==NULL){
        return new Node(val);
    }
    if(root->data>val){
        root->left = insert(root->left , val);
    }
    else{
        root->right = insert(root->right , val);
    }
    return root ; 
}
Node* buildbst(vector<int>bst){
Node* root =NULL;
for(int val : bst){
    root = insert(root , val);
}
return root ; 
}

 void print(Node* root){
    if(root==NULL){
        return;
    }
   
    print(root->left);
     cout<< root->data << " ";
    print(root->right);
}

 void inorder(Node* root , vector<int>&ans){
    if(root==NULL){
        return ; 
    }
    inorder(root->left , ans);
    ans.push_back(root->data);
    inorder(root->right ,ans);

}
 vector<int> mergearr(vector<int>arr1 , vector<int>arr2){
int i=0;
int j=0;
vector<int>finalarr;
while(i<arr1.size() && j<arr2.size()){
if(arr1[i]<=arr2[j]){
    finalarr.push_back(arr1[i]);
    i++;
}
else{
  finalarr.push_back(arr2[j]);
    j++;
}
}
while(i<arr1.size()){
   finalarr.push_back(arr1[i]);
    i++; 
}
while(j<arr2.size()){
    finalarr.push_back(arr2[j]);
    j++;
}
return finalarr;
}

Node* buildbstfromsorted(vector<int>arr , int st , int end){
    if(st>end){
        return NULL;
    }
int mid = st+(end-st)/2;
Node* root = new Node(arr[mid]);
 root->left = buildbstfromsorted(arr , st , mid-1);
 root->right = buildbstfromsorted(arr , mid+1 , end);
 return root;
}
Node* merge2bst(Node* root1 , Node* root2){
 vector<int>arr1;
  vector<int>arr2;
   inorder(root1 ,arr1 );
inorder(root2 , arr2);
vector<int>finalarr = mergearr(arr1 , arr2);
 return buildbstfromsorted(finalarr ,  0 , finalarr.size()-1);  // finalarr={0,1,2,3,5,8,10}... 

}
int main(){
    vector<int>bst1 = {8, 2 ,1 ,10};
    vector<int>bst2= {5 , 3 ,0};
 Node* root1 =   buildbst(bst1);
 Node* root2 = buildbst(bst2);
// make  .. array for these bst 
 Node* newmergeroot = merge2bst(root1 , root2);
  print(newmergeroot);


}