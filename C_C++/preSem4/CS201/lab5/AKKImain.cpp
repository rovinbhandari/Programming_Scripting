//#include "../include/head.h"
#include <iostream>
using namespace std;

struct tree
{
int data;
tree *left;
tree *right;
};

void insert(tree *a, int x);
void inorder( tree *a);
void postorder( tree *a);
void preorder( tree *a);



int main(){
tree *root= new tree;
tree *pos= new tree;
cout<<"enter root";
int x;
cin>>x;
root->data=x;
root->left=NULL;
root->right=NULL;

cout<<"enter any value to insert except 0";
cin>>x;

while(x!=0){
pos=root;
insert(pos,x);
cout<<"enter value";
cin>>x;
}
pos=root;
inorder(pos);
cout<<"\n";
postorder(pos);
cout<<"\n";
preorder(pos);
cout<<"\n";

return 0;
}


void insert(tree *a, int x){
if(a->data<x)
{
if(a->right==NULL)
{a->right= new tree;
a=a->right;
a->data=x;
}
else{
insert(a->right,x);
}
}
else{
if(a->left==NULL)
{a->left= new tree;
a=a->left;
a->data=x;
}
else{
insert(a->left,x);
}

}
}

void inorder( tree *a){
if(a->left!=NULL){
inorder(a->left);}
cout<<a->data;
if(a->right!=NULL){
inorder(a->right);
}
}

void postorder( tree *a){
if(a->left!=NULL){
postorder(a->left);}

if(a->right!=NULL){
postorder(a->right);
}
cout<<a->data;
}

void preorder( tree *a){
cout<<a->data;
if(a->left!=NULL){
preorder(a->left);}

if(a->right!=NULL){
preorder(a->right);
}}
