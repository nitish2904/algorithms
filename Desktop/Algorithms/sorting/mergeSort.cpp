#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int left,int mid,int right){
	int i=left,j=mid,k=0;
	int temp[right-left+1];
	while(i<=mid-1 && j<=right){
		if(arr[i]<=arr[j]){
			temp[k++]=arr[i++];
		}
		else{
			temp[k++]=arr[j++];
		}
	}
	while(i<=mid-1){
		temp[k++]=arr[i++];
	}
	while(j<=right){
		temp[k++]=arr[j++];
	}
	k=0;
	for(i=left;i<=right;i++){
		arr[i]=temp[k++];
	}

}
void mergeSort(int arr[],int l,int r){
	if(l<r){
		int m=(l+r)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m+1,r);
	}
}
int main(){
    int arr[10]={9,8,55,2,47,3,7,6,5,9};
    mergeSort(arr,0,9);
    cout<<"After sorting the array : "<<endl;
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}
