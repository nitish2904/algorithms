#include<bits/stdc++.h>
using namespace std;

struct Node {
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
void inorder(Node* root){
	if(root==NULL)
		return;
	stack<Node*>st;
	Node* curr = root;
	while(curr != NULL || !st.empty()){
		//first go left as possible then start from there
		while(curr != NULL){
			st.push(curr);
			curr = curr->left;
		}
		curr = st.top();
		st.pop();
		cout<< curr -> data <<" ";
		curr = curr->right;

	}
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
	inorder(root);
}