#include<iostream>
using namespace std;

struct Node{
    int Data;
    Node* left;
    Node* right;

    Node(int val){
        Data=val;
        left=nullptr;
        right=nullptr;
    }
};

void preorder(Node* root){
    if(root==nullptr) return;
    cout<<root->Data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->Data<<" ";
    inorder(root->right);
}
void postorder(Node* root){
    if(root==nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->Data<<" ";
}

Node* insertnode(Node* root, int val){
if(root==nullptr){
    return new Node(val);
}

if(val<root->Data){
    root->left=insertnode(root->left,val);
}
else{
    root->right=insertnode(root->right,val);
}
return root;
}

int main(){
Node *root=nullptr;
root=insertnode(root,10);
insertnode(root,5);
insertnode(root,15);
insertnode(root,3);
insertnode(root,8);
insertnode(root,12);
insertnode(root,18);

cout<<"Inorder traversal: ";
inorder(root);
cout<<endl;

cout<<"preorder traversal: ";
preorder(root);
cout<<endl;
cout<<"postorder traversal: ";
postorder(root);
cout<<endl;

}
