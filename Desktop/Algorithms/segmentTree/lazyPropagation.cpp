#include<bits/stdc++.h>
using namespace std;
void buildTree(int* arr,int* tree,int start,int end,int treeNode){
	if(start==end){
		tree[treeNode]=arr[start];
		return;
	}

	int mid = (start+end)/2;
	buildTree(arr,tree,start,mid,2*treeNode);
	buildTree(arr,tree,mid+1,end,2*treeNode+1);

	tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
	return;
}
void updateSegmentTreeLazy(int* tree,int* Lazy,int low,int high,int startR,int endR,int currPos,int inc){
	if(low>high)
		return;
	if(Lazy[currPos]!=0){
		tree[currPos]+=Lazy[currPos];

		if(low!=high){
			Lazy[2*currPos] += Lazy[currPos];
			Lazy[2*currPos+1] += Lazy[currPos];
		}
		Lazy[currPos]=0;
	}
	//No Overlap
	if(startR > high || endR < low)
		return;

	if(startR<=low && high<=endR){
		tree[currPos] += inc;
		if(low!=high){
			Lazy[2*currPos] += inc;
			Lazy[2*currPos+1]+= inc;
		}
		return;
	}
	//partial Overlap
	int mid = (start+end)/2;
	updateSegmentTreeLazy(tree,Lazy,low,mid,startR,endR,2*currPos,inc);
	updateSegmentTreeLazy(tree,Lazy,mid+1,high,startR,endR,2*currPos+1,inc);

	tree[currPos] = min(tree[2*currPos],tree[2*currPos+1]);
	return;
}
int main(){

}