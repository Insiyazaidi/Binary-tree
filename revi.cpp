#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
class Node{
    public:
    int data ;
    Node*left;
    Node*right;
    Node(int value){
        data = value ;
        left = right = NULL;
    }
};
static int idx = -1;
 Node * creatingtree(vector<int>v){
idx++;
if(v[idx]==-1){
    return NULL;
}
Node* root = new Node(v[idx]);
root->left = creatingtree(v);
root->right = creatingtree(v);
return root ; 
}
  void levelorder(Node* root){
queue<Node*>q;
q.push(root);
q.push(NULL);
while(q.size()>0){
    Node*curr = q.front();
    q.pop();
    if(curr==NULL){
        if(!q.empty()){
    q.push(NULL);
    continue;
        }
        else{
            break;
        }
    }
    cout << curr->data<< " " ;
    if(curr->left!=NULL){
        q.push(curr->left);

    }
      if(curr->right!=NULL){
        q.push(curr->right);  
    }
}
}

topview(Node*root){
    queue<pair<int , Node*>>q;
    map<int, Node*>m;
    q.push({0,root});
    while(q.size()>0){
        auto curr = q.front();
        q.pop();
        Node* node = curr.second;
        int hd = curr.first;
        
m[hd] = node ;
if(node->left){
    q.push({hd-1 , node->left});
}
if(node->right){
    q.push({ hd+1 , node->right});
}
    }
    for(auto it:m){
        cout << it.second->data<< " ";
    }
}
  void klevel(Node*root , int k ){
queue<pair<Node* , int>>q;
q.push({root , k});
while(q.size()>0){

 auto curr = q.front();
 q.pop();
  Node* node = curr.first;
 int level = curr.second;
  if(level==1){
cout<<node->data << "  ";
continue;
 }

 if(node->left!=NULL){
    q.push({node->left  , level-1});
 }
 if(node->right!=NULL){
    q.push({node->right  , level-1});
 }
}



}

int main(){
   vector<int> v = {1,2, 4, -1, 7, -1, -1, 5, 8, -1, -1, -1, 3, -1,  6, 9, -1, -1, 10, -1, -1};
   Node*root =  creatingtree(v);
//levelorder(root);
 //topview(root);
 klevel(root , 2);
}