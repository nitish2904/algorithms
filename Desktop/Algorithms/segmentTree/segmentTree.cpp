#include<bits/stdc++.h>
using namespace std;

int query(int* tree,int start,int end,int treeNode,int left,int right){
	if(start>right || end<left)
		return 0;
	if(start>=left && end <=right)
		return tree[treeNode];
	int mid =(start+end)/2;
	int ans1 = query(tree,start,mid,2*treeNode,left,right);
	int ans2 = query(tree,mid+1,end,2*treeNode+1,left,right);
	return ans1+ans2;
}


void updateTree(int* arr,int* tree,int start,int end,int treeNode,int index,int value){

	if(start==end){
		arr[index]=value;
		tree[treeNode]=value;
			return;
	}
	int mid=(start+end)/2;
	if(index>mid){
		updateTree(arr,tree,mid+1,end,2*treeNode+1,index,value);
	}
	else{
		updateTree(arr,tree,start,mid,2*treeNode,index,value);
	}
	tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];

}


void buildtree(int* arr,int* tree,int start,int end,int treeNode){
	
	if(start==end){
		tree[treeNode]=arr[start];
		return;
	}
	int mid = (start+end)/2;

	buildtree(arr,tree,start,mid,2*treeNode);
	buildtree(arr,tree,mid+1,end,2*treeNode+1);

	tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];	

}


int main(){
	int arr[]={1,2,3,4,5,6,7,8,9};
	int* tree =  new int[18];
	buildtree(arr,tree,0,8,1);
	
	cout<<query(tree,0,8,1,0,4);

}
