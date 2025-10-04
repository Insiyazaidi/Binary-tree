#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data ;
    Node*left;
    Node*right;
    Node(int val){
        data = val;
        left=right=NULL;
    }
};

int heightbt(Node*root){
    if(root==NULL){
        return 0;
    }
  int leftheight=  heightbt(root->left);
  int rightheight = heightbt(root->right);
  return max(leftheight , rightheight)+1;
}


int countnodes(Node*root){
if(root==NULL){
    return 0;
}
    int leftc=countnodes(root->left);
    int rightc = countnodes(root->right);
    return leftc+rightc+1;

}

int nodesum(Node*root){
if(root==NULL){
    return 0;
}
 int leftsum = nodesum(root->left);
  int rightsum = nodesum(root->right);
  return leftsum+rightsum+root->data;

}
static int idx=-1;
Node*creatingbt(vector<int>preorder){
idx++;
if(preorder[idx]==-1){
    return NULL;
}
Node*root = new Node(preorder[idx]);
 root->left = creatingbt(preorder);
  root->right = creatingbt(preorder);
  return root;
}
int main(){
 vector<int>preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
   Node*root =  creatingbt(preorder);
   cout<<root->data<< endl;
cout<<root->left->data<< endl;
  cout<<root->right->data<< endl;
 cout<<"height of bt "<< heightbt(root) << endl;
 cout<<"no of nodes" << countnodes(root) << endl;
 cout<<"nodes sum "<< nodesum(root) << endl;
}