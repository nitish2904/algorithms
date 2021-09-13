#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val){
		data =val;
		left = NULL;
		right = NULL;
	}
};
void vericalTraversal(Node* root){
	map<int,vector<int>>mp;
	queue<pair<Node* ,int>>q;
	q.push({root,0});
	while(!q.empty()){
		auto p =q.front();
		Node* curr = p.first;
		int hd = p.second;
		mp[hd].push_back(curr->key);
		q.pop();
		if(curr->left) q.push({curr->left,hd-1});
		if(curr->right) q.push({curr->right,hd+1});
	}
	for(auto x:mp){
		for(int y:x.second)
			cout<<y<<" ";
		cout<<endl;
	}
}