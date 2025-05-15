#include<iostream>
using namespace std;
struct Node{
int key;
Node *left;
Node*right;
Node (int item){
	key=item;
	left=NULL;
	right=NULL;
}
};
Node*search(Node*root,int key){
	if (root==NULL || root->key==key)
	return root;
	if (root->key<key)
	return search (root->right,key);
	else
		return search (root->left,key);
}
//creating Bst 
//    50
//   /  \
//  40   70
//  / \   / \
// 20 45  60 80
int main(){
Node*root=new Node (50);
root->left=new Node (40);
root->right=new Node (70);
root->left->left=new Node (20);
root->left->right=new Node (45);
root->right->left=new Node (60);
root->right->right=new Node (80);
(search(root,21)!=NULL) ?cout<<"found\n":cout<<"Not found\n";
(search(root,60)!=NULL) ?cout<<"found\n":cout<<"Not found\n";
return 0;

}