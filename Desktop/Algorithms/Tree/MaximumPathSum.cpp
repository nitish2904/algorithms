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
int maxPathSum(Node* root, int &maxSum){
	if(node == NULL) return 0;
	int left = maxPathSum(root->left,maxSum);
	int right = maxPathSum(root->right,maxSum);
	maxSum = max(maxSum,left+right+root->data);
	return max(left,right)+root->data;
}

int main(){
	int maxSum = INT_MIN;
	Node* root;//make your tree here
	maxPathSum(root,maxSum);
	cout<<maxSum<<endl;
}