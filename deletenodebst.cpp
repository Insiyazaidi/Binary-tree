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

 Node* insert( Node*root , int val){
    if(root==NULL){
        return new Node(val);
    }
if(val<root->data){
   root->left =  insert(root->left , val); // yeh tb ke liye h jb root ka left null nhi h kuch node present h toh vo phir se further root ke left m 
} //  search krta h kbha next root ka left null h taaki h  new root ko insert krsku 
if(val>root->data){
    root->right = insert(root->right , val);
}
return root;  // jb insert hojaiga node toh last m  new root bhejdena kyu ki kuch changes toh hue honge na tree m add hone ke baad 
 }

 Node* buildbst( vector<int>arr){
 Node* root = NULL;
for(int val: arr){
root = insert(root , val);

} 
return root ;
}
 void printinorder( Node* root){
    if(root==NULL){
        return;
    }
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);
}

// Node* getis(Node*root){
  //while( root!=NULL && root->left!=NULL){
  //  root=root->left;
//}
 // return root ;
 // }

 Node* getip(Node*root){
    while(root!=NULL && root->right!=NULL){
        root=root->right;
    }
    return root ; 
 }


Node* deletenode( Node* root , int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data>key){
       root->left  =    deletenode(root->left , key); 
    }
    else if(root->data<key){
        root->right = deletenode(root->right , key );
    }
    else {  // yaani root mil gaiii 
if(root->left ==NULL){
Node*temp = root->right;
delete root ;
return temp;
}
 else if(root->right ==NULL){
Node*temp = root->left;
delete root ;
return temp;
}
else{ 

    Node*IP = getip (root->left);
    root->data= IP->data;
    root->left = deletenode(root->left , IP->data);
//Node* IS = getis(root->right);
//root->data= IS->data;
 //root->right = deletenode(root->right , IS->data);
}
    }

return root;
}

int main(){
   // vector<int>arr ={3,2,1,5,6,4};
   vector<int>arr ={8, 3, 10, 1, 6, 4, 7, 14, 13, 5};
   Node*root =  buildbst(arr);
   cout<<" before deletion"<<endl;
   printinorder(root);
   deletenode(root , 6 );    // BHAIII HM IS AUR IP DONO  M SE  KISI EK KI HELP SE  DELETE KRSKTE H NODE ... 
   cout<<endl;
      cout<<" after  deletion"<<endl;
    printinorder(root);
  
}