#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};
//preorder root left right
//inorder left root right
//postorder left right root

void postorder(Node* root){
	if(root == NULL) return;
	stack<Node* > st1,st2;
	st1.push(root);
	while(!st1.empty()){
		root = st1.top();
		st1.pop();
		st2.push(root);
		if(root->left != NULL){
			st1.push(root->left);
		}
		if(root->right)
			st1.push(root->right);
	}
	while(!st2.empty()){
		cout<<st2.top()->data<<" ";
		st2.pop();
	}
	cout<<endl;
	return;

}

int main(){
//creating a binary tree
	struct Node *root = new Node(1);
	root -> left = new Node(2);
	root -> right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	/* tree
               1
            /     \
           2       3
          / \     / \
         4   5   6   7
        / \
     NULL NULL
    */
	postorder(root);
}
