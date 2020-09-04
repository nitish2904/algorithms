#include<bits/stdc++.h>
using namespace std;
int m;
struct node{
	int maximum;
	int smaximum;
};

node query(node* tree,int start,int end,int treeNode,int left,int right){
	if(start>right || end<left){
		node ans;
        ans.maximum=INT_MIN;
        ans.smaximum=INT_MIN;
        return ans;
    
    }
	if(start>=left && end <=right)
		return tree[treeNode];
	int mid =(start+end)/2;
	node l = query(tree,start,mid,2*treeNode,left,right);
	node r = query(tree,mid+1,end,2*treeNode+1,left,right);
    node ans;
    ans.maximum=max(l.maximum,r.maximum);
	ans.smaximum=min(max(l.maximum,r.smaximum),max(r.maximum,l.smaximum));

	return ans;
}
void updateTree(int* arr,node* tree,int start,int end,int treeNode,int index,int value){
	if(start==end){
		arr[index]=value;
		tree[treeNode].maximum=value;
		tree[treeNode].smaximum=INT_MIN;
			return;
	}
	int mid=(start+end)/2;
	if(index>mid){
		updateTree(arr,tree,mid+1,end,2*treeNode+1,index,value);
	}
	else{
		updateTree(arr,tree,start,mid,2*treeNode,index,value);
	}
	node left = tree[2*treeNode];
	node right = tree[2*treeNode+1];
	tree[treeNode].maximum=max(left.maximum,right.maximum);
	tree[treeNode].smaximum=min(max(left.maximum,right.smaximum),max(right.maximum,left.smaximum));
	return;
}
void buildtree(int* arr,node* tree,int start,int end,int treeNode){
	if(start==end){
		tree[treeNode].maximum=arr[start];
		tree[treeNode].smaximum=INT_MIN;
		return;
	}
	int mid = (start+end)/2;
	buildtree(arr,tree,start,mid,2*treeNode);
	buildtree(arr,tree,mid+1,end,2*treeNode+1);

	node left = tree[2*treeNode];
	node right = tree[2*treeNode+1];
	tree[treeNode].maximum=max(left.maximum,right.maximum);
	tree[treeNode].smaximum=min(max(left.maximum,right.smaximum),max(right.maximum,left.smaximum));

	return;	
}
int main(){
	int n,q;
    cin>>n;
    int* arr =new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    node* tree = new node[4*n];
    memset(tree,0,sizeof tree);
	buildtree(arr,tree,0,n-1,1);
    cin>>q;
    for(int i=0;i<q;i++){
        int l,r;
        char type;
        cin>>type>>l>>r;
        if(type=='Q'){
            //cin>>l>>r;
            node x=query(tree,0,n-1,1,l-1,r-1);
            cout<<x.maximum+x.smaximum<<endl;
            
        }
        else{
            //cin>>l>>r;
            updateTree(arr,tree,0,n-1,1,l-1,r);
        }
    }
	

}
