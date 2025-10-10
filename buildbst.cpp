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
       if(root->data>val) {
     root->left=    insert(root->left , val);  // yha pr  left side m root->left iskiye likha h kyu ki vo function head return krega aur vo head isliye rterun krega kyu ki ]
// may be hmara root->left change hogya ho 
}
else{
  root->right =   insert(root->right , val);
}
return root;
}

 Node* buildbst(vector<int>arr){
Node*root = NULL;
for(int val:arr){
 root =    insert(root , val);  // hr baar m root change hoga 
}
return root ; 
}

bool search(Node*root , int key){
if(root==NULL){
    return false ;
}
if(root->data == key){
    return true;
}
if(key<root->data){
    search(root->left , key);
}
else{
    search(root->right , key);
}
}
int main(){
    vector<int>arr ={3,2,1,5,6,4};
   Node*root =  buildbst(arr);
  cout << search(root , 9);
}