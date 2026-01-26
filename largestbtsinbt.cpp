#include<iostream>
#include<vector>
#include <climits>     // for INT_MIN, INT_MAX
#include <algorithm>
using namespace std;
class Node{
    public:
    int data ;
    Node* left;
    Node*right;
    Node(int value){
    data =  value ;
    left=right=NULL;
    }

};
 class rootinfo{
    public:
    int maxi ;
    int mini;
    int size;
    rootinfo(int maxreceived ,int  minreceived , int sizereceived  ){
          maxi = maxreceived;
          mini= minreceived;
          size= sizereceived;
    }
 };

rootinfo helper(Node* root){  // iska return type rootinfo h jaise usually int ya bool hota h 
if(root==NULL){                     // postorder traversal left, right, root 
   return rootinfo(INT_MIN , INT_MAX , 0);
}
     rootinfo leftka = helper(root->left);
 rootinfo rightka = helper(root->right);
        if(root->data > leftka.maxi && root->data < rightka.mini){
                int currmax =  max(root->data , rightka.maxi);  // right se max value nikalni h 
                int currmin =  min(root->data , leftka.mini);  // left se min value nikal ni h .. 
                int currsize= leftka.size+rightka.size+1;
             return   rootinfo(currmax , currmin , currsize);
        }
        else{  // yaaani vo bst nhi h 
          return  rootinfo(INT_MAX , INT_MIN , max(leftka.size , rightka.size));

        }
}

  int largestbstinbt(Node* root){
    rootinfo information = helper(root);   // its like - int information = helper(root);
     return information.size;
}
int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
     root->left->right= new Node(8);
       root->right->right = new Node(50);
     cout<< largestbstinbt(root);
     cout<< endl;
}