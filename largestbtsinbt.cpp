#include<iostream>
#include<vector>
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
int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(8);
     root->right->right = new Node(7);
}