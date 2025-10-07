#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
static int idx=-1;
 Node* buildtree(vector<int>preorder){
idx++;
if(preorder[idx]==-1){
    return NULL;
}
Node *root = new Node(preorder[idx]);
root->left =buildtree(preorder);
root->right =buildtree(preorder);
return root ;
 }

 void topview(Node*root){
    queue<pair<Node* , int>>q;
    map<int , int>m;
    q.push({root , 0});  // root ka horizontal dis 0 hi hota h 
while(q.size()>0){
Node*curr=q.front().first;
int hordis=q.front().second;
if(m.find(hordis)==m.end()){
    m[hordis] = curr->data;
}
q.pop();


if(curr->left!=NULL){
    q.push({curr->left , hordis-1});
}
if(curr->right!=NULL){
    q.push({curr->right , hordis+1});
}
}
for(auto it:m){
    cout<<it.second<<" ";
}
 }
int main(){
    vector<int>preorder = {1,2, -1 ,-1,3,4,-1,-1,5 , -1 ,-1};
    Node*root = buildtree(preorder);
   // cout<<root->data <<endl;
    topview(root);
}