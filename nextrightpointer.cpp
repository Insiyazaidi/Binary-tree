queue<Node*>q;
q.push(root);
q.push(NULL);
Node* prev=NULL;
while(q.size()>0){
    if(root==NULL || root->left==NULL){  // base case -- agr root null haai ya phir us root ka left null h toh right bhi null hoga as it is 
        // complete bst h to left aur right exist krege dono saath m vrna nhi krege ...  
        // agr ismai se ek bhi condition true hui toh hme as such kuch nhi krna simply root return krdo 
        return root;
    }
    Node* curr = q.front();
    q.pop();
    if(curr==NULL){
if(q.size()==0){  // yaani queue khmt 
break;
}
else{
    q.push(NULL);  // agr size abhi 0 nhi h toh mtlb abhi elements h aur yeh bs level change hua h toh phir se null push krdege next level ko show krne ke liye 
}
    }
    else{
  if(curr->left!=NULL){
        q.push(curr->left);
    }
      if(curr->right!=NULL){
        q.push(curr->right);
    }
     if(prev!=NULL){
        prev->next=curr;
    }
    }
  
    prev=curr;  // yeh toh hm chahte hi h agr curr null ho tb bhi aur na ho tb bhi ... 
    return root ;
} 