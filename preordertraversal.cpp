#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    int data ;
    Node*right;
    Node*left;
    Node(int val){
        data = val;
        right=left=NULL;
    }
};
static int idx=-1;
 Node * buildtree(vector<int>preorder){
idx++;
if(preorder[idx]==-1){
    return NULL;
}
Node*root = new Node(preorder[idx]);
  root->left = buildtree(preorder);
   root->right = buildtree(preorder);
return root;
}

 void pretraverse(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data << " ";
    pretraverse(root->left);
    pretraverse(root->right);
}

void inordertraverse(Node * root){
    if(root==NULL){
        return;
    }
    inordertraverse(root->left);
    cout<<root->data<< " ";
    inordertraverse(root->right);
}
void postordertraverse(Node*root){
    if(root==NULL){
        return;
    }
postordertraverse(root->left);
postordertraverse(root->right);
cout<<root->data<<" ";
}
void levelorder(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){
       Node*curr =  q.front();
       q.pop();
       if(curr==NULL){
        if(!q.empty()){  // jb kuch elements present h yeh bs us node ko point krrha h jo hmne add kri h 
            cout<<endl;
            q.push(NULL);  
            continue;
        }
        else{
            break;     // yeh vo vla part h jb null point krrha h jb last node bhi traverse krli 
        }
       }
cout<<curr->data << " ";
if(curr->left!=NULL){
    q.push(curr->left);
}
if(curr->right!=NULL){
    q.push(curr->right);
}
    }
}
int main(){
     vector<int>preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
Node*root = buildtree(preorder);
     pretraverse(root);
cout<<endl;
inordertraverse(root);
cout<<endl;
postordertraverse(root);
cout<<endl;
levelorder(root);
}