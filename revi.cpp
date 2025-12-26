#include<iostream>
#include<vector>
#include<queue>
using namespace std;
  class Node {
    public:
    int data ;
    Node*left ;
    Node*right ;
    Node(int value){
        left = right = NULL;
        data = value ;
    }
  };
  static int idx = -1;
Node* creatingtree(vector<int>preorder){
idx++;
if(preorder[idx]==-1){
    return NULL;
}
Node * root = new Node (preorder[idx]);
 root->left = creatingtree(preorder);
  root->right = creatingtree(preorder);
return root ; 
 } 

 void levelorder(Node*root){
queue<Node*>q;
q.push(root);
q.push(NULL);
while(q.size()>0){
    Node*curr = q.front();
       q.pop();
    if(curr==NULL){
        if(!q.empty()){
 cout<< endl;
 q.push(NULL);
 continue;
        }
        else{
            break;
        }
       
    }
 
    cout << curr->data  << " ";
    if(curr->left!=NULL){
        q.push(curr->left);
    }
       if(curr->right!=NULL){
        q.push(curr->right);
    }
}

}
int height (Node*root){
if(root==NULL){
    return 0;
}

  int leftheight =   height(root->left);
 int rightheight =    height(root->right);
 return    max(leftheight , rightheight)+1; 
}

int countnode(Node*root){
    if(root==NULL){
        return 0;
    }
   int leftcount =  countnode(root->left);
int rightcount =     countnode(root->right);
return leftcount+rightcount+1;
}
int sumnode(Node*root){
    if(root==NULL){
return 0;
    }
   int leftsum  = sumnode(root->left);
  int rightsum     = sumnode(root->right);
  return leftsum+rightsum+root->data ; 
}
int main(){
       vector<int> preorder = {1,2,4,8, -1, -1, 9, -1, -1, 5, 10, -1, -1,-1, 3, 6, -1, -1, 7, -1, -1};

//vector<int>preorder= {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
Node*root =  creatingtree(preorder);
// levelorder(root);
//  cout << height(root);
// cout << countnode(root);
 cout << sumnode(root);
}