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

bool isBalanced(Node* root){
	return height(root) != -1;
}

int height(Node* root){
	if(root == NULL) return 0;

	int leftHeight = height(root->left);
	if(leftHeight == -1) return -1;
	
	int rightHeight = height(root->right);
	if(rightHeight == -1) return -1;
	
	if(abs(leftHeight - rightHeight) > 1) return -1;

	return max(leftHeight,rightHeight) + 1;
}