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
static int idx = -1;
  Node* creatingtree(vector<int>preorder){
    idx++;
if(preorder[idx]==-1){
return NULL;
}
Node* root = new Node(preorder[idx]);
 root->left = creatingtree(preorder);
  root->right = creatingtree(preorder);
  return root;
}
int main(){
    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
 Node* root = creatingtree(preorder);
 cout<< root->data<<endl;
 cout<< root->left->data<<endl;
 cout<< root->right->data<<endl;
}