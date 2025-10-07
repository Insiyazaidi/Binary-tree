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
 void kthroot(Node*root , int k){
    if(root==NULL){
            return;
         }
    if(k==1){  
        cout<<root->data;
        return;
         }
         
             kthroot(root->left , k-1);
    kthroot(root->right,k-1);
 }
 int main(){
    vector<int>preorder = {1,2, 7 ,-1 , -1 ,-1,3,4,-1,-1,5,-1,-1};
    Node*root = buildtree(preorder);
kthroot(root ,3);

}
