#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};
bool isSameTree(Node* p,Node* q){
	if(p == NULL || q == NULL)
		return (p == q);
	return (p->data == q->data) && isSameTree(p->left,q->left)
	&& isSameTree(p->right,q->right);
}
int main(){
	Node *p, *q;
	isSameTree(p,q);
}