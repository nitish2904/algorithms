void heapify(int arr[],int n,int i){
	int largest=i;
	int lchild=2*i+1;
	int rchild=2*i+2;
	//if left child is larger than the root
	if(lchild<n && arr[lchild]>arr[largest]){
		largest=lchild;
	}
	//if rchild is greater
	if(rchild<n && arr[rchild]>arr[largest]){
		largest=rchild;
	}
	//if largest has changed
	if(largest!=i){
		swap(arr[i],arr[largest]);
		heapify(arr,n,largest);
	}
}
//not stable but can be made stable
//complexity nlogn 
//quicksort and merge sort are better in practice so heapsort is not used often
void heapsort(int arr[],int n){
	//bottom up approach to build the array and we do not need to worry about the roots
	for(int i=n/2-1;i>=0;i--){
		heapify(arr,n,i);
	}
	for(int i=n-1;i>=0;i--){
		
		//moving current root(largest element as it is a max heap) to the end 
		swap(arr[0],arr[i]);

		//calling max heapify on the reduced heap reduced because we passed new value of n through i
		heapify(arr,i,0);
	}
}